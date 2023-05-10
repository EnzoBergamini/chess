/**
 * @file Bishop.h
 *
 * @brief Gestion de la piece fou
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_BISHOP_H
#define ECHEC_BISHOP_H

#include "Piece.h"
#include "Couleur.h"
#include "Square.h"

/**
 * @class Bishop
 * @inherit Piece
 *
 * @brief Gestion du fou du jeu d'échecs
*/

class Bishop : public Piece{
public:
    /**
     * @brief Constructeur de la classe Bishop
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Bishop(Couleur c,int id,Square pos);

    bool isLegalMove(Square dest, bool isCatch = false);

};


#endif //ECHEC_BISHOP_H
