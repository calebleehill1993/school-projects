/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores an Id and a vector of Strings.
Inputs: takes a passed in Id in the constructor, adds a passed in String in the addString function.
Outputs: outputs the Id and the vector of strings as a string.
*/



#pragma once
#include <vector>
#include <algorithm>
#include "String.h"
#include "Id.h"

using namespace std;

class Fact
{
protected:
    Id id;
    vector<string> factStrings;
public:
    Fact(){}
    ~Fact(){}
    void setString(Id id) {
        this->id = id;
    }
    void addString(string inString) {
        factStrings.push_back(inString);
    }
    string toString() {
        stringstream ss;
        ss << id.toString() << "(" << factStrings.at(0);
        for (int i = 1; i < factStrings.size(); i++) {
            ss << "," << factStrings.at(i);
        }
        ss << ").";
        return ss.str();
    }

    vector<string> getVector(){
      return factStrings;
    }

    string getID(){
      return id.toString();
    }

};
