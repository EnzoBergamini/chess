//
// Created by Enzo Bergamini on 24/04/2023.
//

#include <iostream>

#include "../include/Piece.h"
#include "../include/Square.h"
#include "../include/Couleur.h"

using namespace std;

Piece::Piece(Couleur c,string name,int id, Square position)
    : id(id), name(name), couleur(c), position(position){}

Piece::~Piece(){}

void Piece::affiche(){
    cout << name;
}

Square Piece::getSquare() {
    return this->position;
}

void Piece::setSquare(Square pos){
    this->position = pos;
}

void Piece::displayInfo(){
    cout << "Piece : " << name << endl;
    cout << "Id : " << id << endl;
    cout << "Couleur : " << couleur << endl;
    cout << "Position : ";
    position.display();
}

bool Piece::isInBoard(Square dest){
    if (dest.getColumn() < 0 || dest.getColumn() > 7 || dest.getLine() < 0 || dest.getLine() > 7){
        cout << "La case de destination n'est pas sur l'echiquier" << endl;
        return false;
    }
    return true;
}

