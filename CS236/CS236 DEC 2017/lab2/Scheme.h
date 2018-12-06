/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: holds an Id and a vector of Id
Inputs: an Id passed in via the addId function
Outputs: the Id and the vector of Id as a string via the toString function.
*/

#pragma once
#include "Id.h"

using namespace std;

class Scheme
{

protected:
    Id id;
    vector<Id> ids;
public:
    Scheme(){}
    ~Scheme(){}
    string toString() {
        stringstream ss;
        ss << id.toString() << "(" << ids.at(0).toString();
        for (int i = 1; i < ids.size(); i++) {
            ss << "," << ids.at(i).toString();
        }
        ss << ")";
        return ss.str();
    }
    void setId(Id id) {
        this->id = id;
    }
    void addId(Id id) {
        ids.push_back(id);
    }
};
