/**
 * @file King.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#include "../include/King.h"

King::King(Couleur color,int id,Square pos)
    : Piece(color,(color == black) ? "\u265A" : "\u2654",id,pos){
}

bool King::isLegalMove(Square dest, bool isCatch) const{
    (void) isCatch; // Ici pas utilisé
    if ((abs(dest.getColumn() - this->position.getColumn()) > 1)
        || (abs(dest.getLine() - this->position.getLine()) > 1)){
        return false;
    }
    return true;
}