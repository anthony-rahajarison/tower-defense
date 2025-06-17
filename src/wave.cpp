#include "wave.hpp"
#include <iostream>

// New wave creation based on level
void Wave::nextWave() {
    waveLevel++;
    n_enemy = 10 + (waveLevel - 1) * 5;

    // Reduce spawn delay for each 5th wave
    if (waveLevel % 5 == 0 && spawnDelay > 0.15f) {
        spawnDelay -= 0.1f;
        if (spawnDelay < 0.15f) spawnDelay = 0.15f;
    }
}

// Reset wave to initial state
void Wave::reset() {
    waveLevel = 1;
    n_enemy = 5;
    spawnDelay = 0.5f;
}