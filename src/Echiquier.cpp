//
// Created by Enzo Bergamini on 24/04/2023.
//

#include "../include/Echiquier.h"


#define BOARD_SIZE 8

void Echiquier::allocMemEchiquier(){
    this->echiquier = new Piece**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i) {
        this->echiquier[i] = new Piece*[BOARD_SIZE];
    }
}

void Echiquier::initEchiquier(){
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            this->echiquier[i][j] = nullptr;
        }
    }
}

void Echiquier::posePiece(Piece *p, Square pos) {
    if(p != nullptr){
        p->setSquare(pos);
        this->echiquier[pos.getLine()][pos.getColumn()] = p;
    }else{
        this->echiquier[pos.getLine()][pos.getColumn()] = nullptr;
    }
}

Echiquier::Echiquier(){

    this->allocMemEchiquier();

    this->initEchiquier();

    pieces[white] = {
            new Rook    (white,  0, Square(0,0)),
            new Knight(white,  1, Square(0,1)),
            new Bishop     (white,  2, Square(0,2)),
            new Queen    (white,  3, Square(0,3)),
            new King     (white,  4, Square(0,4)),
            new Bishop     (white,  5, Square(0,5)),
            new Knight(white,  6, Square(0,6)),
            new Rook    (white,  7, Square(0,7))
    };

    pieces[black] = {
            new Rook    (black,  8, Square(7,0)),
            new Knight(black,  9, Square(7,1)),
            new Bishop     (black, 10, Square(7,2)),
            new Queen    (black, 11, Square(7,3)),
            new King     (black, 12, Square(7,4)),
            new Bishop     (black, 13, Square(7,5)),
            new Knight(black, 14, Square(7,6)),
            new Rook    (black, 15, Square(7,7)),
    };

    for (size_t i=0;i<8;i++) {
        pieces[white].push_back(new Pawn(white, 16+i, Square(1,i)));
        pieces[black].push_back(new Pawn(black, 24+i, Square(6,i)));
    }

    for (auto p : pieces[white])
        this->posePiece(p, p->getSquare());
    for (auto p : pieces[black])
        this->posePiece(p, p->getSquare());

}

Echiquier::~Echiquier(){
    for (auto& p : pieces[white])
        delete p;
    for (auto& p : pieces[black])
        delete p;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        delete[] this->echiquier[i];
    }
    delete[] this->echiquier;
}

void Echiquier::affiche() {
    string space5 = string(5,' ');
    cout << endl;
    cout << "     a     b     c     d     e     f     g     h    "<< endl;
    cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    for (int i(BOARD_SIZE-1);i>=0;i--) {
        cout << i+1 << " "; // numérotation ligne dans affichage
        for (int j(0);j<BOARD_SIZE;j++) {
            cout << "|" ;
//            cout << "\u0020\u0020";
//            cout << i << "/" << j;
//            cout << "\u0020" << " ";
            if (echiquier[i][j]) {
                cout << "\u0020\u0020";  //U+0020 est un esapce utf-8 taille police
                echiquier[i][j]->affiche();
                cout << "\u0020" << " ";
            }
            else
                cout << space5;  // 2 ascii spaces
        }
        cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
        cout << endl;
    }
}

void Echiquier::movePiece(Square pos_start, Square pos_end){
    Piece *tmp_piece = this->echiquier[pos_start.getLine()][pos_start.getColumn()];
    this->posePiece(nullptr, pos_start);
    this->posePiece(tmp_piece, pos_end);
}

Piece *Echiquier::getPiece(Square pos){
    return this->echiquier[pos.getLine()][pos.getColumn()];
}