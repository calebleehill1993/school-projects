/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a token, acts as a parent class to Id, String, and Expression
Inputs: takes a Token in the constructor
Outputs: returns the Token as a string
*/


#pragma once
#include "Token.h"

using namespace std;

class Parameter
{

protected:
  Token aToken;
public:
  Parameter(Token someToken) {
    aToken = someToken;
  }
  Parameter(){}
  ~Parameter(){}
  virtual string &toString(){
    return aToken.getString();
  }
  Token getToken() {
    return aToken;
  }
};
