//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Jeu.h"
#include <regex>

Jeu::Jeu() : chessboard(new Echiquier()) {}

Jeu::~Jeu() {
    delete chessboard;
}

void Jeu::affiche() {
    chessboard->affiche();
}

bool isLegalInput(string const & input){
    regex pattern("[a-h][1-8][a-h][1-8]");
    return regex_match(input, pattern);
}

bool Jeu::coup() {
    string input;
    getline(cin, input);
    while (!isLegalInput(input)){
        cout << "La coup n'est pas valide !" << endl;
        cout << "Coup (eg. a1a8) ? " << endl;
        getline(cin, input);
        cout << input << endl;
    }
    chessboard->movePiece(Square(input.substr(0,2)), Square(input.substr(2,2)));
    chessboard->affiche();
    return true;
}