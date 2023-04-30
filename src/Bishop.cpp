//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Bishop.h"

Bishop::Bishop(Couleur color,int id,Square pos)
    : Piece(color,(color == black) ? "\u265D" : "\u2657",id,pos){}

bool Bishop::isLegalMove(Square dest, bool isCatch) {
    if (abs(dest.getColumn() - this->position.getColumn()) != abs(dest.getLine() - this->position.getLine())){
        return false;
    }
    return true;
}