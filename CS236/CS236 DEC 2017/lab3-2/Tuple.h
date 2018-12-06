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
  void reverse() {
    std::reverse(this->begin(), this->end());
  }
};
