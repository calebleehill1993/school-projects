/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a character and an operatorType
Inputs: Takes a token in the constructor
Outputs: None
*/


#pragma once
#include "Token.h"

enum operatorType {
    ADD,
    MULTIPLY
};

class Operator
{
protected:
    char myOpChar;
    operatorType myOperator;
public:
    Operator(tokenType token){
        myOpChar = token.getString();
        myOperator = token.getTokenType();
    }
    ~Operator(){}
};
