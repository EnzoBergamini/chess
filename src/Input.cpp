//
// Created by Enzo Bergamini on 11/05/2023.
//

#include "../include/Input.h"


bool isValidQueenPromotion(string const & input){
    regex pattern("(Q|q)\\s*");
    return regex_match(input,pattern);
}

bool isValidRookPromotion(string const & input){
    regex pattern("(R|r)\\s*");
    return regex_match(input,pattern);
}

bool isValidBishopPromotion(string const & input){
    regex pattern("(B|b)\\s*");
    return regex_match(input,pattern);
}

bool isValidKnightPromotion(string const & input){
    regex pattern("(N|n)\\s*");
    return regex_match(input,pattern);
}

bool isValidMoveInput(string const & input) {
    regex mouvmtpattern("[a-h][1-8][a-h][1-8]\\s*");
    return regex_match(input,mouvmtpattern);
}

bool isValidSmallRookMove(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool isValidBigRookMove(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool isQuitInput(string const & input){
    regex pattern("/quit\\s*");
    return regex_match(input,pattern);
}

bool isDrawInput(string const & input){
    regex pattern("/draw\\s*");
    return regex_match(input,pattern);
}


bool isResignInput(string const & input){
    regex pattern("/resign\\s*");
    return regex_match(input,pattern);
}

bool isValidInput(string const & input){
    return isValidMoveInput(input)
           || isValidSmallRookMove(input)
           || isValidBigRookMove(input)
           || isQuitInput(input)
           || isDrawInput(input)
           || isResignInput(input);
}

bool isValidPromotion(string const & input){
    return isValidQueenPromotion(input)
           || isValidRookPromotion(input)
           || isValidBishopPromotion(input)
           || isValidKnightPromotion(input);
}