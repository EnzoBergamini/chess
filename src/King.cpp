//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/King.h"

King::King(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265A" : "\u2654",id,pos){
}

bool King::isLegalMove(Square pos){
    cout << "King::isLegalMove" << endl;
    if ((abs(pos.getColumn() - this->position.getColumn()) > 1)
        || (abs(pos.getLine() - this->position.getLine()) > 1)){
        return false;
    }
    return true;
}