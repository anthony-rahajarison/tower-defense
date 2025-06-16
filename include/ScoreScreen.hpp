#pragma once
#include <SFML/Graphics.hpp>

enum class AppState;

class scoreScreen {
    private:
        sf::RenderWindow& window;
        sf::Texture backgroundTexture, buttonquitTexture;
        sf::Sprite background, buttonquit;
        sf::Event event;
        
        void render();
        AppState handleEvents();

    public:
        scoreScreen(sf::RenderWindow& win);
        AppState run();


};