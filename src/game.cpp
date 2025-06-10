#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow& win) : window(win) {
    std::cout << "Initialisation du jeu" << std::endl;
}

AppState Game::run() {
    sf::Event event;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/maps/map1.png")) {
        std::cerr << "Erreur : impossible de charger assets/maps/map1.png" << std::endl;
        return AppState::MainMenu;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);


    sf::Vector2u windowSize = window.getSize();
    sf::FloatRect spriteSize = backgroundSprite.getLocalBounds();
    backgroundSprite.setScale(800.0f / backgroundSprite.getLocalBounds().width, 1000.0f / backgroundSprite.getLocalBounds().height);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                return AppState::MainMenu;
        }

        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }

    return AppState::MainMenu;
}
