//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Knight.h"

Knight::Knight(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265E" : "\u2658",id,pos){}

bool Knight::isLegalMove(Square dest, bool isCatch){
    if (((abs(dest.getLine() - this->position.getLine()) == 2) && (abs(dest.getColumn() - this->position.getColumn()) == 1))
        || ((abs(dest.getLine() - this->position.getLine()) == 1) && (abs(dest.getColumn() - this->position.getColumn()) == 2))){
        return true;
    }
    return false;
}