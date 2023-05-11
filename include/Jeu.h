/**
 * @file Jeu.h
 *
 * @brief Gestion de l'architecture du jeu d'échecs
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "Echiquier.h"
#include "Couleur.h"

#include <iostream>
#include <string>

/**
 * @class Jeu
 *
 * @brief Gestion de l'architecture du jeu d'échecs
*/

using namespace std;


class Jeu {
private:
    Echiquier *chessboard; /** < Pointeur sur l'échiquier */

    Couleur current_player; /** < Couleur du joueur courant */

    string last_move; /** < Dernier coup joué */
public:
    /**
     * @brief Constructeur de la classe Jeu
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu
     */
    ~Jeu();

    /**
     * @brief Affiche l'échiquier
     */
    void affiche();

    /**
     * @brief Affiche un message de fin de partie avec le résultat et arrête le jeu.
     *
     * Affiche la position finale de l'échiquier et le résultat de la partie.
     * le résultat est donné sous la forme d'une chaîne de caractères:
     * - "1-0" si les blancs ont gagné
     * - "0-1" si les noirs ont gagné
     * - "1/2-1/2" si la partie est nulle
     * - "?-?" si la partie est arrêtée avant la fin
     * et la position finale de l'échiquier est donnée sous forme canonique:
     * -"wR,wN,,wQ,wK,wB,wN,wR,wP,wP,wP,,wP,wP,wP,wP,,,,,,,,,,,,wP,,,,wB,,,,bP,,bB,,,,,,,,bP,,,bP,bP,bP,,bP,,bP,bP,bR,bN,,bQ,bK,bB,bN,bR,"
     *
     * @param result Résultat de la partie
     */
    void displayEndGame(string result);

    /**
     * @brief Déplace une pièce d'une case de départ à une case d'arrivée sur l'échiquier.
     *
     * Cette méthode déplace une pièce sur l'échiquier en effectuant les vérifications suivantes :
     * - La pièce à déplacer existe-t-elle sur la case de départ ?
     * - La pièce à déplacer appartient-elle au joueur courant ?
     * - Le mouvement est-il valide pour ce type de pièce ?
     * - Le chemin est-il libre (sauf si isPassingThroughAllowed est vrai) ?
     * - Le mouvement ne met-il pas le joueur en échec ?
     * - Le mouvement est-il une prise en passant ?
     * - Le mouvement implique t-il une promotion ?
     *
     * Si toutes les conditions sont remplies, la méthode effectue le déplacement et vérifie s'il y a une prise en passant
     * ou une promotion à réaliser.
     *
     * @param start La case de départ de la pièce à déplacer.
     * @param end La case d'arrivée de la pièce.
     * @param isPassingThroughAllowed Indique si le passage à travers d'autres pièces est autorisé.
     * @return Retourne true si le déplacement est réussi, sinon false.
     */
    bool movePiece(Square start, Square end, bool isPassingThroughAllowed = false);

    /**
     * @brief cette fonction permet de gérer les coups des joueurs en alternance.
     *
     * Elle affiche un message indiquant à quel joueur il est de jouer.
     * Elle demande à l'utilisateur de saisir une chaîne de caractères représentant un coup valide.
     * Elle vérifie que la saisie est valide et effectue le coup demandé en utilisant les méthodes appropriées de la classe Jeu.
     * Si le roi du joueur qui vient de jouer est en échec, elle affiche un message et permet à ce joueur de saisir un autre coup valide.
     * Si l'utilisateur saisit "quit", elle affiche un message de fin de partie avec le résultat "?-?" et retourne false pour arrêter le jeu.
     * Si l'utilisateur saisit "draw", elle affiche un message de fin de partie avec le résultat "1/2-1/2" et retourne false pour arrêter le jeu.
     * Si l'utilisateur saisit "resign", elle affiche un message de fin de partie avec le résultat approprié en fonction du joueur qui a abandonné et retourne false pour arrêter le jeu.
     * Si l'utilisateur saisit un coup de roque petit ou grand valide, elle effectue ce coup en utilisant les méthodes appropriées de la classe Jeu.
     *
     * @return true si le coup a été joué, false si le coup n'a pas été joué (fin de partie ou saisie invalide)
     */
    bool coup();

    /*======================== Vérifications ========================*/

    /**
     * @brief Vérifie si le chemin entre deux cases est libre de toute pièce
     * Cette méthode vérifie si le chemin entre la case de départ et la case d'arrivée est libre de toute pièce.
     * Si le chemin est libre, la méthode renvoie true, sinon elle renvoie false.
     *
     * @param start La case de départ du chemin
     * @param end La case d'arrivée du chemin
     * @return true si le chemin est libre de toute pièce, false sinon
    */
    bool isPathClear(Square start, Square end);

    /**
     * @brief Vérifie si le roi du joueur de la couleur donnée est en échec.
     *
     * @param c Couleur du joueur
     * @return true si le roi est en échec, false sinon
     */
    bool isKingInCheck(Couleur c);

    /**
     * @brief Vérifie si une piece a une position donnée est capturable.
     *
     * @param square position de la piece pour laquelle on veut savoir si elle est capturable
     * @param c couleur de la piece pour laquelle on veut savoir si elle est capturable
     * @return true si la piece est capturable, false sinon
     */
    bool isCapturable(Square square, Couleur c);

    /**
     * @brief Vérifie si le mouvement d'une piece (le roi) va le mettre en échec.
     *
     * @param start position de la piece avant le mouvement
     * @param end position de la piece apres le mouvement
     * @param c couleur de la piece
     *
     * @return true si le mouvement met le roi en échec, false sinon
     */
    bool isCheckMove(Square start, Square end ,Couleur c);

    /**
     * @brief Vérifie si le mouvement est un petit roque.
     *
     * @param c couleur du joueur effectuant le roque
     * @return true si le mouvement est un petit roque, false sinon
     */
    bool smallRookMove(Couleur c);

    /**
     * @brief Vérifie si le mouvement est une promotion.
     *
     * @return true si le mouvement est une promotion, false sinon
     */
    bool isPromotion();

    /**
     * @brief Vérifie si le mouvement est un grand roque.
     *
     * @param c couleur du joueur effectuant le roque
     * @return true si le mouvement est un grand roque, false sinon
     */
    bool bigRookMove(Couleur c);

    /**
     * @brief Vérifie si le mouvement est une prise en passant.
     *
     * @param start position de la piece avant le mouvement
     * @param end position de la piece apres le mouvement
     */
    bool isTakingInPassing(Square start, Square end);

    /*======================== SETTERS ========================*/

    /**
     * @brief Affection de la couleur du joueur courant
     *
     * @param c Couleur (blanc ou white)
     */
    void setPlayer(Couleur c);

    /**
     * @brief Affecte la valeur de l'attribut lastMove.
     *
     * @param move le dernier mouvement effectué
     */
    void setLastMove(string move);

    /*======================== GETTERS ========================*/

    /**
     * @brief Récupération de la couleur du joueur courant
     *
     * @return Couleur (blanc ou white)
     */
    Couleur getPlayer();

    /**
     * @brief Récupère la valeur de l'attribut lastMove.
     *
     * @return le dernier mouvement effectué
    */
    string getLastMove();
};


#endif //ECHEC_JEU_H
