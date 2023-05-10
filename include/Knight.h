/**
 * @file Knight.h
 *
 * @brief Gestion de la piece cavalier
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_KNIGHT_H
#define ECHEC_KNIGHT_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

/**
 * @class Knight
 * @inherit Piece
 *
 * @brief Gestion du cavalier du jeu d'échecs
*/

class Knight : public Piece{
public:
    /**
     * @brief Constructeur de la classe Knight
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Knight(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest, bool isCatch = false);
};


#endif //ECHEC_KNIGHT_H
