//
// Created by Enzo Bergamini on 24/04/2023.
//

#include <iostream>

#include "../include/Square.h"
#include "../include/Piece.h"
#include "../include/Echiquier.h"
#include "../include/Jeu.h"

int main() {
    Jeu jeu;
    bool stop = false;

    do {
        jeu.affiche();
        stop = jeu.coup();
    } while (stop);
    return 0;
}
