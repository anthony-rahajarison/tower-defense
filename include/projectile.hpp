#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "enemy.hpp"
#include "position.hpp"

class Projectile {
    private :
        int damage = 1;
        float speed = 1;
        Position position;
    public :
        void getPosition(int x, int y);
        void hitTarget(Enemy enemy);
        void move(int x, int y);

        int get_damage();
};

#endif