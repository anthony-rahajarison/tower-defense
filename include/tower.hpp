#ifndef TOWER_HPP
#define TOWER_HPP

#include "position.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>


struct TowerStats {
    int range;
    int damage;
    float attackSpeed;
    int sellPrice;
};

class Tower {
    private :
        int level = 0;
        int sellPrice = 0;
        Enemy target;
        float fireCooldown = 0.f;
        static const int upgradePrices[3];

    
    public :
        // Sprite and textures
        void loadTextures();
        Position position;
        sf::Sprite sprite;
        sf::Texture tower0Texture, tower1Texture, tower2Texture, tower3Texture;
        sf::Texture texture = tower0Texture;
        void drawTower(sf::RenderWindow& window);

        TowerStats getStats() const;
        int upgradePrice = 100;
        void upgrade(Player *playerobj);
        void destroy();
        void update(std::vector<Enemy*>& enemies, float deltaTime);
        
        Tower(int x, int y);
};
#endif