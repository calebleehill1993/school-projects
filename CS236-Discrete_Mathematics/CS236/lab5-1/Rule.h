/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a Predicate and a vector of Predicate
Inputs: a Predicate via the setHead or addPredicate functions
Outputs: both the Predicate and the vector of Predicate as a string via the toString function.
*/


#pragma once
#include "Predicate.h"

using namespace std;

class Rule
{
protected:
    Predicate headPredicate;
    vector<Predicate> predicates;
public:
    Rule(){}
    ~Rule(){}
    void setHead(Predicate predicate) {
        headPredicate = predicate;
    }
    void addPredicate(Predicate predicate) {
        predicates.push_back(predicate);
    }
    string toString() {
        stringstream ss;
        ss << "  " << headPredicate.toString() << " :- " << predicates.at(0).toString();
        for (int i = 1; i < predicates.size(); i++) {
            ss << "," << predicates.at(i).toString();
        }
        ss << "." << endl;
        return ss.str();
    }
    vector<Predicate> &getPredicates() {
        return predicates;
    }
    Predicate &getHead() {
        return headPredicate;
    }
    string &getHeadString() {
        return headPredicate.getPredicateIdString();
    }
};
