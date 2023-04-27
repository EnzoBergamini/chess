//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Bishop.h"

Bishop::Bishop(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265D" : "\u2657",id,pos){}