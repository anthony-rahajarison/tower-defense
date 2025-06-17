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
    while (window.isOpen() && !gameOver) { // Ajoute !gameOver ici
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

    return AppState::MainMenu; // Retourne bien au menu principal après Game Over
}

void Game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                
            if (buttonWave.getGlobalBounds().contains(mousePos)) {
                bool isGameOver = launchWave();
                if (!isGameOver) {
                    wave.nextWave();
                }
                else {
                    std::cout << "Game Over! Returning to Main Menu." << std::endl;
                    gameOver = true;
                    return; // Exit the game loop
                }
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


bool Game::launchWave() {
    std::cout << "Lancement de la vague " << wave.waveLevel << " !" << std::endl;

    int totalEnemies = wave.n_enemy;
    float spawnDelay = wave.spawnDelay;

    std::vector<Enemy> enemies;
    sf::Clock spawnClock;
    size_t spawnedEnemies = 0;

    sf::Clock frameClock;
    
    // Put enemies in a vector to keep track of them
    std::vector<bool> rewarded(totalEnemies, false);

    while (window.isOpen()) {
        float deltaTime = frameClock.restart().asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Create a new enemy
        if (spawnedEnemies < totalEnemies && spawnClock.getElapsedTime().asSeconds() >= spawnDelay) {
            Enemy e(wave.waveLevel); // Get wave level for enemy
            e.setPosition(pathPoints[0]);
            enemies.push_back(e);
            rewarded[spawnedEnemies] = false; // Flag for reward
            spawnedEnemies++;
            spawnClock.restart();
        }

        // Change enemies position
        for (auto& enemy : enemies) {
            if (enemy.isAlive) {
                enemy.followPath(pathPoints, deltaTime);
            }
        }

        std::vector<Enemy*> enemyPtrs;
        for (auto& e : enemies) {
            if (e.isAlive) {
                enemyPtrs.push_back(&e);
            }
        }

        towerA.update(enemyPtrs, deltaTime);
        towerB.update(enemyPtrs, deltaTime);
        towerC.update(enemyPtrs, deltaTime);
        towerD.update(enemyPtrs, deltaTime);
        towerE.update(enemyPtrs, deltaTime);
        towerF.update(enemyPtrs, deltaTime);

        // Add credit if an enemy is killed
        for (size_t i = 0; i < enemies.size(); ++i) {
            if (!enemies[i].isAlive && !rewarded[i]) {
                player.addCredit(enemies[i].getReward());
                rewarded[i] = true;
            }
        }
        
        // Verify if all enemies have been spawned
        bool allEnemiesSpawned = (spawnedEnemies == totalEnemies);

        // Count alive enemies
        int aliveEnemies = 0;
        for (const Enemy& ennemi : enemies) {
            if (ennemi.isAlive) {
                aliveEnemies++;
            }
        }

        if (allEnemiesSpawned && aliveEnemies == 0) {
            // All enemies have been spawned and defeated
            std::cout << "Wave is over" << std::endl;
            break;
        }

        // Check if any enemy has reached the end of the path
        for (auto& enemy : enemies) {
            if (enemy.isAlive && enemy.currentPathIndex >= pathPoints.size()) {
                player.removeLife();
                enemy.isAlive = false;
                std::cout << "Un ennemi a atteint la fin ! Vies restantes : " << player.returnLives() << std::endl;
            }
        }

        // Check if the game is over
        if (player.isGameOver()) {
            std::cout << "GAME OVER !" << std::endl;
            sf::Text gameOverText;
            gameOverText.setFont(MyFont);
            gameOverText.setString("GAME OVER");
            gameOverText.setCharacterSize(80);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(200, 350);
            window.draw(gameOverText);
            window.display();
            sf::sleep(sf::seconds(2));
            return true;
        }

        // Display Game
        window.clear();
        window.draw(background);
        for (auto& enemy : enemies) {
            if (enemy.isAlive) {
                enemy.drawEnemy(window);
            }
        }
        CreditText.setString("Credits : " + std::to_string(player.returnCredit()));
        window.draw(CreditText);
        drawTowers();
        window.display();
    }
    return false; // Keep the game running
}

void Game::drawTowers(){
    towerA.drawTower(window);
    towerB.drawTower(window);
    towerC.drawTower(window);
    towerD.drawTower(window);
    towerE.drawTower(window);
    towerF.drawTower(window);
}