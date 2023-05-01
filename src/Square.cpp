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

int Square::getColumn(){ return column;}

int Square::getLine(){ return line;}

void Square::display(){
    cout << "Colonne : " << this->column << " ligne : " << this->line << endl;
}

bool operator==(const Square &sq1, const Square &sq2){
    return (sq1.getLine() == sq2.getLine()) && (sq1.getColumn() == sq2.getColumn());
}

