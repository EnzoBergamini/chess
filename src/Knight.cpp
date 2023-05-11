/**
 * @file Knight.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#include "../include/Knight.h"

Knight::Knight(Couleur color,int id,Square pos)
    : Piece(color,(color == black) ? "\u265E" : "\u2658",id,pos){}

bool Knight::isLegalMove(Square dest, bool isCatch) const{
    if (((abs(dest.getLine() - this->position.getLine()) == 2) && (abs(dest.getColumn() - this->position.getColumn()) == 1))
        || ((abs(dest.getLine() - this->position.getLine()) == 1) && (abs(dest.getColumn() - this->position.getColumn()) == 2))){
        return true;
    }
    return false;
}