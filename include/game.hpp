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
        void initGame();
        void initPath();
        AppState launchWave();
        void handleInput(const sf::Event& event);


    private:

        sf::RenderWindow& window;
        sf::Event event;
        std::vector<sf::Vector2f> pathPoints;
        sf::Texture backgroundTexture , buttonWaveTexture;
        sf::Sprite buttonWave, background;



};
#endif