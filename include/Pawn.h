/**
 * @file Piece.h
 *
 * @brief Gestion de la piece pion
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/


#ifndef ECHEC_PAWN_H
#define ECHEC_PAWN_H

#include "Piece.h"
#include "Square.h"
#include "Couleur.h"

/**
 * @class Pawn
 * @inherit Piece
 *
 * @brief Gestion du pion du jeu d'échecs
*/

class Pawn : public Piece{
public:
    /**
     * @brief Constructeur de la classe Pawn
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Pawn(Couleur color, int id, Square pos);

    /**
     * @brief Permet de savoir si le mouvement et legal
     * @param dest case de destination
     * @param isCatch Booleen qui permet de savoir si ont est en position de catch (cas special pour le pion)
     */
    bool isLegalMove(Square dest, bool isCatch = false) const;
};


#endif //ECHEC_PAWN_H
