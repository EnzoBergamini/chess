//
// Created by Enzo Bergamini on 27/04/2023.
//

#ifndef ECHEC_ROOK_H
#define ECHEC_ROOK_H

#include "Piece.h"
#include "Couleur.h"

class Rook : public Piece{
public:
    Rook(Couleur color,int id, Square pos);

    bool isLegalMove(Square dest, bool isCatch = false);

};


#endif //ECHEC_ROOK_H
