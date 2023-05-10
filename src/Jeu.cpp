//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Jeu.h"

#include <regex>

#define BOARD_SIZE 8

Jeu::Jeu() : chessboard(new Echiquier()),
current_player(white), last_move("") {}

Jeu::~Jeu() {
    delete chessboard;
}

void Jeu::affiche() {
    chessboard->affiche();
}

bool isValidMoveInput(string const & input) {
    regex mouvmtpattern("[a-h][1-8][a-h][1-8]\\s*");
    return regex_match(input,mouvmtpattern);
}

bool isValidSmallRookMove(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool isValidBigRookMove(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool isQuitInput(string const & input){
    regex pattern("/quit\\s*");
    return regex_match(input,pattern);
}

bool isDrawInput(string const & input){
    regex pattern("/draw\\s*");
    return regex_match(input,pattern);
}

bool isResignInput(string const & input){
    regex pattern("/resign\\s*");
    return regex_match(input,pattern);
}

bool isValidInput(string const & input){
    return isValidMoveInput(input)
        || isValidSmallRookMove(input)
        || isValidBigRookMove(input)
        || isQuitInput(input)
        || isDrawInput(input)
        || isResignInput(input);
}

bool Jeu::coup() {
    string input;
    bool stop = false;

    cout << "C'est au joueur " << ((current_player == white) ? "blanc" : "noir") << " de jouer" << endl;

    do {
        do {
            if (this->isKingInCheck(this->current_player)){
                cout << "Le roi est en échec" << endl;
            }
            getline(cin, input);

            while (!isValidInput(input)) {
                cout << "L'input n'est pas valide" << endl;
                cout << "Coup ? (eg a2a3) " << endl;
                getline(cin, input);
            }

            if (isQuitInput(input)){
                cout << "quit" << endl;
                this->displayEndGame("?-?");
                return false;
            } else if (isDrawInput(input)){
                cout << "draw" << endl;
                this->displayEndGame("1/2-1/2");
                return false;
            } else if (isResignInput(input)) {
                cout << "resign" << endl;
                if (this->getPlayer() == white){
                    this->displayEndGame("0-1");
                }else{
                    this->displayEndGame("1-0");
                }
                return false;
            }else if (isValidSmallRookMove(input)){
                cout << "small rook move" << endl;
                stop = this->smallRookMove(this->current_player);
            }else if (isValidBigRookMove(input)){
                cout << "big rook move" << endl;
            }else{
                cout << "move" << endl;
                stop = this->movePiece(Square(input.substr(0,2)),
                                       Square(input.substr(2,2))
                );
            }

        }while(this->isKingInCheck(this->current_player));

    } while (!stop);

    this->setLastMove(input);

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

bool Jeu::movePiece(Square start, Square end, bool isPassingThroughAllowed) {

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

    /*===== Vérification si c'est une prise en passant ======*/

    if (strcmp(class_name, "Pawn") == 0){
        if (this->isTakingInPassing(start, end)){
            cout << "Prise en passant" << endl;
            this->chessboard->posePiece(nullptr, Square(this->getLastMove().substr(2,2)));
            this->chessboard->movePiece(start, end);
            moving_piece->incrementMoveCount();
            return true;
        }
    }


    /*===== Vérification de la validité des coups ======*/

    if(!(strcmp(class_name, "King") == 0 && isPassingThroughAllowed)){
        if (destination_piece != nullptr){
            if (destination_piece->getColor() != moving_piece->getColor()){
                if (strcmp(class_name, "Pawn") == 0){
                    if (!moving_piece->isLegalMove(end, true)) {
                        cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                        return false;
                    }
                }else{
                    if (!moving_piece->isLegalMove(end)) {
                        cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                        return false;
                    }
                }
            } else{
                cout << "Il y a deja une piece de la meme couleur a cette position" << endl;
                return false;
            }
        }else{
            if (!moving_piece->isLegalMove(end)) {
                cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                return false;
            }
        }
    }

    /*===== Vérification si le chemin est libre ======*/

    if (strcmp(class_name, "Pawn") == 0
        || strcmp(class_name, "King") == 0
        || strcmp(class_name, "Queen") == 0
        || strcmp(class_name, "Bishop") == 0
        || strcmp(class_name, "Rook") == 0){
        if (!this->isPathClear(start, end) && !isPassingThroughAllowed){
            cout << "Le chemin n'est pas libre" << endl;
            return false;
        }
    }

    /*===== Vérification si le joueur se place en echec ======*/

    if (this->isCheckMove(start, end ,this->getPlayer())){
        cout << "Le coup n'est pas valide vous etes en echec" << endl;
        return false;
    }

    this->chessboard->movePiece(start, end);
    moving_piece->incrementMoveCount();

    return true;
}

void Jeu::displayEndGame(string result) {
    cout << this->chessboard->canonicalPosition() << " " << result << endl;
}

bool Jeu::isKingInCheck(Couleur c){
    Square king_square = this->chessboard->getKingSquare(c);
    if (king_square == Square(-1, -1)){
        cerr << "Le roi n'a pas ete trouve" << endl;
        exit(1);
    }

    return this->isCapturable(king_square, c);
}

bool Jeu::isCapturable(Square square, Couleur c){
    for (int i = 0 ; i < BOARD_SIZE ; ++i){
        for (int j = 0 ; j < BOARD_SIZE ; ++j){
            Square current_square(i, j);
            Piece *piece = this->chessboard->getPiece(current_square);
            if (piece != nullptr && piece->getColor() != c){
                if (strcmp(typeid(*piece).name() + 1, "Knight") == 0){
                    if (piece->isLegalMove(square)){
                        return true;
                    }
                }else{
                    if (piece->isLegalMove(square, true)
                        && this->isPathClear(current_square, square)
                    ){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void Jeu::setPlayer(Couleur c){
    this->current_player = c;
}

Couleur Jeu::getPlayer(){
    return this->current_player;
}

bool Jeu::isCheckMove(Square start, Square end ,Couleur c){
    Piece *start_piece = this->chessboard->getPiece(start);
    Piece *end_piece = this->chessboard->getPiece(end);

    this->chessboard->movePiece(start, end);

    if(this->isKingInCheck(c)){
        this->chessboard->posePiece(start_piece, start);
        this->chessboard->posePiece(end_piece, end);
        if (start_piece != nullptr){
            start_piece->setSquare(start);
        }
        if (end_piece != nullptr){
            end_piece->setSquare(end);
        }
        return true;
    }else{
        this->chessboard->posePiece(start_piece, start);
        this->chessboard->posePiece(end_piece, end);
        if (start_piece != nullptr){
            start_piece->setSquare(start);
        }
        if (end_piece != nullptr){
            end_piece->setSquare(end);
        }
        return false;
    }
}

bool Jeu::isTakingInPassing(Square start, Square end){
    if (this->getLastMove().empty() || this->getLastMove().size() < 4){
        return false;
    }
    Square last_move_start = this->getLastMove().substr(0,2);
    Square last_move_end = this->getLastMove().substr(2,2);

    Piece *last_move_piece = this->chessboard->getPiece(last_move_end);

    if (last_move_piece != nullptr && strcmp(typeid(*last_move_piece).name() + 1, "Pawn") == 0){
        if (last_move_piece->getMoveCount() == 1){
            if (last_move_start.getLine() == last_move_end.getLine() + 2
                || last_move_start.getLine() == last_move_end.getLine() - 2){
                if (last_move_piece->getSquare().getColumn() == end.getColumn()
                    && abs(start.getLine() - end.getLine()) == abs(start.getColumn() - end.getColumn()) // si le pion se deplace en diagonale
                    ){
                    return true;
                }
            }
        }
    }

    return false;
}

void Jeu::setLastMove(string move){
    this->last_move = move;
}

string Jeu::getLastMove() {
    return this->last_move;
}

bool Jeu::smallRookMove(Couleur c) {
    if (c == white){
        if(this->isPathClear(Square("e1"), Square("h1" ))
            && this->chessboard->getPiece(Square("e1")) != nullptr
            && this->chessboard->getPiece(Square("h1")) != nullptr
            && this->chessboard->getPiece(Square("e1"))->getMoveCount() == 0
            && this->chessboard->getPiece(Square("h1"))->getMoveCount() == 0){
            if(!this->movePiece(Square("e1"), Square("g1"), true)){
                cout << "Movement du roi impossible" << endl;
                return false;
            }
            this->movePiece(Square("h1"), Square("f1"), true);
            return true;
        }
    }else{
        if(this->isPathClear(Square("e8"), Square("h8" ))
            && this->chessboard->getPiece(Square("e8")) != nullptr
            && this->chessboard->getPiece(Square("h8")) != nullptr
            && this->chessboard->getPiece(Square("e8"))->getMoveCount() == 0
            && this->chessboard->getPiece(Square("h8"))->getMoveCount() == 0){
            if(!this->movePiece(Square("e8"), Square("g8"), true)){
                cout << "Mouvement du roi impossible" << endl;
                return false;
            }
            this->movePiece(Square("h8"), Square("f8"), true);
            return true;
        }
    }

    cout << "Petit roque impossible" << endl;
    return false;
}