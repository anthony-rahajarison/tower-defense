#include "projectile.hpp"
#include "position.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int hp = 10;
        int maxHp = 10;
        float speed = 1;
        int reward = 5;
        bool isAlive = true;
    
    public:
        sf::Sprite sprite;
        sf::Texture texture, enemy1, enemy2, enemy3;
        Position position;

        // void receiveProjectile(Projectile proj);
        void takeDamage(int damage);
        void die();
        void move(int x, int y);

        void loadTextures();
        void drawEnemy(sf::RenderWindow& window);

        Enemy();
};

#endif