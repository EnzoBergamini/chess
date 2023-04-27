//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Square.h"

#include <iostream>
#include <vector>

#define BOARD_SIZE 8


Square::Square(std::string coord) {
    this->coord = coord;
    this->x = coord[0] - 'A' + 1;
    this->y = (coord[1] - '1') + 1;
}

Square::Square(int x, int y) {
    this->x = x;
    this->y = y;
    this->coord = std::string(1, x + 'A') + std::string(1, y + '1');
}

std::string Square::getCoordString() {
    return this->coord;
}

int Square::getLine() {
    return this->y;
}

int Square::getColumn() {
    return this->x;
}
