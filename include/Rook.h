/**
 * @file Rook.h
 *
 * @brief Gestion de la piece tour
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_ROOK_H
#define ECHEC_ROOK_H

#include "Piece.h"
#include "Couleur.h"

/**
 * @class Rook
 * @inherit Piece
 *
 * @brief Gestion de la tour du jeu d'échecs
*/

class Rook : public Piece{
public:
    /**
     * @brief Constructeur de la classe Rook
     * @param color Couleur de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Rook(Couleur color,int id, Square pos);

    bool isLegalMove(Square dest, bool isCatch = false) const;

};


#endif //ECHEC_ROOK_H
