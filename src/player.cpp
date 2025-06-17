#include "player.hpp"
#include <iostream>

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