//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_QUEEN_H
#define ECHEC_QUEEN_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"


class Queen : public Piece{
public:
    Queen(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest);
};


#endif //ECHEC_QUEEN_H
