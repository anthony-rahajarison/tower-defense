#include "tower.hpp"

Enemy Tower::findTargets(Enemy enemy) {
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

Projectile Tower::sendProjectile() {

}

void Tower::upgrade() {
    this->level += 1;
    this->sellPrice += 50;
    this->upgradePrice += 100;
}

void Tower::destroy() {
    this->level = 0;
}