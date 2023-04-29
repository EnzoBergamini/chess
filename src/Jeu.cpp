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
        cout << "Coup ? " << endl;
        getline(cin, input);
        cout << input << endl;
    }

    Square start = Square(input.substr(0,2));
    Square end = Square(input.substr(2,2));

    this->movePiece(start, end);
    return true;
}

bool Jeu::movePiece(Square start, Square end) {
    Piece *moving_piece = chessboard->getPiece(start);
    if (moving_piece == nullptr){
        cout << "Il n'y a pas de piece a cette position" << endl;
        return false;
    }else if(!moving_piece->isLegalMove(end)){
        cout << "Le mouvement n'est pas valide" << endl;
        return false;
    }

    Piece *destination_piece = chessboard->getPiece(end);

    if (destination_piece != nullptr){
        if (destination_piece->getColor() == moving_piece->getColor()){
            cout << "Il y a deja une piece de la meme couleur a cette position" << endl;
            return false;
        }
    }
    chessboard->movePiece(start, end);
    return true;
}