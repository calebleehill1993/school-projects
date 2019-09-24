/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: stores a vector of Rule
Inputs: a rule passed in via the addToVector function
Outputs: the vector of Rule as a string via the toString function.
*/


#pragma once
#include "Rule.h"

using namespace std;

class Rules
{
protected:
  Rule myRule;
  vector<Rule> rules;
public:
  Rules(){}
  ~Rules(){}
  void addToVector(Rule rule) {
    rules.push_back(rule);
  }
  string toString() {
    stringstream ss;
    ss << "Rules(" << rules.size() << "):" << endl;
    for (unsigned int i = 0; i < rules.size(); i++) {
      ss << rules.at(i).toString();
    }
    return ss.str();
  }
  vector <Rule> &getRules() {
    return rules;
  }
};
