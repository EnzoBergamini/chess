//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Piece.h"
#include "../include/Rook.h"

Rook::Rook(Couleur color, int id, Square pos) :
Piece(color, (color == white) ? "\u265C" : "\u2656", id, pos) {}

bool Rook::isLegalMove(Square dest) {
    if (dest.getLine() != this->position.getLine() && dest.getColumn() != this->position.getColumn()){
        return false;
    }
    return true;
}
