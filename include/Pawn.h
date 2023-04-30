//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_PAWN_H
#define ECHEC_PAWN_H

#include "Piece.h"
#include "Square.h"
#include "Couleur.h"

class Pawn : public Piece{
public:
    Pawn(Couleur color, int id, Square pos);
    bool isLegalMove(Square dest, bool isCatch = false);
};


#endif //ECHEC_PAWN_H
