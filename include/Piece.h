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
    size_t move_count;
    bool is_catch;

public:
    Piece(Couleur c,string name,int id, Square position);

    virtual ~Piece();

    void affiche();

    void displayInfo();

    void setSquare(Square pos);

    void setCatch(bool isCatch);

    Square getSquare();

    string getName();

    Couleur getColor();

    bool getCatch();

    virtual bool isLegalMove(Square dest, bool isCatch = false);

    void incrementMoveCount();

    size_t getMoveCount();
};


#endif //ECHEC_PIECE_H
