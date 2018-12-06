/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Child class of Predicate, stores a vector of Parameters.
Inputs: A Parameter via the constructor
Outputs: the Id and the vector of Parameter as a string. Returns the Id via the getPredicateId function and the vector of Parameter via the getParameters function.
*/

#pragma once
#include "Predicate.h"

using namespace std;

class Query : public Predicate
{
protected:

public:
    Query(Predicate predicate){
        this->predicateID = predicate.getPredicateId();
        this->parameters = predicate.getParameters();
    }
    Query(){}
    ~Query(){}
};
