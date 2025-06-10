#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "game.hpp"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& win) : window(win) {
    if (!backgroundTexture.loadFromFile("assets/maps/map1.png")) {
        std::cerr << "Erreur de chargement de la texture de fond" << std::endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(800.0f / background.getLocalBounds().width, 800.0f / background.getLocalBounds().height);

    if (!buttonWaveTexture.loadFromFile("./assets/buttons/lauch_wave.png")) {
        std::cerr << "Erreur de chargement du bouton wave" << std::endl;
    }
    buttonWave.setTexture(buttonWaveTexture);
    buttonWave.setScale(150.0f / buttonWave.getLocalBounds().width, 150.0f / buttonWave.getLocalBounds().height);
    buttonWave.setPosition(350,0);

    initGame();
}

AppState Game::run() {

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.draw(buttonWave);
        window.display();
        handleInput(event);
    }

    return AppState::MainMenu;
}

void Game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(
                {event.mouseButton.x, event.mouseButton.y});
                
            if (buttonWave.getGlobalBounds().contains(mousePos)) {
                launchWave();
            }
        }
    }
}

void Game::initGame() {

    int remainingLives = 3;
    int credit = 0;

    initPath();
}


void Game::initPath() {
    pathPoints = {
        sf::Vector2f(0, 200),
        sf::Vector2f(200, 200),
        sf::Vector2f(200, 400),
        sf::Vector2f(600, 400),
        sf::Vector2f(600, 200),
        sf::Vector2f(800, 200)
    };
}


AppState Game::launchWave() {
    std::cout << "Lancement de la vague !" << std::endl;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.display();
    }
}
