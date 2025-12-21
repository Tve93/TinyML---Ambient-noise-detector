#include "features.h"
#include <cmath>
#include <climits>
#include <cstdint>

// scale and saturate into int16 helper
static inline int16_t sat_to_int16(float v) {
    if (v > 32767.0f) return 32767;
    if (v < -32768.0f) return -32768;
    return (int16_t)lrintf(v);
}

void compute_time_features(const int16_t *window_samples, int16_t *out_features) {
    long long sum = 0;
    long long sumsq = 0;
    int16_t min_v = INT16_MAX;
    int16_t max_v = INT16_MIN;
    int zero_cross = 0;
    for (std::size_t i = 0; i < WINDOW_SIZE; ++i) {
        int16_t s = window_samples[i];
        sum += s;
        sumsq += (long long)s * s;
        if (s < min_v) min_v = s;
        if (s > max_v) max_v = s;
        if (i > 0) {
            int16_t prev = window_samples[i - 1];
            if ((s >= 0 && prev < 0) || (s < 0 && prev >= 0)) ++zero_cross;
        }
    }
    float mean = (float)sum / (float)WINDOW_SIZE;
    float rms = sqrtf((float)sumsq / (float)WINDOW_SIZE);
    float zcr = (float)zero_cross / (float)(WINDOW_SIZE - 1);
    float ptp = (float)(max_v - min_v);

    out_features[0] = sat_to_int16(mean * SCALE_MEAN);
    out_features[1] = sat_to_int16(rms * SCALE_RMS);
    out_features[2] = sat_to_int16((float)min_v * SCALE_MINMAX);
    out_features[3] = sat_to_int16((float)max_v * SCALE_MINMAX);
    out_features[4] = sat_to_int16(zcr * SCALE_ZCR);
    out_features[5] = sat_to_int16(ptp * SCALE_PTP);
}

double compute_raw_rms(const int16_t *window_samples, std::size_t n) {
    unsigned long long sumsq = 0ull;
    for (std::size_t i = 0; i < n; ++i) {
        int16_t s = window_samples[i];
        sumsq += (unsigned long long)((long long)s * s);
    }
    return sqrt((double)sumsq / (double)n);
}




