//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Knight.h"

Knight::Knight(Couleur color,int id,Square pos)
    : Piece(color,(color == white) ? "\u265E" : "\u2658",id,pos){}