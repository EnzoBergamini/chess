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

void Piece::affiche(){
    cout << name;
}

Square Piece::getSquare() {
    return this->position;
}

void Piece::setSquare(Square pos){
    this->position = pos;
}
