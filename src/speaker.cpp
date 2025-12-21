#include "speaker.h"

#ifndef SPEAKER_PIN
#define SPEAKER_PIN D0
#endif

#ifndef ANALOG_WRITE_MAX_VALUE
#define ANALOG_WRITE_MAX_VALUE 255
#endif

#ifndef VOLUME_PERCENT
#define VOLUME_PERCENT 25
#endif

#ifndef MA_FILTER_LEN
#define MA_FILTER_LEN 12
#endif

#ifndef SAMPLE_RATE_HZ
#define SAMPLE_RATE_HZ 8000
#endif

static volatile int s_playing = 0;
static volatile unsigned long s_samplesEmitted = 0;
static volatile unsigned long s_requested_end = 0;
static unsigned long s_last_tick_us = 0;

static uint32_t s_rnd_state = 0x12345678u;
static inline uint32_t s_xorshift32(void) {
    uint32_t x = s_rnd_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    s_rnd_state = x;
    return x;
}

static void speaker_audio_tick() {
    uint8_t r = (uint8_t)(s_xorshift32() & 0xFFu);
    uint32_t target = ((uint32_t)r * (uint32_t)ANALOG_WRITE_MAX_VALUE * (uint32_t)VOLUME_PERCENT) / (255u * 100u);

    static uint32_t buf[MA_FILTER_LEN];
    static uint32_t sum = 0;
    static unsigned int idx = 0;
    sum -= buf[idx];
    buf[idx] = target;
    sum += buf[idx];
    idx = (idx + 1) % MA_FILTER_LEN;
    uint32_t avg = sum / MA_FILTER_LEN;

    analogWrite(SPEAKER_PIN, (int)avg);
    s_samplesEmitted++;
}

static void speaker_tone_ms(int pin, unsigned int freqHz, unsigned long durationMs) {
    if (freqHz == 0 || durationMs == 0) return;
    unsigned long end = millis() + durationMs;
    unsigned int periodUs = 1000000u / freqHz;
    while (millis() < end) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(periodUs / 2);
        digitalWrite(pin, LOW);
        delayMicroseconds(periodUs / 2);
    }
}

void speaker_init() {
    pinMode(SPEAKER_PIN, OUTPUT);
    analogWrite(SPEAKER_PIN, 0);
    pinMode(D7, OUTPUT);
    digitalWrite(D7, LOW);
}

void start_white_noise(unsigned long durationMs) {
    unsigned long now = millis();
    unsigned long new_end = now + durationMs;
    // Extend requested end if already playing
    if (s_playing) {
        if (new_end > s_requested_end) s_requested_end = new_end;
        return;
    }

    // Start playback and return immediately. speaker_poll() will emit samples.
    s_playing = 1;
    s_samplesEmitted = 0;
    s_requested_end = new_end;
    s_last_tick_us = micros();
    digitalWrite(D7, HIGH);
    Log.info("speaker: white-noise started until %lu (ms)", s_requested_end);
}

void start_beeping(unsigned long durationMs) {
    if (s_playing) return;
    s_playing = 1;
    s_samplesEmitted = 0;
    // Simple blocking beeper retained for short tests
    const unsigned int beepFreqHz = 1000;
    const unsigned int beepMs = 200;
    const unsigned int gapMs = 300;

    digitalWrite(D7, HIGH);
    unsigned long end = millis() + durationMs;
    Log.info("speaker: beep-run started: %lu ms total (beep %ums / gap %ums)", durationMs, beepMs, gapMs);
    while (millis() < end) {
        speaker_tone_ms(SPEAKER_PIN, beepFreqHz, beepMs);
        s_samplesEmitted++;
        if (millis() + gapMs >= end) break;
        delay(gapMs);
    }
    analogWrite(SPEAKER_PIN, 0);
    s_playing = 0;
    digitalWrite(D7, LOW);
    Log.info("speaker: beep-run finished, beeps=%lu", s_samplesEmitted);
}

void speaker_stop() {
    analogWrite(SPEAKER_PIN, 0);
    s_playing = 0;
    s_requested_end = 0;
    digitalWrite(D7, LOW);
}

bool speaker_is_playing() {
    return s_playing != 0;
}

void speaker_poll() {
    if (!s_playing) return;
    unsigned long now_us = micros();
    unsigned long delta_us = now_us - s_last_tick_us;
    if (delta_us == 0) return;
    // number of samples to emit based on elapsed microseconds
    unsigned long samples_due = (delta_us * (unsigned long)SAMPLE_RATE_HZ) / 1000000u;
    if (samples_due == 0) return;
    // Cap to avoid long loops if polls are infrequent
    if (samples_due > 1024) samples_due = 1024;
    for (unsigned long i = 0; i < samples_due; ++i) {
        speaker_audio_tick();
    }
    s_last_tick_us = now_us;

    // Stop if reached requested end
    if (millis() >= s_requested_end) {
        analogWrite(SPEAKER_PIN, 0);
        s_playing = 0;
        s_requested_end = 0;
        digitalWrite(D7, LOW);
        Log.info("speaker: white-noise finished samples=%lu", s_samplesEmitted);
    }
}
