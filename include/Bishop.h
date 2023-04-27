//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_BISHOP_H
#define ECHEC_BISHOP_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

class Bishop : public Piece{
public:
    Bishop(Couleur c,int id,Square pos);

};


#endif //ECHEC_BISHOP_H
