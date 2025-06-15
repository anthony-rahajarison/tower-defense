#include "game.hpp"
#include <iostream>
#include <cmath>



Game::Game(sf::RenderWindow& win) : window(win) {
    Player player = Player();

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
    
    //Credit Text
    CreditText.setFont(MyFont); 
    CreditText.setCharacterSize(40);
    CreditText.setPosition(550,0);
    CreditText.setFillColor(sf::Color::White);

    initGame();
}

AppState Game::run() {
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
            sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                
            if (buttonWave.getGlobalBounds().contains(mousePos)) {
                launchWave();
            }
            else if (towerA.sprite.getGlobalBounds().contains(mousePos)){
                towerA.upgrade(&player);
            }
            else if (towerB.sprite.getGlobalBounds().contains(mousePos)){
                towerB.upgrade(&player);
            }
            else if (towerC.sprite.getGlobalBounds().contains(mousePos)){
                towerC.upgrade(&player);
            }
            else if (towerD.sprite.getGlobalBounds().contains(mousePos)){
                towerD.upgrade(&player);
            }
            else if (towerE.sprite.getGlobalBounds().contains(mousePos)){
                towerE.upgrade(&player);
            }
            else if (towerF.sprite.getGlobalBounds().contains(mousePos)){
                towerF.upgrade(&player);
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
        {700, 700},
        {700, 500},
        {500, 500},
        {500, 200},
        {600, 200},
        {600, 300},
        {700, 300},
        {700, 70}, 
        {350, 70},
        {350, 555},
        {40, 555},
        {40, 300},
        {100, 300},
        {100, 400},
        {200, 400},
        {200, 150},
        {40, 150},
        {40, 0}
    };
}


void Game::launchWave() {
    std::cout << "Lancement de la vague !" << std::endl;

    const int totalEnemies = 3;
    const float spawnDelay = 0.5f;

    std::vector<Enemy> enemies;
    sf::Clock spawnClock;
    size_t spawnedEnemies = 0;

    sf::Clock frameClock;
    
    while (window.isOpen()) {
        float deltaTime = frameClock.restart().asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Create a new enemy
        if (spawnedEnemies < totalEnemies && spawnClock.getElapsedTime().asSeconds() >= spawnDelay) {
            Enemy e;
            e.setPosition(pathPoints[0]);
            enemies.push_back(e);
            spawnedEnemies++;
            spawnClock.restart();
        }

        // Change enemies position
        for (auto& enemy : enemies) {
            enemy.followPath(pathPoints, deltaTime);
        }

        
        // Display Game
        window.clear();
        window.draw(background);
        for (auto& enemy : enemies) {
            enemy.drawEnemy(window);
        }
        drawTowers();
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