/**
 * @file Piece.cpp
 *
 * @author BERGAMINI Enzo
 * @date 11/05/2023
*/
#include <iostream>

#include "../include/Piece.h"
#include "../include/Square.h"
#include "../include/Couleur.h"

using namespace std;

Piece::Piece(Couleur c,string name,int id, Square position)
    : id(id), name(name), couleur(c), position(position), move_count(0), is_catch(false){}

Piece::~Piece(){}

void Piece::affiche(){
    cout << name;
}

Square Piece::getSquare() const{
    return this->position;
}

Couleur Piece::getColor() const{
    return this->couleur;
}

string Piece::getName() const{
    return this->name;
}

bool Piece::getCatch() const{
    return this->is_catch;
}

void Piece::setSquare(const Square& pos){
    this->position = pos;
}

void Piece::setCatch(bool isCatch) {
    this->is_catch = isCatch;
}

void Piece::displayInfo(){
    cout << "Piece : " << name << endl;
    cout << "Id : " << id << endl;
    cout << "Couleur : " << couleur << endl;
    cout << "Position : ";
    position.display();
}

bool Piece::isLegalMove(Square dest, bool isCatch) const{
    (void) dest; // Ici pas utilisé
    (void) isCatch; // Ici pas utilisé
    return true;
}

void Piece::incrementMoveCount() {
    this->move_count++;
}

size_t Piece::getMoveCount() const{
    return this->move_count;
}

int Piece::getId() const{
    return this->id;
}

void Piece::setId(int id) {
    this->id = id;
}

void Piece::setMoveCount(size_t count) {
    this->move_count = count;
}

