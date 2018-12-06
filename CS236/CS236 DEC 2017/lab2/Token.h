/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: defines the functions for Token.
Sets up the enums that will be used to define what a token is. Each token includes a string, and int, and a token type
*/


#pragma once
#include <string>
#include <sstream>

using namespace std;

enum tokenType {
  COMMA,
  PERIOD,
  Q_MARK,
  LEFT_PAREN,
  RIGHT_PAREN,
  COLON,
  COLON_DASH,
  MULTIPLY,
  ADD,
  SCHEMES,
  FACTS,
  RULES,
  QUERIES,
  ID,
  STRING,
  COMMENT,
  WHITESPACE,
  UNDEFINED,
  END_OF_FILE
};


class Token
{
protected:

  string stringFromFile;
  int lineNum;
  tokenType myToken;

public:

  Token(string someString = "", int someInt = 0, tokenType someToken = UNDEFINED){
    stringFromFile = someString;
    lineNum = someInt;
    myToken = someToken;
  }
  ~Token(){}

  string getString();
  int getLine();
  tokenType getTokenType();
  string enumToString(tokenType someEnum);
  string toString();


};
