#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MainMenu.hpp"


MainMenu::MainMenu() 
    : window(sf::VideoMode(800, 1000), "KINGDOM SIEGE"), isMuted(false)

{
    //background

    if (!backgroundTexture.loadFromFile("./assets/backgroundMainMenu.png")) {
        std::cout << "Erreur: Impossible de charger l'image de fond!" << std::endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(
        800.0f / background.getLocalBounds().width,
        1000.0f / background.getLocalBounds().height
    );

    //play button
    if (!playButtonTexture.loadFromFile("./assets/buttons/buton_play.png")) {
        std::cout << "Erreur: Impossible de charger le bouton Play!" << std::endl;
    }
        playButton.setTexture(playButtonTexture);
        playButton.setScale(
        300.0f / playButton.getLocalBounds().width,
        100.0f / playButton.getLocalBounds().height
    );
        playButton.setPosition(400, 250);

     //score button
    if (!scoreButtonTexture.loadFromFile("./assets/buttons/score.png")) {
        std::cout << "Erreur: Impossible de charger le bouton Score !" << std::endl;
    }
        scoreButton.setTexture(scoreButtonTexture);
        scoreButton.setScale(
        300.0f / scoreButton.getLocalBounds().width,
        100.0f / scoreButton.getLocalBounds().height
    );
        scoreButton.setPosition(400, 400);

    //ajouter bouton quitter


    //sound button
    if (!soundOnTexture.loadFromFile("./assets/buttons/soundOn.png")) {
        std::cout<< "Erreur: Impossible de charger soundOn.png!" << std::endl;
    }
    if (!soundOffTexture.loadFromFile("./assets/buttons/soundOff.png")) {
        std::cout << "Erreur: Impossible de charger soundOff.png!" << std::endl;
    }
    soundButton.setTexture(soundOnTexture);
    soundButton.setScale(
        100.0f / soundButton.getLocalBounds().width,
         100.0f / soundButton.getLocalBounds().height);
    soundButton.setPosition(0, 0);

    if (!buffer.loadFromFile("./assets/sounds/music.mp3")) {
        std::cout << "Erreur de chargement du son!" << std::endl;
    }

    clickSound.setBuffer(buffer);
    clickSound.play(); 
}

void MainMenu::run() {
    while (window.isOpen()) {
        handleEvents();
    }
}


void MainMenu::handleEvents(){
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2f mousePos = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );

                if (playButton.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Démarrage du jeu!" << std::endl;
                    
                }
                else if(scoreButton.getGlobalBounds().contains(mousePos)){
                    std::cout <<"Affichage du tableau score" << std::endl;
                }
                else if (soundButton.getGlobalBounds().contains(mousePos)){
                    isMuted = !isMuted;
                    if (isMuted){
                        soundButton.setTexture(soundOffTexture);
                        std::cout<<"son désactivé"<< std::endl;
                        clickSound.pause();
                    }else {
                        soundButton.setTexture(soundOnTexture);
                        std::cout<<"son activé"<<std::endl;
                        clickSound.play();
                    }
                }

            }
        }
        render();
    }
}

void MainMenu::render() {
    window.clear();
    window.draw(background);
    window.draw(playButton);
    window.draw(scoreButton);
    window.draw(soundButton);
    window.display();
}

