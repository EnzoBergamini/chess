/**
 * @file Square.h
 *
 * @brief Gestion des cases du jeu d'échecs
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_SQUARE_H
#define ECHEC_SQUARE_H

#include <string>
#include <vector>

/**
 * @class Square
 *
 * @brief Gestion des coordonnées des cases du jeu d'échecs
*/

using namespace std;

class Square {
private:
    int line; /** < Ligne de la case */

    int column; /** < Colonne de la case */

public:
    /**
     * @brief Constructeur de la classe Square
     * @param coord Coordonnées de la case en notation algébrique (ex: "a1")
     */
    Square(string coord);

    /**
     * @brief Constructeur de la classe Square
     * @param line Ligne de la case
     * @param column Colonne de la case
     */
    Square(int line, int column);

    /**
     * @brief Renvoie la ligne de la case
     */
    int getLine() const;

    /**
     * @brief Renvoie la colonne de la case
     */
    int getColumn() const;

    /**
     * @brief Affiche les coordonnées de la case
     */
    void display();

    /**
     * @brief Surcharge de l'opérateur ==
     * @param other Case à comparer
     * @return true si les cases sont égales, false sinon
     */
    bool operator==(const Square &other) const;
};



#endif //ECHEC_SQUARE_H
