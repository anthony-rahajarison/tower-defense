#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    //window
    sf::RenderWindow window(sf::VideoMode(800, 1000), "KINGDOM SIEGE");

    //background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/Users/ponsb/OneDrive/Documents/tower-defense/assets/ecranD'acceuil.png")) {
        std::cerr << "Erreur: Impossible de charger l'image de fond!" << std::endl;
        return -1; 
    }

    sf::Sprite background(backgroundTexture);
    background.setScale(
        800.0f / background.getLocalBounds().width,
        1000.0f / background.getLocalBounds().height
    );

    //play button
    sf::Texture playButtonTexture;
    if (!playButtonTexture.loadFromFile("./assets/buttons/buton_play.png")) {
        std::cerr << "Erreur: Impossible de charger le bouton Play!" << std::endl;
        return -1;
    }

    sf::Sprite playButton(playButtonTexture);
        playButton.setScale(
        300.0f / playButton.getLocalBounds().width,
        100.0f / playButton.getLocalBounds().height
    );

    playButton.setPosition(400, 250);

     //score button
    sf::Texture scoreButtonTexture;
    if (!scoreButtonTexture.loadFromFile("./assets/buttons/score.png")) {
        std::cerr << "Erreur: Impossible de charger le bouton Score !" << std::endl;
        return -1;
    }

    sf::Sprite scoreButton(scoreButtonTexture);
        scoreButton.setScale(
        300.0f / scoreButton.getLocalBounds().width,
        100.0f / scoreButton.getLocalBounds().height
    );
    
    scoreButton.setPosition(400, 400);


    //ajouter bouton quitter

    //sound button
    sf::Texture soundOnTexture, soundOffTexture;
    if (!soundOnTexture.loadFromFile("./assets/buttons/soundOn.png")) {
        std::cerr << "Erreur: Impossible de charger soundOn.png!" << std::endl;
        return -1;
    }
    if (!soundOffTexture.loadFromFile("./assets/buttons/soundOff.png")) {
        std::cerr << "Erreur: Impossible de charger soundOff.png!" << std::endl;
        return -1;
    }
    sf::Sprite soundButton(soundOnTexture); // par défaut, son activé
    soundButton.setScale(
        100.0f / soundButton.getLocalBounds().width,
         100.0f / soundButton.getLocalBounds().height);
    soundButton.setPosition(0, 0);

    
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("./assets/sounds/music.mp3")) {
        std::cerr << "Erreur de chargement du son!" << std::endl;
        return -1;
    }

    sf::Sound clickSound;
    clickSound.setBuffer(buffer);
    clickSound.play(); 

    bool isMuted = false;

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


        window.clear();
        window.draw(background);
        window.draw(playButton);
        window.draw(scoreButton);
        window.draw(soundButton);
        window.display();
    }

    return 0;
}
