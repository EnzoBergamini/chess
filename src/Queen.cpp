/**
 * @file Queen.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#include "../include/Queen.h"

Queen::Queen(Couleur color,int id,Square pos)
    : Piece(color,(color == black) ? "\u265B" : "\u2655",id,pos){}

bool Queen::isLegalMove(Square dest, bool isCatch) const{
    (void) isCatch; // Ici pas utilisé
    if (abs(dest.getColumn() - this->position.getColumn()) == abs(dest.getLine() - this->position.getLine())){
        return true;
    }
    if (dest.getColumn() == this->position.getColumn() || dest.getLine() == this->position.getLine()){
        return true;
    }

    return false;
}