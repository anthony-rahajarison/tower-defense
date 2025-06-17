#include "tower.hpp"

const std::vector<TowerStats> towerLevels = {
// Range, DMG, AtkSpd, Sell

    {  0,  0, 0.f,    0}, // Level 0
    {200, 10, 1.f,  100}, // Level 1
    {250, 20, 0.7f, 200}, // Level 2
    {300, 35, 0.5f, 300}  // Level 3
};

const int Tower::upgradePrices[3] = {100, 500, 3000}; // Prix pour passer niveau 1, 2, 3

void Tower::update(std::vector<Enemy*>& enemies, float deltaTime) {
    if (this->level == 0) { 
        return; // Skip unbuilt towers
    }

    TowerStats stats = getStats();
    
    fireCooldown -= deltaTime; // Elapsed time since last shot

    for (Enemy* enemy : enemies) {
        if (!enemy->isAlive) continue;

        sf::Vector2f enemyPos = enemy->sprite.getPosition();
        float dx = position.get_x() - enemyPos.x;
        float dy = position.get_y() - enemyPos.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= stats.range && fireCooldown <= 0.f) {
            enemy->takeDamage(stats.damage);
            fireCooldown = stats.attackSpeed;
            break;
        }
    }
}

TowerStats Tower::getStats() const {
    if (this->level <= 3) {
        return towerLevels[level];
    }
    std::cout << "Invalid tower level, returning empty tower" << std::endl;
    return towerLevels[0];
}


//Towers Textures
void Tower::loadTextures() {
    if (!tower0Texture.loadFromFile("./assets/tower/magicTower0.png")) {
        std::cerr << "Erreur de chargement de tower0"<< std::endl;
    }

    if (!tower1Texture.loadFromFile("./assets/tower/magicTower1.png")) {
        std::cerr << "Erreur de chargement de tower1"<< std::endl;
    }

    if (!tower2Texture.loadFromFile("./assets/tower/magicTower2.png")) {
        std::cerr << "Erreur de chargement de tower2"<< std::endl;
    }

    if (!tower3Texture.loadFromFile("./assets/tower/magicTower3.png")) {
        std::cerr << "Erreur de chargement de tower3"<< std::endl;
    }
}


void Tower::upgrade(Player *playerobj) {
    if (this->level >= 3) {
        std::cout << "Tower is already at max level." << std::endl;
        return;
    }

    int price = upgradePrices[level]; // Get the price for the next upgrade
    if (playerobj->returnCredit() >= price) {
        playerobj->removeCredit(price);
        this->level++;
        switch (level) {
            case 1:
                texture = tower1Texture;
                break;
            case 2:
                texture = tower2Texture;
                break;
            case 3:
                texture = tower3Texture;
                break;
            default:
                break;
        }
        sprite.setTexture(texture);
    } else {
        std::cout << "Not enough credits to upgrade." << std::endl;
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
        
    } else {
        sf::Color color = sprite.getColor();
        color.a = 255;
        sprite.setColor(color);
    }
    sprite.setTexture(texture);
    sprite.setPosition(position.get_x(), position.get_y());
    sprite.setScale(0.8f, 0.8f);
    window.draw(sprite);
}


Tower::Tower(int x, int y) {
    position.set_x(x);
    position.set_y(y);
    this->level = 0;
    this->fireCooldown = 0.f;

    loadTextures();
    this->texture = tower0Texture;
}