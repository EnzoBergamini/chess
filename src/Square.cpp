//
// Created bline Enzo Bergamini on 24/04/2023.
//

#include "../include/Square.h"

#include <iostream>
#include <vector>

#define BOARD_SIZE 8


Square::Square(int line, int column)
        : line(line), column(column){}

Square::Square(string s){
    column = s[0] - 'a';
    line = s[1] - '0' - 1;
}

int Square::getColumn() const { return column;}

int Square::getLine() const { return line;}

void Square::display(){
    cout << "Colonne : " << this->column << " ligne : " << this->line << endl;
}

bool Square::operator==(const Square &other) const{
    return (this->line == other.getLine() && this->column == other.getColumn());
}

