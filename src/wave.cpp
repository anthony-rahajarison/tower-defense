#include "wave.hpp"
#include <iostream>

void Wave::createWavefromlevel(){

};

bool Wave::waveEnded(){
    if (this-> totalEnemies == 0){
        this-> isover = true;
    }
    return this-> isover;
}

Wave::Wave(int lvl){
    this->totalEnemies = 3 * lvl;
}