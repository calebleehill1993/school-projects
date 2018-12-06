/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: inherits from a vector of strings.
Inputs: takes a vector of strings and stores it as the tuple.
*/


#pragma once
#include <sstream>
#include <vector>
#include <sstream>
#include <string>
#include "String.h"

using namespace std;

class Tuple : public vector<string>
{
protected:
public:
  Tuple(){}
  ~Tuple(){}
  void set(vector<string> addTuple) {
    for(auto i:addTuple) {
      this->push_back(i);
    }
  }
};
