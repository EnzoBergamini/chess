//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Bishop.h"

Bishop::Bishop(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265D" : "\u2657",id,pos){}

bool Bishop::isLegalMove(Square pos) {
    if (abs(pos.getColumn() - this->position.getColumn()) != abs(pos.getLine() - this->position.getLine())){
        return false;
    }
    return true;
}