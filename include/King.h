//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_KING_H
#define ECHEC_KING_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

#include <iostream>

using namespace std;

class King : public Piece{
public:
    King(Couleur c,int id,Square pos);

    bool isLegalMove(Square pos);
};


#endif //ECHEC_KING_H
