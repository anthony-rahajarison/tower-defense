#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(696, 523), "Tower Defense");

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/ponsb/OneDrive/Documents/tower-defense/assets/maps/map1.png")) {
        std::cerr << "Erreur : image non trouvée" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
