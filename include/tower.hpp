#ifndef TOWER_HPP
#define TOWER_HPP

#include "position.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

class Tower {
    private :
        int delay = 0;
        int towerRange = 10;
        int projectileRange = 10;
        int level = 0;
        int sellPrice = 50;

        Enemy target;

    
    public :
        void loadTextures();
        Position position;
        sf::Sprite sprite;
        sf::Texture tower0Texture, tower1Texture, tower2Texture;
        sf::Texture texture = tower0Texture;
        int upgradePrice = 100;
        void findTargets(Enemy enemy);
        Projectile sendProjectile();
        void upgrade(Player *playerobj);
        void destroy();
        bool canUpgrade(int playerCredit);
        void drawTower(sf::RenderWindow& window);
        Tower(int x, int y);
};
#endif