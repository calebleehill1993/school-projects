/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: defines the functions for the Lexer
includes a vector of tokens,
*/


#pragma once
#include <string>
#include <fstream>
#include <map>
#include "Token.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Lexer
{

protected:
  ifstream inFile;
  string currentString;
  int currentLine = 1;
  int lineNumHolder = 0;
  vector<Token> tokenList;
  char current;
  char next;
  bool undefinedStringOrComment;


public:
  Lexer(){}

  ~Lexer(){}

  void scanner(string fileName);
  bool findWhitespace();
  tokenType simplePunct();
  tokenType colonDash();
  tokenType findStrings();
  tokenType findComments();
  tokenType findIDs();
  bool isSchemes();
  bool isFacts();
  bool isRules();
  bool isQueries();
  bool checkIfLine();
  string enumToString(tokenType someEnum);
  string getTokenList();
};
