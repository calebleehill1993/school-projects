/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: implements the functions in token, essentially just outputs the data members that are contained in token.
*/


#include "Token.h"

string &Token::getString() {
  return stringFromFile;
}

int Token::getLine() {
  return lineNum;
}

tokenType Token::getTokenType() {
  return myToken;
}

string Token::enumToString(tokenType someEnum) {
  switch (someEnum) {
    case COMMA :
    return "COMMA";
    case PERIOD :
    return "PERIOD";
    case Q_MARK :
    return "Q_MARK";
    case LEFT_PAREN :
    return "LEFT_PAREN";
    case RIGHT_PAREN :
    return "RIGHT_PAREN";
    case COLON :
    return "COLON";
    case COLON_DASH :
    return "COLON_DASH";
    case MULTIPLY :
    return "MULTIPLY";
    case ADD :
    return "ADD";
    case SCHEMES :
    return "SCHEMES";
    case FACTS :
    return "FACTS";
    case RULES :
    return "RULES";
    case QUERIES :
    return "QUERIES";
    case ID :
    return "ID";
    case STRING :
    return "STRING";
    case COMMENT :
    return "COMMENT";
    case WHITESPACE :
    return "WHITESPACE";
    case UNDEFINED :
    return "UNDEFINED";
    case END_OF_FILE :
    return "EOF";
    default :
    return "FAILED TO DEFAULT";
  }
}

string Token::toString() {
  stringstream ss;
  ss << "("  << enumToString(getTokenType()) << ",\"" << getString() << "\"," << getLine() << ")" << endl;
  string temp = ss.str();
  return temp;
}
