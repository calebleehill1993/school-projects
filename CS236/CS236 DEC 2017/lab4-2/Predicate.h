/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores an Id and a vector of Parameter
Inputs: a parameter via the constructor and a string via the setString function.
Outputs: the Id and the vector of Parameter as a string. Returns the Id via the getPredicateId function and the vector of Parameter via the getParameters function.
*/

#pragma once
#include "Parameter.h"

using namespace std;

class Predicate
{

protected:
  Id predicateID;
  vector<Parameter> parameters;

public:
  Predicate(){}
  ~Predicate(){}
  void addParameter(Parameter parameter) {
    parameters.push_back(parameter);
  }
  void setString(string inString) {
    predicateID = Id(inString);
  }
  string toString() {
    stringstream ss;
    ss << predicateID.toString() << "(" << parameters.at(0).toString();
    for (unsigned int i = 1; i < parameters.size(); i++) {
      ss << "," << parameters.at(i).toString();
    }
    ss << ")";
    return ss.str();
  }
  Id getPredicateId() {
    return predicateID;
  }
  vector<Parameter> &getParameters() {
    return parameters;
  }
  string &getPredicateIdString() {
    return predicateID.toString();
  }
};
