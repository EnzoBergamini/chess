//
// Created bline Enzo Bergamini on 24/04/2023.
//

#ifndef ECHEC_SQUARE_H
#define ECHEC_SQUARE_H

#include <string>
#include <vector>

using namespace std;


class Square {
private:
    int line;
    int column;

public:
    Square(string coord);

    Square(int line, int column);

    int getLine() const;

    int getColumn() const;

    void display();

    bool operator==(const Square &other) const;
};



#endif //ECHEC_SQUARE_H
