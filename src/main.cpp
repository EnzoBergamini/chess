//
// Created by Enzo Bergamini on 24/04/2023.
//

#include <iostream>

#include "../include/Square.h"
#include "../include/Echiquier.h"

int main() {
    Square square("G2");

    std::cout << "ligne : " << square.getLine() << " colonne : " << square.getColumn() << std::endl;
    return 0;
}
