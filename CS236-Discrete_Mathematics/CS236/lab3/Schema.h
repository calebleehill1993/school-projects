/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a vector of strings
Inputs: takes a string and stores it in the vectore
Outputs: the vector that is stored.
*/


#pragma once
#include <vector>
#include <string>

using namespace std;

class Schema {
protected:
  vector <string> schema;
public:
  Schema(vector<string> schema){
    this->schema = schema;
  }
  Schema(){}
  ~Schema(){}

  string toString() {
    stringstream ss;
    for (int i = 0; i < schema.size(); i++) {
      ss << schema.at(i) << " ";
    }
    return ss.str();
  }

  void setAt(int index, string set) {
    schema.at(index) = set;
  }
  int size() {
    return schema.size();
  }
  vector<string> getVector() {
    return schema;
  }
  void insert(string s) {
    schema.push_back(s);
  }


};
