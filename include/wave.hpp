#ifndef WAVE_HPP
#define WAVE_HPP

class Wave {
    public:
        int waveLevel = 1;
        int n_enemy = 5;
        float spawnDelay = 0.5f;

        void nextWave();
        void reset();
};

#endif
