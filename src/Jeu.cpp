//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Jeu.h"
#include <regex>
#include <typeindex>

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
        cout << "L'input n'est pas valide'" << endl;
        cout << "Coup ? " << endl;
        getline(cin, input);
        cout << input << endl;
    }

    Square start = Square(input.substr(0,2));
    Square end = Square(input.substr(2,2));

    this->movePiece(start, end);
    return true;
}

bool Jeu::isPathClear(Square start, Square end){
    int start_line = start.getLine();
    int start_column = start.getColumn();
    int end_line = end.getLine();
    int end_column = end.getColumn();

    // si le chemin est horizontale
    if (start_line == end_line){
        int line = start_line;
        if (start_column < end_column){
            for (int i = start_column + 1 ; i < end_column ; ++i) {
                if (this->chessboard->getPiece(Square(line, i)) != nullptr){
                    return false;
                }
            }
        }else{
            for (int i = end_column + 1 ; i < start_column ; ++i) {
                if (this->chessboard->getPiece(Square(line, i)) != nullptr){
                    return false;
                }
            }
        }
    }

    // si le chemin est verticale
    if (start_column == end_column){
        int column = start_column;
        if (start_line < end_line){
            for (int i = start_line + 1 ; i < end_line ; ++i) {
                if (this->chessboard->getPiece(Square(i, column)) != nullptr){
                    return false;
                }
            }
        }else{
            for (int i = end_line + 1 ; i < start_line ; ++i) {
                if (this->chessboard->getPiece(Square(i, column)) != nullptr){
                    return false;
                }
            }
        }
    }

    // si le chemin est diagonal
    if (abs(start_line - end_line) == abs(start_column - end_column)){
        int line = start_line;
        int column = start_column;
        if (start_line < end_line){
            if (start_column < end_column){
                for (int i = start_line + 1 ; i < end_line ; ++i) {
                    ++line;
                    ++column;
                    if (this->chessboard->getPiece(Square(line, column)) != nullptr){
                        return false;
                    }
                }
            }else{
                for (int i = start_line + 1 ; i < end_line ; ++i) {
                    ++line;
                    --column;
                    if (this->chessboard->getPiece(Square(line, column)) != nullptr){
                        return false;
                    }
                }
            }
        }else{
            if (start_column < end_column){
                for (int i = end_line + 1 ; i < start_line ; ++i) {
                    --line;
                    ++column;
                    if (this->chessboard->getPiece(Square(line, column)) != nullptr){
                        return false;
                    }
                }
            }else{
                for (int i = end_line + 1 ; i < start_line ; ++i) {
                    --line;
                    --column;
                    if (this->chessboard->getPiece(Square(line, column)) != nullptr){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Jeu::movePiece(Square start, Square end) {
    Piece *moving_piece = chessboard->getPiece(start);
    Piece *destination_piece = chessboard->getPiece(end);

    if (moving_piece == nullptr){
        cout << "Il n'y a pas de piece a cette position" << endl;
        return false;
    }else if(!moving_piece->isLegalMove(end)){
        cout << "Le mouvement n'est pas valide" << endl;
        return false;
    }

    const char *class_name = typeid(*moving_piece).name() + 1;
    cout << class_name << endl;

    if (strcmp(class_name, "Pawn") == 0
        || strcmp(class_name, "King") == 0
        || strcmp(class_name, "Queen") == 0
        || strcmp(class_name, "Bishop") == 0
        || strcmp(class_name, "Rook") == 0){ // si la piece est un pion, un roi, une reine, un fou ou une tour (ne peut pas sauter par dessus les autres pieces)

        if (!this->isPathClear(start, end)){
            cout << "Le chemin n'est pas libre" << endl;
            return false;
        }
    }

    if (destination_piece != nullptr){
        if (destination_piece->getColor() == moving_piece->getColor()){
            cout << "Il y a deja une piece de la meme couleur a cette position" << endl;
            return false;
        } else{
            chessboard->movePiece(start, end);
            return true;
        }
    }else{
        chessboard->movePiece(start, end);
        return true;
    }
}