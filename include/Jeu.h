//
// Created by Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "Echiquier.h"
#include "Couleur.h"

#include <iostream>
#include <string>

using namespace std;


class Jeu {
private:
    Echiquier *chessboard;
    Couleur current_player;
public:
    Jeu();
    ~Jeu();
    void affiche();
    bool coup();
    void setPlayer(Couleur c);
    Couleur getPlayer();
    bool isPathClear(Square start, Square end);
    bool movePiece(Square start, Square end);
    void displayEndGame(string result);
    bool isKingInCheck(Couleur c);
    bool isCapturable(Square square, Couleur c);
    bool isCheckMove(Square start, Square end ,Couleur c);
};


#endif //ECHEC_JEU_H
