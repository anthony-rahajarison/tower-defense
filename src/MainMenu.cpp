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
    background.setScale(800.0f / background.getLocalBounds().width, 1000.0f / background.getLocalBounds().height);

    playButtonTexture.loadFromFile("./assets/buttons/buton_play.png");
    playButton.setTexture(playButtonTexture);
    playButton.setScale(300.0f / playButton.getLocalBounds().width, 100.0f / playButton.getLocalBounds().height);
    playButton.setPosition(400, 250);

    scoreButtonTexture.loadFromFile("./assets/buttons/score.png");
    scoreButton.setTexture(scoreButtonTexture);
    scoreButton.setScale(300.0f / scoreButton.getLocalBounds().width, 100.0f / scoreButton.getLocalBounds().height);
    scoreButton.setPosition(400, 400);

    soundOnTexture.loadFromFile("./assets/buttons/soundOn.png");
    soundOffTexture.loadFromFile("./assets/buttons/soundOff.png");
    soundButton.setTexture(soundOnTexture);
    soundButton.setScale(100.0f / soundButton.getLocalBounds().width, 100.0f / soundButton.getLocalBounds().height);
    soundButton.setPosition(0, 0);

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
    window.display();
}
