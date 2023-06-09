/**
 * @file Pawn.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#include "../include/Pawn.h"

Pawn::Pawn(Couleur color, int id, Square pos) :
        Piece(color, (color == black) ? "\u265F" : "\u2659", id, pos) {}

bool Pawn::isLegalMove(Square dest, bool isCatch) const{
    if (isCatch){
        if (this->getColor() == white){
            if ((dest.getColumn() == this->position.getColumn() - 1
                && dest.getLine() == this->position.getLine() + 1) // diagonale gauche
                || (dest.getColumn() == this->position.getColumn() + 1
                && dest.getLine() == this->position.getLine() + 1) // diagonale droite
                ){
                return true;
            }else{
                return false;
            }
        }else{
            if ((dest.getColumn() == this->position.getColumn() - 1
                 && dest.getLine() == this->position.getLine() - 1) // diagonale gauche
                || (dest.getColumn() == this->position.getColumn() + 1
                    && dest.getLine() == this->position.getLine() - 1) // diagonale droite
                ){
                return true;
            }else{
                return false;
            }
        }
    } else {
        if (this->getColor() == white){
            if ((dest.getColumn() == this->position.getColumn() // deplacement vertical
                 && dest.getLine() == this->position.getLine() + 1) // avance d'une case
                ){
                return true;
            }else if (this->getMoveCount() == 0
                      && dest.getColumn() == this->position.getColumn() // deplacement vertical
                      && dest.getLine() == this->position.getLine() + 2 // avance de deux cases
                      ){
                return true;
            }else{
                return false;
            }
        }else{
            if ((dest.getColumn() == this->position.getColumn() // deplacement vertical
                 && dest.getLine() == this->position.getLine() - 1) // avance d'une case
                ){
                return true;
            }else if (this->getMoveCount() == 0
                      && dest.getColumn() == this->position.getColumn() // deplacement vertical
                      && dest.getLine() == this->position.getLine() - 2 // avance de deux cases
                    ){
                return true;
            }else{
                return false;
            }
        }
    }
}

