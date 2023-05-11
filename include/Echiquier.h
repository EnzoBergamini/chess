/**
 * @file Echiquier.h
 *
 * @brief Gestion de l'échiquier du jeu d'échecs
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_ECHIQUIER_H
#define ECHEC_ECHIQUIER_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Couleur.h"
#include "Input.h"

#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

/**
 * @class Echiquier
 *
 * @brief Gestion de l'échiquier du jeu d'échecs
*/

using namespace std;

class Echiquier
{
private:
    Piece ***echiquier; /** < Tableau 2D de pointeurs de pièces */

    vector<Piece *> pieces[2];/** < Vecteur de pointeurs des pièces de l'échiquier */
public:
    /**
     * @brief Constructeur de la classe Echiquier et allocation de la mémoire pour les pieces
     */
    Echiquier();

    /**
     * @brief Alloue la mémoire pour l'échiquier
     */
    void allocMemEchiquier();

    /**
     * @brief Destructeur de la classe Echiquier
     */
    ~Echiquier();

    /**
     * @brief Affiche l'échiquier
     */
    void affiche() const;

    /**
     * @brief Pose une pièce p sur l'échiquier a la position pos
     *
     * @param p Pointeur de la pièce à poser
     * @param pos Position de la pièce à poser
     */
    void posePiece(Piece *p, const Square& pos);

    /**
     * @brief Initialise l'échiquier avec des pointeurs null et sue les pièces
     */
    void initEchiquier();

    /**
     * @brief Déplace une pièce sur l'échiquier.
     *
     * Cette fonction déplace une pièce de la position @p pos_start à la position @p pos_end sur l'échiquier.
     * Si une pièce se trouve déjà à la position @p pos_end, elle est capturée.
     *
     * @param pos_start La position de départ de la pièce à déplacer.
     * @param pos_end  La position d'arrivée de la pièce à déplacer.
     */
    void movePiece(const Square& pos_start, const Square& pos_end);

    /**
     * @brief Renvoie le nom PGN de la pièce correspondant à un symbole Unicode donné.
     *
     * Cette fonction prend en entrée un symbole Unicode représentant une pièce d'échecs et renvoie son nom PGN (Portable Game Notation).
     * Le paramètre @p view_pawn permet de contrôler l'affichage ou non du pion, et le paramètre @p view_color permet de contrôler l'affichage ou non de la couleur.
     *
     * @param name Le symbole Unicode représentant la pièce d'échecs.
     * @param view_pawn Un booléen indiquant si le pion doit être affiché ou non.
     * @param view_color Un booléen indiquant si la couleur doit être affichée ou non.
     *
     * @return Le nom PGN de la pièce correspondant au symbole Unicode donné, ou une chaîne vide si le symbole ne correspond à aucune pièce.
     */
    string pgnPieceName(string const name, bool view_pawn, bool view_color) const;

    /**
     * @brief Génère la représentation canonique de la position de l'échiquier.
     *
     * Cette méthode renvoie une chaîne de caractères contenant la représentation
     * canonique de la position actuelle de l'échiquier. Les pièces sont représentées
     * par leur nom en notation PGN, avec les pions indiqués par la lettre "P" et les
     * couleurs par les lettres "w" pour les pièces blanches et "b" pour les pièces
     * noires. Les pièces sont représentées ligne par ligne, en partant de la première
     * rangée jusqu'à la dernière.
     *
     * @return Une chaîne de caractères contenant la représentation canonique de la position.
     */
    string canonicalPosition() const;

    /**
     * @brief Renvoie la case occupée par le roi de la couleur spécifiée.
     *
     * Cette méthode recherche le roi de la couleur spécifiée dans l'échiquier et
     * renvoie la case où il se trouve. Si le roi n'est pas présent sur l'échiquier,
     * une case invalide est renvoyée (avec les coordonnées x et y égales à -1).
     *
     * @param color La couleur du roi recherché (blanc ou noir).
     * @return La case où se trouve le roi de la couleur spécifiée.
     */
    Square getKingSquare(Couleur const color) const;

    /**
     * @brief Renvoi la pièce à la position pos
     * @param pos La position de la pièce
     * @return Le pointeur vers la pièce à la position pos
     */
    Piece *getPiece(const Square& pos) const;

    /*=========  SETTERS  =========*/

    /**
     * @brief Place une pièce à la position spécifiée sur l'échiquier.
     *
     * Cette méthode place la pièce spécifiée à la position spécifiée sur l'échiquier.
     * Si une autre pièce occupait déjà cette position, elle est ecrasée.
     *
     * @param p Un pointeur vers la pièce à placer.
     * @param pos La position où placer la pièce.
     */
    void setPiece(Piece *p, const Square& pos);

    /**
     * @brief Promouvoir un pion en une reine, tour, fou ou cavalier.
     * @param piece Un pointeur vers la pièce pion à promouvoir.
     * @param type Une chaîne de caractères représentant le type de pièce de promotion souhaité (Q, R, B ou N).
     */
    void promote(Piece *p, const string& type);
};

#endif //ECHEC_ECHIQUIER_H
