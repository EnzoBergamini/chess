#ifndef ECHEC_PIECE_H
#define ECHEC_PIECE_H

/**
 * @file Piece.h
 *
 * @brief Gestion des pièces du jeu d'échecs
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#include "Square.h"
#include "Couleur.h"

using namespace std;

/**
 * @class Piece
 *
 * @brief Gestion des pièces du jeu d'échecs
*/

class Piece {
protected:
    int id; /** < Un entier unique pour identifier chaque pièce */

    string name; /** < Nom de la pièce */

    Couleur couleur; /** < Couleur de la pièce */

    Square position; /** < Position de la pièce sur l'échiquier */

    size_t move_count; /** < Nombre de déplacement de la pièce */

    bool is_catch; /** < Booléen pour savoir si la pièce est capturée */

public:
    /**
     * @brief Constructeur de la classe Piece
     * @param c Couleur de la pièce
     * @param name Nom de la pièce
     * @param id Identifiant de la pièce
     * @param position Position de la pièce
     */
    Piece(Couleur c,string name,int id, Square position);

    /**
     * @brief Destructeur de la classe Piece
     */
    virtual ~Piece();

    /**
     * @brief Affiche la nom pièce
     */
    void affiche();

    /**
     * @brief Affiche les informations de la pièce
     */
    void displayInfo();

    /**
     * @brief Incrémente le nombre de déplacement de la pièce
     */
    void incrementMoveCount();

    /**
     * @brief Si le mouvement vers dest est legal pour la piece
     * @param dest La case de destination
     * @param isCatch Booléen pour savoir si la pièce capture une autre pièce
     * @return Le nombre de déplacement de la pièce
     */
    virtual bool isLegalMove(Square dest, bool isCatch = false) const;

    /*=========  GETTERS  =========*/

    /**
     * @brief Renvoie la position de la pièce
     * @return La position de la pièce
     */
    Square getSquare() const;

    /**
     * @brief Renvoie le nom de la pièce
     * @return Le nom de la pièce
     */
    string getName() const;

    /**
     * @brief Renvoie la couleur de la pièce
     * @return La couleur de la pièce
     */
    Couleur getColor() const;

    /**
     * @brief Renvoie l'identifiant de la pièce
     * @return L'identifiant de la pièce
     */
    int getId() const;

    /**
     * @brief Renvoie la valeur de is_catch
     * @return La valeur de is_catch
     */
    bool getCatch() const;

    /**
     * @brief Renvoie le nombre de déplacement de la pièce
     * @return Le nombre de déplacement de la pièce
     */
    size_t getMoveCount() const;

    /*=========  SETTERS  =========*/

    /**
     * @brief Applique sur l'attribut is_catch de la piece la valeur passée en paramètre
     * @param isCatch Nouvelle valeur de is_catch
     */
    void setCatch(bool isCatch);

    /**
     * @brief Applique sur l'attribut move_count de la piece la valeur passée en paramètre
     * @param count Nouvelle valeur de move_count
     */
    void setMoveCount(size_t count);

    /**
     * @brief Applique sur l'attribut id de la piece la valeur passée en paramètre
     * @param id Nouvelle valeur de id
     */
    void setId(int id);

    /**
     * @brief Applique sur l'attribut position de la piece la position passée en paramètre
     * @param pos Nouvelle position de la pièce
     */
    void setSquare(Square& pos);
};

#endif //ECHEC_PIECE_H
