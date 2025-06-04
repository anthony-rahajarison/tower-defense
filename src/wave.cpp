#include "wave.hpp"
#include <iostream>

void Wave::createWavefromlevel(){
    
};

bool Wave::waveEnded(){
    if (this-> n_enemy == 0){
        this-> isover = true;
    }
    return this-> isover;
}