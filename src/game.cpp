#include "game.hpp"
#include <iostream>
#include <cmath>



Game::Game(sf::RenderWindow& win) : window(win) {
    //Map
    if (!backgroundTexture.loadFromFile("assets/maps/map1.png")) {
        std::cerr << "Erreur de chargement de la texture de fond" << std::endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(800.0f / background.getLocalBounds().width, 800.0f / background.getLocalBounds().height);

    //Next Wave button
    if (!buttonWaveTexture.loadFromFile("./assets/buttons/lauch_wave.png")) {
        std::cerr << "Erreur de chargement du bouton wave" << std::endl;
    }
    buttonWave.setTexture(buttonWaveTexture);
    buttonWave.setScale(150.0f / buttonWave.getLocalBounds().width, 150.0f / buttonWave.getLocalBounds().height);
    buttonWave.setPosition(350,0);

    if (!MyFont.loadFromFile("./assets/font/MedievalSharp-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police" << std::endl;
    }

    Player player = Player();
    
    //Credit Text
    CreditText.setFont(MyFont); 
    CreditText.setCharacterSize(40);
    CreditText.setPosition(550,0);
    CreditText.setFillColor(sf::Color::White);

    initGame();
}

AppState Game::run() {
    
    //tower0
    if (!tower0Texture.loadFromFile("./assets/tower/tower0.png")) {
        std::cerr << "Erreur de chargement de tower0"<< std::endl;
    }

    if (!tower1Texture.loadFromFile("./assets/tower/tower1.png")) {
        std::cerr << "Erreur de chargement de tower1"<< std::endl;
    }

    if (!tower2Texture.loadFromFile("./assets/tower/tower2.png")) {
        std::cerr << "Erreur de chargement de tower2"<< std::endl;
    }

    towerA.texture = tower0Texture;
    towerB.texture = tower0Texture;
    towerC.texture = tower0Texture;
    towerD.texture = tower0Texture;
    towerE.texture = tower0Texture;
    towerF.texture = tower0Texture;
    

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleInput(event);
        }
        window.clear();
        CreditText.setString("Credits : " + std::to_string(player.returnCredit()));
        window.draw(background);
        window.draw(CreditText);
        drawTowers();
        window.draw(buttonWave);
        window.display();
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
            if (towerA.sprite.getGlobalBounds().contains(mousePos)){
                towerA.upgrade();
                std::cout << "UPGRADE";
                towerA.texture = tower1Texture;
            }
            if (towerB.sprite.getGlobalBounds().contains(mousePos)){
                towerB.upgrade();
                std::cout << "UPGRADE";
                towerB.texture = tower1Texture;
            }
            if (towerC.sprite.getGlobalBounds().contains(mousePos)){
                towerC.upgrade();
                std::cout << "UPGRADE";
                towerC.texture = tower1Texture;
            }
            if (towerD.sprite.getGlobalBounds().contains(mousePos)){
                towerD.upgrade();
                std::cout << "UPGRADE";
                towerD.texture = tower1Texture;
            }
            if (towerE.sprite.getGlobalBounds().contains(mousePos)){
                towerE.upgrade();
                std::cout << "UPGRADE";
                towerE.texture = tower1Texture;
            }
            if (towerF.sprite.getGlobalBounds().contains(mousePos)){
                towerF.upgrade();
                std::cout << "UPGRADE";
                towerF.texture = tower1Texture;
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


void Game::launchWave() {
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

void Game::drawTowers(){
    towerA.drawTower(window);
    towerB.drawTower(window);
    towerC.drawTower(window);
    towerD.drawTower(window);
    towerE.drawTower(window);
    towerF.drawTower(window);
}