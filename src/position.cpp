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