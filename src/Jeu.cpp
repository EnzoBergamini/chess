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
    if (isLegalInput(input)){
        cout << "l'input est legal : " << input << endl;
    }
    else{
        cout << "l'input n'est pas valide : " << input << endl;
    }
    return true;
}