#pragma once
#include "Particle.h"

void speaker_init();

void start_white_noise(unsigned long durationMs);

void start_beeping(unsigned long durationMs);

void speaker_stop();

bool speaker_is_playing();

// Cooperative poll function that should be called frequently from the main
// loop to allow non-blocking audio playback. Emits as many samples as are
// due based on elapsed time since the last poll.
void speaker_poll();
