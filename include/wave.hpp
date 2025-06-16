
#ifndef WAVE_HPP
#define WAVE_HPP

class Wave{
    public:
        int totalEnemies = 5;
        int level = 0;
        bool isover = false;


    bool waveEnded();
    void createWavefromlevel();
    Wave(int lvl);
};
#endif
