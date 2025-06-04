#ifndef WAVE_HPP
#define WAVE_HPP

class Wave{
    public:
        int n_enemy = 5;
        int level = 0;
        bool isover = false;


    bool waveEnded();
    void createWavefromlevel();
};
#endif
