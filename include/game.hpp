#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "wave.hpp"
#include "tower.hpp"

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
        bool gameOver = false;
        int currentWaves = 1 ;
        Game(sf::RenderWindow& win);
        AppState run();
        void initGame();
        void initPath();
        bool launchWave();
        void handleInput(const sf::Event& event);
        void drawTowers();

        Tower towerA = Tower(600, 500);
        Tower towerB = Tower(600, 50);
        Tower towerC = Tower(425, 180);
        Tower towerD = Tower(370, 550);
        Tower towerE = Tower(100, 390);
        Tower towerF = Tower(120, 150);


    private:
        sf::RenderWindow& window;
        sf::Font MyFont;
        sf::Text CreditText;
        sf::Event event;
        std::vector<sf::Vector2f> pathPoints;
        sf::Texture backgroundTexture , buttonWaveTexture;
        sf::Sprite buttonWave, background;

};
#endif