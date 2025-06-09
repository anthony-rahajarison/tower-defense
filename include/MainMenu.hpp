#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class AppState;

class MainMenu {
public:
    MainMenu(sf::RenderWindow& win);
    AppState run();

private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture, playButtonTexture, scoreButtonTexture, soundOnTexture, soundOffTexture;
    sf::Sprite background, playButton, scoreButton, soundButton;
    sf::SoundBuffer buffer;
    sf::Sound clickSound;
    bool isMuted = false;

    void render();
    AppState handleEvents();
};
