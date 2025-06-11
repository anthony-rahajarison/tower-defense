#include "tower.hpp"

void Tower::findTargets(Enemy enemy) {
    int towerX = this->position.get_x();
    int towerY = this->position.get_y();
    int enemyX = enemy.position.get_x();
    int enemyY = enemy.position.get_y();

    if ((enemyX <= towerX + this->towerRange) && (enemyX >= towerX - this->towerRange)) {
        if ((enemyY <= towerY + this->towerRange) && (enemyY >= towerY - this->towerRange)) {
            this->target = enemy;
        }
    }
}

// Projectile Tower::sendProjectile() {

// }

void Tower::upgrade() {
    this->level += 1;
    this->sellPrice += 50;
    this->upgradePrice += 100;
}

void Tower::destroy() {
    this->level = 0;
}

void Tower::drawTower(sf::RenderWindow& window) {
    if (level == 0) {
        sf::Color color = sprite.getColor();
        color.a = 140;
        sprite.setColor(color);
        
    }
    sprite.setTexture(texture);
    sprite.setPosition(position.get_x(), position.get_y());
    sprite.setScale(1.5f, 1.5f);
    window.draw(sprite);
}

Tower::Tower(int x, int y) {
    position.set_x(x);
    position.set_y(y);
}