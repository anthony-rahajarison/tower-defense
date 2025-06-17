#include "position.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int hp;
        int maxHp;
        float speed;
        int reward;
        int level;

    public:
        bool isAlive = true;
        int currentPathIndex = 0;
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
        int getReward();

        Enemy(int level = 1);
};

#endif