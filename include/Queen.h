/**
 * @file Queen.h
 *
 * @brief Gestion de la piece reine
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_QUEEN_H
#define ECHEC_QUEEN_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

/**
 * @class Queen
 * @inherit Piece
 *
 * @brief Gestion de la reine du jeu d'échecs
*/

class Queen : public Piece{
public:
    /**
     * @brief Constructeur de la classe Queen
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Queen(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest, bool isCatch = false) const;
};


#endif //ECHEC_QUEEN_H
