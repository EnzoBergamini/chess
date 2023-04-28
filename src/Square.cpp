//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Square.h"

#include <iostream>
#include <vector>

#define BOARD_SIZE 8


Square::Square(std::string coord) {
    this->coord = coord;
    this->x = coord[0] - 'A';
    this->y = (coord[1] - '1');
}

Square::Square(int x, int y) {
    this->x = x;
    this->y = y;
    this->coord = std::string(1, (char) (x + 'A')) + std::string(1, (char) ( y + '1'));
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

void Square::affiche() {
    std::cout << this->coord << std::endl;
    std::cout << "ligne : " << this->y << " et colonne : " << this->x << std::endl;
}
