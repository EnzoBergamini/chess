/**
 * @file Rook.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/
#include "../include/Piece.h"
#include "../include/Rook.h"

Rook::Rook(Couleur color, int id, Square pos) :
Piece(color, (color == black) ? "\u265C" : "\u2656", id, pos) {}

bool Rook::isLegalMove(Square dest, bool isCatch) const{
    Square start = this->position;

    if (dest.getLine() != start.getLine() && dest.getColumn() != start.getColumn()){
        return false;
    }

    return true;
}
