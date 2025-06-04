#include "projectile.hpp"

void Projectile::hitTarget(Enemy enemy) {
    enemy.receiveProjectile(*this);
}

void move(int x, int y) {
    
}

int Projectile::get_damage() {
    return this->damage;
}