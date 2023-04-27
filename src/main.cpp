//
// Created by Enzo Bergamini on 24/04/2023.
//

#include <iostream>

#include "../include/Square.h"
#include "../include/Piece.h"

int main() {

    Square pos("A6");
    Piece p(white,"pion",1,pos);

    p.affiche();


    return 0;
}
