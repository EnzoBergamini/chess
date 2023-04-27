//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/King.h"

King::King(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265A" : "\u2654",id,pos){}