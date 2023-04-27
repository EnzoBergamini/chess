//
// Created by Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_SQUARE_H
#define ECHEC_SQUARE_H

#include <string>
#include <vector>


class Square {
private:
    int x;
    int y;
    std::string coord;

public:
    Square(std::string coord);

    Square(int x, int y);

    std::string getCoordString();

    int getLine();

    int getColumn();

};


#endif //ECHEC_SQUARE_H
