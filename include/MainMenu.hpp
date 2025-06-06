#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

enum class GameState {
    MainMenu,
    Playing,
    Score
};


class MainMenu {
public:
    MainMenu();  
    void run();
    void handleEvents();
    void render();

private:
    sf::RenderWindow window;  

    sf::Texture backgroundTexture;
    sf::Sprite background;

    sf::Texture playButtonTexture;
    sf::Sprite playButton;

    sf::Texture scoreButtonTexture;
    sf::Sprite scoreButton;

    sf::Texture soundOnTexture, soundOffTexture;
    sf::Sprite soundButton;

    sf::SoundBuffer buffer;
    sf::Sound clickSound;

    bool isMuted = false;
};

#endif
