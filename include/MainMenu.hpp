#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class AppState;

class MainMenu {
    private:
        sf::RenderWindow& window;
        sf::Texture backgroundTexture, playButtonTexture, scoreButtonTexture, soundOnTexture, soundOffTexture, quitButtonTexture;
        sf::Sprite background, playButton, scoreButton, soundButton, quitButton;
        sf::SoundBuffer buffer;
        sf::Sound clickSound;
        bool isMuted = false;

        void render();
        AppState handleEvents();

    public:
        MainMenu(sf::RenderWindow& win);
        AppState run();


};
