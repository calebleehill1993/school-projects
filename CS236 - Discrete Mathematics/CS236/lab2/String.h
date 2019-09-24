/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: holds a string.
Inputs: a Token via the constructor
Outputs: a string via the toString function.
*/


#pragma once
#include "Parameter.h"

using namespace std;

class String : public Parameter
{
protected:
    string myString;
public:
    String(Token someToken) : Parameter(someToken){
        myString = someToken.getString();
    }
    String(){}
    ~String(){}
    string toString() {
        return myString;
    }
};
