#include "player.hpp"
#include <iostream>

void Player::addCredit(int c) {
    this->credit += c;

};

void Player::removeCredit(int c){
    this->credit -= c; 
};

void Player::removeLife(){
    this -> remainingLives -1;
};

bool Player::isGameOver(){
    if (this->remainingLives==0){
        this->gameover = true;
    }
    return this->gameover;
};

