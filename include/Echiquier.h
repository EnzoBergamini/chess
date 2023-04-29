//
// Created by Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_ECHIQUIER_H
#define ECHEC_ECHIQUIER_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Couleur.h"

#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

using namespace std;

class Echiquier
{
private:
    Piece ***echiquier;
    vector<Piece *> pieces[2];
public:
    Echiquier();
    ~Echiquier();
    void affiche();
    void posePiece(Piece *p, Square pos);
    void allocMemEchiquier();
    void initEchiquier();
    void movePiece(Square pos1, Square pos2);
    Piece *getPiece(Square pos);
};


#endif //ECHEC_ECHIQUIER_H
