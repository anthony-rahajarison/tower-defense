#ifndef TOWER_HPP
#define TOWER_HPP

#include "position.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include <SFML/Graphics.hpp>

class Tower {
    private :
        int delay = 0;
        int towerRange = 10;
        int projectileRange = 10;
        int level = 0;
        int sellPrice = 50;
        int upgradePrice = 100;
        
        
        Enemy target;

    
    public :
        Position position;
        sf::Sprite sprite;
        sf::Texture texture;
        void findTargets(Enemy enemy);
        Projectile sendProjectile();
        void upgrade();
        void destroy();
        void drawTower(sf::RenderWindow& window);
        Tower(int x, int y);
};
#endif