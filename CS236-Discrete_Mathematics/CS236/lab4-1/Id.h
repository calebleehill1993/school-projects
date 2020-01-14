/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a string
Inputs: uses a passed in Token in the constructor.
Outputs: returns the Id as a string.
*/




#pragma once
#include "Parameter.h"

using namespace std;

class Id : public Parameter
{
protected:
    string id;
public:
    Id(Token someToken) : Parameter(someToken) {
        id = someToken.getString();
    }
    Id(){}
    ~Id(){}

    string toString() {
        return id;
    }
};
