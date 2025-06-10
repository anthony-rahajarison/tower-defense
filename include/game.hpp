#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "map.hpp"
#include "Wave.hpp"


enum class AppState {
    MainMenu,
    InGame,
    ScoreScreen,
    Exit
};


class Game {
    public:
        Player player;
        Wave wave;
        int currentWaves = 1 ;
        Game(sf::RenderWindow& win);
        AppState run();

    private:
        sf::RenderWindow& window;


};
#endif