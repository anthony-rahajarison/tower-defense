#include <iostream>
#include "scoreScreen.hpp" 

enum class AppState {
    MainMenu,
    Game,
    scoreScreen,
    Exit
};

scoreScreen::scoreScreen(sf::RenderWindow& win) : window(win) {
    // Background
    if (!backgroundTexture.loadFromFile("assets/backgroundMainMenu.png")) {
        std::cerr << "Erreur de chargement de la texture de fond" << std::endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(
        800.0f / background.getLocalBounds().width,
        800.0f / background.getLocalBounds().height
    );

    // Quit Button
    if (!buttonquitTexture.loadFromFile("assets/buttons/quit.png")) {
        std::cerr << "Erreur de chargement du bouton quit" << std::endl;
    }
    buttonquit.setTexture(buttonquitTexture);
    buttonquit.setScale(
        150.0f / buttonquit.getLocalBounds().width,
        150.0f / buttonquit.getLocalBounds().height
    );
    buttonquit.setPosition(0, 0); 
}

AppState scoreScreen::run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.draw(buttonquit);
        window.display();
    }
    return AppState::Exit;
}

