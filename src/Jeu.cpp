//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Jeu.h"

#include <regex>

Jeu::Jeu() : chessboard(new Echiquier()), current_player(white) {}

Jeu::~Jeu() {
    cout << this->chessboard->canonicalPosition() << endl;
    delete chessboard;
}

void Jeu::affiche() {
    chessboard->affiche();
}

bool isLegalInput(string const & input){
    regex pattern("([a-h][1-8][a-h][1-8])|(/quit)|(/draw)|(resign)");
    return regex_match(input, pattern);
}

bool Jeu::coup() {
    string input;
    bool stop = false;

    cout << "C'est au joueur " << ((current_player == white) ? "blanc" : "noir") << " de jouer" << endl;

    do {
        cout << "Coup ? (eg a2a3) ";
        getline(cin, input);

        while (!isLegalInput(input)) {
            cout << "L'input n'est pas valide" << endl;
            cout << "Coup ? (eg a2a3) " << endl;
            getline(cin, input);
        }

        if (input == "/quit"){
            return false;
        } else if (input == "/draw"){
            cout << "Match nul" << endl;
            return false;
        } else if (input == "/resign") {
            cout << "Vous avez abandonné" << endl;
            return false;
        }


        stop = this->movePiece(Square(input.substr(0,2)),
                               Square(input.substr(2,2))
                               );

    } while (!stop);

    cout << "-> Déplacement " << this->chessboard->getPiece(Square(input.substr(2,2)))->getName() << " en " << input << endl;

    this->current_player = (this->current_player == white) ? black : white;

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

    /*===== Vérification si la piece existe ======*/
    if (moving_piece == nullptr){
        cout << "Il n'y a pas de piece a cette position" << endl;
        return false;
    }

    if (moving_piece->getColor() != current_player){
        cout << "Ce n'est pas votre piece !" << endl;
        return false;
    }

    const char *class_name = typeid(*moving_piece).name() + 1;

    /*===== Vérification de la validité des coups ======*/
    if (destination_piece != nullptr){
        if (destination_piece->getColor() != moving_piece->getColor()){
            if (strcmp(class_name, "Pawn") == 0){
                if (!moving_piece->isLegalMove(end, true)) {
                    cout << "Le coup n'est pas valide" << endl;
                    return false;
                }
            }else{
                if (!moving_piece->isLegalMove(end)) {
                    cout << "Le coup n'est pas valide" << endl;
                    return false;
                }
            }
        } else{
            cout << "Il y a deja une piece de la meme couleur a cette position" << endl;
            return false;
        }
    }else{
        if (!moving_piece->isLegalMove(end)) {
            cout << "Le coup n'est pas valide" << endl;
            return false;
        }
    }

    /*===== Vérification si le chemin est libre ======*/

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

    this->chessboard->movePiece(start, end);
    moving_piece->incrementMoveCount();

    return true;
}


void Jeu::setPlayer(Couleur c){
    this->current_player = c;
}

Couleur Jeu::getPlayer(){
    return this->current_player;
}