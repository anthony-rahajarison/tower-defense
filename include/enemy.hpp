#include "projectile.hpp"
#include <iostream>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int hp = 10;
        int maxHp = 10;
        float speed = 1;
        int reward = 5;
        int posX = 0;
        int posY = 0;
        bool isAlive = true;
    
    public:
        void receiveProjectile(Projectile proj);
        void takeDamage(int damage);
        void die();
        void move(int x, int y);
};

#endif