#include "enemy.hpp"
#include <math.h>

void Enemy::takeDamage(int damage) {
    this->hp -= damage;
    if (this->hp <= 0) {
        die();
    }
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

    // Display health bar above the enemy
    if (hp < maxHp) {
        float barWidth = sprite.getGlobalBounds().width;
        float barHeight = 6.f;
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y - barHeight - 4.f;

        sf::RectangleShape backBar(sf::Vector2f(barWidth, barHeight));
        backBar.setFillColor(sf::Color(150, 0, 0));
        backBar.setPosition(x, y);

        float hpRatio = static_cast<float>(hp) / maxHp;
        sf::RectangleShape hpBar(sf::Vector2f(barWidth * hpRatio, barHeight));
        hpBar.setFillColor(sf::Color(0, 200, 0));
        hpBar.setPosition(x, y);

        window.draw(backBar);
        window.draw(hpBar);
    }
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

int Enemy::getReward() {
    return this->reward;
}

Enemy::Enemy(int level) {
    loadTextures();
    int type = 1;
    if (type == 1) {
        this->texture = enemy1;
    }

    // Hp, speed and rewards based on level
    this->maxHp = 10 + (level - 1) * 5;
    this->hp = this->maxHp;
    this->speed = 100.0f + (level - 1) * 20.0f;
    this->reward = 10 + (level - 1) * 2;
    if (this->reward > 25) {
        this->reward = 25; // Cap the reward at 25
    }
}