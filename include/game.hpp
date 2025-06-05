#include "Player.hpp"
#include "map.hpp"
#include "Wave.hpp"
#ifndef GAME_HPP
#define GAME_HPP

class Game {
    public:
    Player player;
    MAP map;
    Wave wave;
    int currentWaves = 1 ;


}
#endif