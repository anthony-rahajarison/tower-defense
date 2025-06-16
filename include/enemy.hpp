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
        float speed = 100.0f;
        int reward = 5;
        int currentPathIndex = 0;
    
    public:
        bool isAlive = true;
        sf::Sprite sprite;
        sf::Texture texture, enemy1, enemy2, enemy3;
        Position position;
        void loadTextures();
        void drawEnemy(sf::RenderWindow& window);

        void takeDamage(int damage);
        void die();
        void move(int x, int y);
        void followPath(const std::vector<sf::Vector2f>& path, float deltaTime);

        void setPosition(const sf::Vector2f& pos);

        Enemy();
};

#endif