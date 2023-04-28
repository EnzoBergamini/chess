//
// Created by Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_PIECE_H
#define ECHEC_PIECE_H

#include "Square.h"
#include "Couleur.h"

using namespace std;

class Piece {
protected:
    int id;
    string name;
    Couleur couleur;
    Square position;

public:
    Piece(Couleur c,string name,int id, Square position);

    void affiche();

    void displayInfo();

    void setSquare(Square pos);

    Square getSquare();
};


#endif //ECHEC_PIECE_H
