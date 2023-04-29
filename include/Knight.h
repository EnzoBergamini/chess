//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_KNIGHT_H
#define ECHEC_KNIGHT_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"


class Knight : public Piece{
public:
    Knight(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest);
};


#endif //ECHEC_KNIGHT_H
