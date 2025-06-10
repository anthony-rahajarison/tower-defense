#ifndef TOWER_HPP
#define TOWER_HPP

#include "position.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

class Tower {
    private :
        Position position;
        int delay = 0;
        int towerRange = 10;
        int projectileRange = 10;
        int level = 1;
        int sellPrice = 50;
        int upgradePrice = 100;
        Enemy target;
    
    public :

        Enemy findTargets(Enemy enemy);
        Projectile sendProjectile();
        void upgrade();
        void destroy();
        void select();
};

#endif