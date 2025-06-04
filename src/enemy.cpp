#include "enemy.hpp"

void Enemy::receiveProjectile(Projectile proj) {
    this->takeDamage(proj.get_damage());
}

void Enemy::takeDamage(int damage) {
    this->hp -= damage;
}

void Enemy::die() {
    this->isAlive = false;
}

void Enemy::move(int x, int y) {
    this->position.set_x(x);
    this->position.set_y(y);
}