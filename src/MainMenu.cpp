#include "MainMenu.hpp"
#include <iostream>

enum class AppState {
    MainMenu,
    Game,
    Score,
    Exit
};

MainMenu::MainMenu(sf::RenderWindow& win) : window(win) {
    backgroundTexture.loadFromFile("./assets/backgroundMainMenu.png");
    background.setTexture(backgroundTexture);
    background.setScale(800.0f / background.getLocalBounds().width, 800.0f / background.getLocalBounds().height);

    playButtonTexture.loadFromFile("./assets/buttons/buton_play.png");
    playButton.setTexture(playButtonTexture);
    playButton.setScale(200.0f / playButton.getLocalBounds().width, 80.0f / playButton.getLocalBounds().height);
    playButton.setPosition(450, 220);

    scoreButtonTexture.loadFromFile("./assets/buttons/score.png");
    scoreButton.setTexture(scoreButtonTexture);
    scoreButton.setScale(200.0f / scoreButton.getLocalBounds().width, 80.0f / scoreButton.getLocalBounds().height);
    scoreButton.setPosition(450, 320);

    soundOnTexture.loadFromFile("./assets/buttons/soundOn.png");
    soundOffTexture.loadFromFile("./assets/buttons/soundOff.png");
    soundButton.setTexture(soundOnTexture);
    soundButton.setScale(100.0f / soundButton.getLocalBounds().width, 100.0f / soundButton.getLocalBounds().height);
    soundButton.setPosition(0, 0);

    quitButtonTexture.loadFromFile("./assets/buttons/buton_quit.png");
    quitButton.setTexture(quitButtonTexture);
    quitButton.setScale(300.0f / quitButton.getLocalBounds().width, 300.0f / quitButton.getLocalBounds().height);
    quitButton.setPosition(400, 320);

    buffer.loadFromFile("./assets/sounds/music.mp3");
    clickSound.setBuffer(buffer);
    clickSound.play();
}

AppState MainMenu::run() {
    while (window.isOpen()) {
        AppState result = handleEvents();
        if (result != AppState::MainMenu) return result;
        render();
    }
    return AppState::Exit;
}

AppState MainMenu::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return AppState::Exit;
        }

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            if (playButton.getGlobalBounds().contains(mousePos)) {
                return AppState::Game;
            } else if (scoreButton.getGlobalBounds().contains(mousePos)) {
                return AppState::Score;
            } else if (quitButton.getGlobalBounds().contains(mousePos)){
                window.close();
                std::cout<<"fermeture du programme";
                return AppState::Exit;
            } else if (soundButton.getGlobalBounds().contains(mousePos)) {
                isMuted = !isMuted;
                soundButton.setTexture(isMuted ? soundOffTexture : soundOnTexture);
                if (isMuted) clickSound.pause();
                else clickSound.play();
            }
        }
    }
    return AppState::MainMenu;
}

void MainMenu::render() {
    window.clear();
    window.draw(background);
    window.draw(playButton);
    window.draw(scoreButton);
    window.draw(soundButton);
    window.draw(quitButton);
    window.display();
}
