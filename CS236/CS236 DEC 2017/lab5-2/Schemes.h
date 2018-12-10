/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: holds a vector of Scheme
Inputs: a Scheme via the addToVector function.
Outputs: the vector of Scheme as a string via the toString function.
*/

#pragma once
#include <vector>
#include "Scheme.h"

using namespace std;

class Schemes
{

protected:
  vector<Scheme> schemes;
public:
  Schemes(){}
  ~Schemes(){}
  void addToVector(Scheme scheme) {
    schemes.push_back(scheme);
  }
  string toString() {
    stringstream ss;
    ss << "Schemes(" << schemes.size() << "):" << endl;
    for (unsigned int i = 0; i < schemes.size(); i++) {
        ss << "  " << schemes.at(i).toString() << endl;
    }
    return ss.str();
  } //ss << "Schemes(" << DLPSchemes.size() << "):" << endl iterate through and print all indented with 2 spaces.
  vector<Scheme> getSchemes() {
    return schemes;
  }
};
