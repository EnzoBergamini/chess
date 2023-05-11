/** @mainpage Document d'information
 *
 * @section Résumé_général Résumé général
 * Ce document d'information a pour but de présenter le projet programmation
 * sur le projet jeu d'échecs.
 *
 * @section Section_introduction Introduction
 * Ce projet est un projet de programmation en c++, pour le cours de programmation orienté objet à Telecom Physique Strasbourg.
 * Le but de ce projet est de faire un jeu d'échecs en c++.
 *
 * @version 1.0
 * @author BERGAMINI Enzo
 * @date 11/05/2023
 *
 */

#include <iostream>

#include "../include/Square.h"
#include "../include/Piece.h"
#include "../include/Echiquier.h"
#include "../include/Jeu.h"

int main() {
    Jeu jeu;
    bool stop;

    do {
        jeu.affiche();
        stop = jeu.coup();
    } while (stop);
    return 0;
}
