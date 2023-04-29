//
// Created by Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "Echiquier.h"

#include <iostream>
#include <string>

using namespace std;


class Jeu {
private:
    Echiquier *chessboard;
public:
    Jeu();
    ~Jeu();
    void affiche();
    bool coup();
    bool isPathClear(Square start, Square end);
    bool movePiece(Square start, Square end);
};


#endif //ECHEC_JEU_H
