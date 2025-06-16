#include "projectile.hpp"
#include "position.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int maxHp = 10;
        int hp = maxHp;
        float speed = 200.0f;
        int reward = 5;
        bool isAlive = true;
        int currentPathIndex = 0;
    
    public:
        sf::Sprite sprite;
        sf::Texture texture, enemy1, enemy2, enemy3;
        Position position;

        // void receiveProjectile(Projectile proj);
        void takeDamage(int damage);
        void die();
        void move(int x, int y);
        void followPath(const std::vector<sf::Vector2f>& path, float deltaTime);

        void loadTextures();
        void drawEnemy(sf::RenderWindow& window);
        void setPosition(const sf::Vector2f& pos);

        Enemy();
        Enemy(int lvl);
};

#endif