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

Couleur Piece::getColor() {
    return this->couleur;
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

bool Piece::isLegalMove(Square dest) {
    return true;
}

