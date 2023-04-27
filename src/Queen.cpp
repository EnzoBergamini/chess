//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Queen.h"

Queen::Queen(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265B" : "\u2655",id,pos){}