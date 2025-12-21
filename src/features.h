#pragma once
#include <cstddef>
#include <cstdint>

// Window and feature sizes (match firmware/trainer)
constexpr std::size_t WINDOW_SIZE = 512;
constexpr std::size_t NUM_FEATURES = 6;

// Feature scaling constants (must match `forest.py`)
constexpr float SCALE_MEAN = 128.0f; // mean * 128 -> int
constexpr float SCALE_RMS = 64.0f;   // rms * 64 -> int
constexpr float SCALE_MINMAX = 1.0f; // min/max kept as raw int16 values
constexpr float SCALE_ZCR = 1000.0f; // zcr * 1000
constexpr float SCALE_PTP = 1.0f;    // peak-to-peak kept as raw int16 difference

// Quick, lightweight feature extraction (packs into int16_t)
// Using simple time-domain features; no extra buffers needed
// Compute simple time-domain features over WINDOW_SIZE samples and scale to int16
void compute_time_features(const int16_t *window_samples, int16_t *out_features);

// Lightweight helper to compute raw RMS (double) over n samples
double compute_raw_rms(const int16_t *window_samples, std::size_t n);
