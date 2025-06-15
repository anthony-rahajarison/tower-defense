#include "position.hpp"
#include <iostream>

void Position::set_x(int value_x){
    this-> x = value_x;
}
void Position::set_y(int value_y){
    this-> y = value_y;
}

int Position::get_x(){
    return this->x;
}

int Position::get_y(){
    return this->y;
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::Position() {
    this->x = 0;
    this->y = 0;
}