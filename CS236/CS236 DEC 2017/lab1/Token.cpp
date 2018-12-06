/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: implements the functions in token, essentially just outputs the data members that are contained in token.
*/


#include "Token.h"

using namespace std;

string Token::getString() {
  return stringFromFile;
}

int Token::getLine() {
  return lineNum;
}

tokenType Token::getTokenType() {
  return myToken;
}
