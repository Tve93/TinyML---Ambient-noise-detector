#include "Particle.h"
#include "Microphone_PDM.h"
#include "speech_noise_model_wrapper.h"
#include "speaker.h"
#include "features.h"

#include <cstring>
#include <cstdint>
#include <cmath>
#include <climits>

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

// Audio/frame configuration
constexpr int SAMPLE_RATE = 16000;
// DMA chunk size on RTL872x is 256 samples. We'll accumulate 2 chunks to make a 512-sample window
constexpr size_t FRAME_SAMPLES_PER_CHUNK = 256;
constexpr size_t FRAME_CHUNKS_PER_WINDOW = 2;
constexpr size_t FRAME_QUEUE_DEPTH = 8; // keep more small chunks

static int16_t g_frameQueue[FRAME_QUEUE_DEPTH][FRAME_SAMPLES_PER_CHUNK];
static volatile uint8_t g_frameWrite = 0;
static volatile uint8_t g_frameRead = 0;
static volatile uint8_t g_frameCount = 0;
static volatile uint32_t g_droppedFrames = 0;

// Button integration
#ifndef WHITE_NOISE_BUTTON_PIN
#define WHITE_NOISE_BUTTON_PIN D2
#endif

// White-noise playback duration
static const unsigned long WHITE_NOISE_TRIGGER_MS = 5UL * 60UL * 1000UL; // 5 minutes

// Button press flag (set in ISR), debounced in the main loop
static volatile bool g_button_pressed = false;
static unsigned long g_last_button_ms = 0;
static const unsigned long BUTTON_DEBOUNCE_MS = 200;
// When true we ignore further ISR events until the physical button is released
static volatile bool g_button_wait_release = false;

// Simple button ISR
void button_isr()
{
    if (!g_button_wait_release)
    {
        g_button_pressed = true;
    }
}

// Smoothing / debounce state
static float g_probEma = 0.0f;
static const float EMA_ALPHA = 0.15f; // smoother EMA
static int g_stateCounter = 0;        // positive -> towards speech, negative -> towards noise
// Detection tuning
static const float PROB_THRESHOLD = 0.60f;    // require higher prob
static const int STATE_COUNTER_THRESHOLD = 2; // require 2-step debounce
static const float ENERGY_THRESHOLD = 100.0f; // raw RMS minimum to consider speech

// Very small helper to push a frame into the ring buffer from the audio callback
static void push_frame_from_callback(const int16_t *samples, size_t n)
{
    if (n > FRAME_SAMPLES_PER_CHUNK)
        n = FRAME_SAMPLES_PER_CHUNK;

    noInterrupts();
    if (g_frameCount < FRAME_QUEUE_DEPTH)
    {
        // copy samples into queue
        memcpy(g_frameQueue[g_frameWrite], samples, n * sizeof(int16_t));
        // zero any remaining if n < FRAME_SAMPLES_PER_CHUNK
        if (n < FRAME_SAMPLES_PER_CHUNK)
        {
            memset(&g_frameQueue[g_frameWrite][n], 0, (FRAME_SAMPLES_PER_CHUNK - n) * sizeof(int16_t));
        }
        g_frameWrite = (g_frameWrite + 1) % FRAME_QUEUE_DEPTH;
        ++g_frameCount;
    }
    else
    {
        ++g_droppedFrames;
    }
    interrupts();
}

void setup()
{
    Serial.begin(115200);
    waitFor(Serial.isConnected, 3000);

    Log.info("Starting classifier pipeline...");

    int err = Microphone_PDM::instance()
                  .withOutputSize(Microphone_PDM::OutputSize::SIGNED_16)
                  .withRange(Microphone_PDM::Range::RANGE_2048)
                  .withSampleRate(SAMPLE_RATE)
                  .init();

    if (err)
    {
        Log.error("PDM init err=%d", err);
    }

    // quick callback: copy DMA buffer into our ring buffer and return
    Microphone_PDM::instance().noCopySamples([](void *pSamples, size_t numSamples)
                                             {
        const int16_t *samples = reinterpret_cast<const int16_t *>(pSamples);
        push_frame_from_callback(samples, numSamples); });

    err = Microphone_PDM::instance().start();
    if (err)
    {
        Log.error("PDM start err=%d", err);
    }
    // Initialize speaker and configure white-noise button
    speaker_init();
    pinMode(WHITE_NOISE_BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(WHITE_NOISE_BUTTON_PIN, button_isr, FALLING);
}

void loop()
{
    // let the library process interrupts and internal state
    Microphone_PDM::instance().loop();

    // Process one frame from queue if available
    // Need FRAME_CHUNKS_PER_WINDOW chunks to form one window
    if (g_frameCount >= FRAME_CHUNKS_PER_WINDOW)
    {
        // pop FRAME_CHUNKS_PER_WINDOW indices
        int indices[FRAME_CHUNKS_PER_WINDOW];
        noInterrupts();
        for (size_t i = 0; i < FRAME_CHUNKS_PER_WINDOW; ++i)
        {
            indices[i] = g_frameRead;
            g_frameRead = (g_frameRead + 1) % FRAME_QUEUE_DEPTH;
            --g_frameCount;
        }
        interrupts();

        // Build window samples by concatenating chunks in order
        int16_t window_samples[WINDOW_SIZE];
        for (size_t c = 0; c < FRAME_CHUNKS_PER_WINDOW; ++c)
        {
            memcpy(&window_samples[c * FRAME_SAMPLES_PER_CHUNK], g_frameQueue[indices[c]], FRAME_SAMPLES_PER_CHUNK * sizeof(int16_t));
        }

        // Compute RMS for energy gating (keep lightweight)
        int64_t raw_sumsq = 0;
        for (size_t i = 0; i < WINDOW_SIZE; ++i)
        {
            int16_t s = window_samples[i];
            raw_sumsq += (int64_t)s * s;
        }
        double raw_rms = sqrt((double)raw_sumsq / (double)WINDOW_SIZE);

        // skip model while speaker playback is active
        if (!speaker_is_playing())
        {
            int16_t features[NUM_FEATURES];
            compute_time_features(window_samples, features);

            // Call model (get class and probabilities)
            float probs[2] = {0.0f, 0.0f};
            int32_t cls = speech_noise_model_predict(features, (int32_t)NUM_FEATURES);
            // try to get probabilities when available
            (void)speech_noise_model_predict_proba(features, (int32_t)NUM_FEATURES, probs, 2);

            // update EMA of speech probability (class 1)
            g_probEma = (1.0f - EMA_ALPHA) * g_probEma + EMA_ALPHA * probs[1];

            // debounce via state counter
            if (g_probEma > PROB_THRESHOLD)
            {
                if (g_stateCounter < STATE_COUNTER_THRESHOLD)
                    ++g_stateCounter;
            }
            else
            {
                if (g_stateCounter > -STATE_COUNTER_THRESHOLD)
                    --g_stateCounter;
            }
            // require both debounced probability and sufficient energy
            int reported = (g_stateCounter >= STATE_COUNTER_THRESHOLD && raw_rms > ENERGY_THRESHOLD) ? 1 : 0;

            // React to detected speech windows
            uint32_t now = millis();
            if (reported == 1)
            {
                // Start white-noise
                start_white_noise(WHITE_NOISE_TRIGGER_MS);
                Log.info("Speech detected prob=%.2f (white-noise started)", g_probEma);
            }
        }
    }

    // If callbacks aren't firing, poll samplesAvailable() and copy samples directly
    if (Microphone_PDM::instance().samplesAvailable())
    {
        size_t n = Microphone_PDM::instance().getNumberOfSamples();
        if (n > FRAME_SAMPLES_PER_CHUNK)
            n = FRAME_SAMPLES_PER_CHUNK;
        static int16_t tmp[FRAME_SAMPLES_PER_CHUNK];
        bool ok = Microphone_PDM::instance().copySamples((void *)tmp);
        if (ok)
        {
            push_frame_from_callback(tmp, n);
        }
        else
        {
            Log.warn("copySamples failed");
        }
    }

    // white-noise starts (from any source) and off when it stops.
    static bool prev_speaker_playing = false;
    bool now_playing = speaker_is_playing();
    if (now_playing && !prev_speaker_playing)
    {
        // started
        Log.info("speaker: playback started");
    }
    else if (!now_playing && prev_speaker_playing)
    {
        // stopped
        Log.info("speaker: playback stopped");
    }
    prev_speaker_playing = now_playing;

    // Handle external button press (debounced). ISR only sets flag.
    if (g_button_pressed)
    {
        // clear ISR flag immediately
        g_button_pressed = false;

        unsigned long now = millis();
        if (now - g_last_button_ms >= BUTTON_DEBOUNCE_MS)
        {
            g_last_button_ms = now;
            // process the toggle and then require a full release before
            // accepting further presses
                if (speaker_is_playing())
                {
                    speaker_stop();
                    Log.info("button: stop requested");
                }
            else
            {
                start_white_noise(WHITE_NOISE_TRIGGER_MS);                 
                Log.info("button: start requested");
            }
            // require release before next press
            g_button_wait_release = true;
        }
    }

    // Clear the wait-for-release flag when the button is physically released
    if (g_button_wait_release && digitalRead(WHITE_NOISE_BUTTON_PIN) == HIGH)
    {
        g_button_wait_release = false;
    }

    // Cooperative speaker poll: emit pending audio samples without blocking
    speaker_poll();
    delay(5);
}
