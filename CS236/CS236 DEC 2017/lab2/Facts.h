/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a vector of Fact
Inputs: uses a passed in Fact in the addToVector function
Outputs: returns the vector of Fact as a string.
*/
#pragma once
#include "Fact.h"

using namespace std;

class Facts
{
protected:
  vector<Fact> facts;
  Fact currentFact;
public:
  Facts(){}
  ~Facts(){}
  void addToVector(Fact fact) {
    facts.push_back(fact);
  }
  string toString() {
    stringstream ss;
    ss << "Facts(" << facts.size() << "):" << endl;
    for (int i = 0; i < facts.size(); i++) {
      ss << "  " << facts.at(i).toString() << endl;
    }
    return ss.str();
  }
};
