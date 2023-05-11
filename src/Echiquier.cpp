/**
 * @file Echiquier.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/

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
    }
    this->setPiece(p, pos);
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

void Echiquier::promote(Piece *piece, string type){
    if(isValidQueenPromotion(type)){
        Queen *new_piece = new Queen(piece->getColor(), piece->getId(), piece->getSquare());
        new_piece->setMoveCount(piece->getMoveCount());
        new_piece->setCatch(piece->getCatch());

        replace(pieces[piece->getColor()].begin(), pieces[piece->getColor()].end(), piece, (Piece *)new_piece);

        this->posePiece(new_piece, new_piece->getSquare());

    } else if(isValidRookPromotion(type)){
        Rook *new_piece = new Rook(piece->getColor(), piece->getId(), piece->getSquare());
        new_piece->setMoveCount(piece->getMoveCount());
        new_piece->setCatch(piece->getCatch());

        replace(pieces[piece->getColor()].begin(), pieces[piece->getColor()].end(), piece, (Piece *)new_piece);

        this->posePiece(new_piece, new_piece->getSquare());

    } else if(isValidBishopPromotion(type)){
        Bishop *new_piece = new Bishop(piece->getColor(), piece->getId(), piece->getSquare());
        new_piece->setMoveCount(piece->getMoveCount());
        new_piece->setCatch(piece->getCatch());

        replace(pieces[piece->getColor()].begin(), pieces[piece->getColor()].end(), piece, (Piece *)new_piece);

        this->posePiece(new_piece, new_piece->getSquare());

    } else{
        Knight *new_piece = new Knight(piece->getColor(), piece->getId(), piece->getSquare());
        new_piece->setMoveCount(piece->getMoveCount());
        new_piece->setCatch(piece->getCatch());

        replace(pieces[piece->getColor()].begin(), pieces[piece->getColor()].end(), piece, (Piece *)new_piece);

        this->posePiece(new_piece, new_piece->getSquare());

    }

    delete piece;

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

void Echiquier::movePiece(Square pos_start, Square pos_end) {
    Piece *end_piece = this->getPiece(pos_end);
    if (end_piece != nullptr){
        end_piece->setCatch(true);
    }
    this->posePiece(this->getPiece(pos_start), pos_end);
    this->posePiece(nullptr, pos_start);
}

Piece *Echiquier::getPiece(Square pos){
    return this->echiquier[pos.getLine()][pos.getColumn()];
}

string Echiquier::pgnPieceName(string const name, bool view_pawn, bool view_color){

    string psymb;
    if      (name=="\u2656") psymb="R";  // Rook W
    else if (name=="\u2658") psymb="N";  // Knight W
    else if (name=="\u2657") psymb="B";  // Bishop W
    else if (name=="\u2655") psymb="Q";  // Queen W
    else if (name=="\u2654") psymb="K";  // King W
    else if (name.rfind("\u2659",0)==0 && view_pawn) psymb= "P"; // Pawn W
    if (psymb.size()>0) { // one of the white piece has been found
        if (view_color)
            return "w"+psymb;
        else
            return psymb;
    }
    if      (name=="\u265C") psymb= "R";  // Rook B
    else if (name=="\u265E") psymb= "N";  // Knight B
    else if (name=="\u265D") psymb= "B";  // Bishop B
    else if (name=="\u265B") psymb= "Q";  // Queen B
    else if (name=="\u265A") psymb= "K";  // King B
    else if (name.rfind("\u265F",0)==0 && view_pawn) psymb= "P"; // Pawn B
    if (psymb.size()>0) { // one of the black piece has been found
        if (view_color)
            return "b"+psymb;
        else
            return psymb;
    }
    else return "";
}

string Echiquier::canonicalPosition(){
    string output;
    for (size_t row(1); row<=BOARD_SIZE; row++){
        for (char col('a');col<='h';col++) {
            Square square(col+to_string(row));
            if (this->getPiece(square) != nullptr)
                // get pieces with theit PGN names,
                // true -> with P for pawns, true -> w/b for colors.
                output += pgnPieceName(getPiece(square)->getName(),true,true);
            output += ",";
        }
    }
    return output;
}

Square Echiquier::getKingSquare(Couleur color){
    for (auto p : this->pieces[color])
        if (p->getName() == "\u2654" || p->getName() == "\u265A")
            return p->getSquare();
    return Square(-1,-1);
}

void Echiquier::setPiece(Piece *p, Square pos){
    this->echiquier[pos.getLine()][pos.getColumn()] = p;
}

