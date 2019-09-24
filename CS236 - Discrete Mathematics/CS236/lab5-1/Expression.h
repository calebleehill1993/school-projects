/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores an Expression
Inputs: uses a passed in string in the constructor
Outputs: return a string
*/


#pragma once
#include "Parameter.h"

using namespace std;

class Expression : public Parameter
{
protected:
public:
    Expression(string expression) {
        this->aToken = Token(expression, -1, MULTIPLY);
    }
    ~Expression(){}
    string getExpression() {
        return aToken.getString();
    }
};
