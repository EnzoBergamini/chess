//
// Created by Enzo Bergamini on 24/04/2023.
//

#include <iostream>

#include "../include/Square.h"
#include "../include/Piece.h"
#include "../include/Echiquier.h"
#include "../include/Couleur.h"
#include "../include/Rook.h"
#include "../include/Pawn.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include "../include/Jeu.h"

int main() {
    Jeu jeu;
    jeu.affiche();
    jeu.coup();
    return 0;
}
