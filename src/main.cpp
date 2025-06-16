#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "Game.hpp"
#include "scoreScreen.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "KINGDOM SIEGE");
    AppState state = AppState::MainMenu;

    MainMenu menu(window);
    Game game(window);
    scoreScreen scoreScreen(window); 

    while (window.isOpen() && state != AppState::Exit) {
        switch (state) {
            case AppState::MainMenu:
                state = menu.run();
                break;
            case AppState::InGame:
                state = game.run();
                break;
            case AppState::ScoreScreen:
                state = scoreScreen.run();
                break;
            default:
                window.close();
                break;
        }
    }

    return 0;
}
