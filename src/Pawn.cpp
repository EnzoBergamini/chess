//
// Created by Enzo Bergamini on 27/04/2023.
//

#include "../include/Pawn.h"

Pawn::Pawn(Couleur color, int id, Square pos) : Piece(color, (color == white) ? "\u265F" : "\u2659", id, pos) {}
