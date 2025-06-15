#include "enemy.hpp"
#include <math.h>

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
    sprite.setScale(1.f, 1.f);
    window.draw(sprite);
}

void Enemy::loadTextures() {
    if (!enemy1.loadFromFile("./assets/enemies/enemy1.png")) {
        std::cerr << "Erreur de chargement de tower0"<< std::endl;
    }
}

void Enemy::followPath(const std::vector<sf::Vector2f>& path, float deltaTime) {
    if (currentPathIndex >= path.size()) {
        return;
    }

    sf::Vector2f target = path[currentPathIndex];
    sf::Vector2f direction = target - sprite.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 1.0f) {
        currentPathIndex++;
        if (currentPathIndex >= path.size()) {
            return;
        }

        target = path[currentPathIndex];
        direction = target - sprite.getPosition();
        distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    }

    if (distance != 0) {
        direction /= distance;
        sprite.move(direction * speed * deltaTime);
    }
}

void Enemy::setPosition(const sf::Vector2f& pos) {
    sprite.setPosition(pos);
    currentPathIndex = 1; // Set next point as target
}

Enemy::Enemy() {
    loadTextures();
    int type = 1;
    if (type == 1) {
        this->texture = enemy1;
    }
}