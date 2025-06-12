#include "enemy.hpp"

// void Enemy::receiveProjectile(Projectile proj) {
//     this->takeDamage(proj.get_damage());
// }

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

void Enemy::drawEnemy(sf::RenderWindow& window) {
    sprite.setTexture(texture);
    sprite.setPosition(position.get_x(), position.get_y());
    sprite.setScale(1.f, 1.f);
    window.draw(sprite);
}

void Enemy::loadTextures() {
    if (!enemy1.loadFromFile("./assets/enemies/enemy1.png")) {
        std::cerr << "Erreur de chargement de tower0"<< std::endl;
    }
}

Enemy::Enemy() {
    loadTextures();
    int type = 1;
    if (type == 1) {
        this->texture = enemy1;
    }
}