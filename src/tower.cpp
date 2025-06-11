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

void Tower::loadTextures() {
    if (!tower0Texture.loadFromFile("./assets/tower/tower0.png")) {
        std::cerr << "Erreur de chargement de tower0"<< std::endl;
    }

    if (!tower1Texture.loadFromFile("./assets/tower/tower1.png")) {
        std::cerr << "Erreur de chargement de tower1"<< std::endl;
    }

    if (!tower2Texture.loadFromFile("./assets/tower/tower2.png")) {
        std::cerr << "Erreur de chargement de tower2"<< std::endl;
    }
}
//Towers Textures


void Tower::upgrade(Player *playerobj) {
    if (canUpgrade(playerobj->returnCredit())) {
        playerobj->removeCredit(this->upgradePrice);
        this->level += 1;
        this->sellPrice += 50;
        this->upgradePrice += 100;
        this->texture = tower1Texture;
    }
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

    Tower::loadTextures();
    this->texture = tower0Texture;
}

bool Tower::canUpgrade(int playerCredit) {
    if (this->upgradePrice <= playerCredit) {
        return true;
    }
    else return false;
}