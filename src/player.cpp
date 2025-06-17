#include "player.hpp"
#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void Player::addCredit(int c) {
    this->credit += c;
};

void Player::removeCredit(int c){
    this->credit -= c; 
};

void Player::removeLife(){
    this->remainingLives--;
};

bool Player::isGameOver(){
    if (this->remainingLives==0){
        this->gameover = true;
    }
    return this->gameover;
};

Player::Player() {

}

int Player::returnCredit() {
    return this->credit;
}

int Player::returnLives() {
    return this->remainingLives;
}

void Player::addScore(int s) {
    this->score += s;
}

int Player::returnScore() {
    return this->score;
}

int Player::loadHighScore(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return 0;
    json j;
    file >> j;
    if (j.contains("highscore")) {
        return j["highscore"];
    }
    return 0;
}

void Player::saveHighScore(int score, const std::string& filename) {
    int oldScore = loadHighScore(filename);
    if (score > oldScore) {
        json j;
        j["highscore"] = score;
        std::ofstream file(filename);
        file << j.dump(4);
    }
}