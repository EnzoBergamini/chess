/**
 * @file Input.h
 *
 * @brief Gestion des entrées utilisateur
 *
 * Utilisation des expression "regex" pour vérifier la validité des entrées utilisateur.
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

#ifndef ECHEC_INPUT_H
#define ECHEC_INPUT_H

#include <regex>
#include <string>

using namespace std;

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format de promotion de la reine.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion de la reine, sinon
 */
bool isValidQueenPromotion(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format de promotion de la tour.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion de la tour, sinon False.
 */
bool isValidRookPromotion(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format de promotion du fou.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion du fou, sinon False.
 */
bool isValidBishopPromotion(string const & input);

/**
 * @brief si la chaîne de caractères d'entrée correspond au format de promotion du cavalier.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion du cavalier, sinon False.
 */
bool isValidKnightPromotion(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format d'un coup valide.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isValidMoveInput(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format d'un petit roque.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isValidSmallRookMove(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond au format d'un grand roque.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isValidBigRookMove(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond a l'instruction de quitter.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isQuitInput(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond a l'instruction de demander un match nul.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isDrawInput(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond a l'instruction d'abandonner.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isResignInput(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond a un format valide.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isValidInput(string const & input);

/**
 * @brief Vérifie si la chaîne de caractères d'entrée correspond a un format de promotion valide.
 *
 * @param input Chaîne de caractères à vérifier.
 * @return True si la chaîne de caractères correspond au format de promotion, sinon False.
 */
bool isValidPromotion(string const & input);

#endif //ECHEC_INPUT_H
