#include "projectile.hpp"

// void Projectile::hitTarget(Enemy enemy) {
//     enemy.receiveProjectile(*this);
// }

void Projectile::move(int x, int y) {
    this->position.set_x(x);
    this->position.set_y(y);
}

int Projectile::get_damage() {
    return this->damage;
}