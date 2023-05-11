/**
 * @file King.h
 *
 * @brief Gestion de la piece roi
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_KING_H
#define ECHEC_KING_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

#include <iostream>

/**
 * @class King
 * @inherit Piece
 *
 * @brief Gestion du roi du jeu d'échecs
*/

using namespace std;

class King : public Piece{
public:
    /**
     * @brief Constructeur de la classe King
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    King(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest, bool isCatch = false) const;
};


#endif //ECHEC_KING_H
