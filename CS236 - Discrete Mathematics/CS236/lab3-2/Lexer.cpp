/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Scans the file one character at a time
classifies the text into tokens
creates a vector of all tokens in the file
contains a function to output the tokens into string
*/


#include "Lexer.h"

vector<Token> Lexer::scanner(string fileName) {
  inFile.open(fileName);
  current = inFile.get();
  while (current != -1) {
    next = inFile.peek();
    currentString.clear();
    currentString += current;
    undefinedStringOrComment = false;
    if (findWhitespace()) {}
    else if (simplePunct() != UNDEFINED) {
      Token currentToken(currentString, currentLine, simplePunct());
      tokenList.push_back(currentToken);
    }
    else if (colonDash() == COLON) {
      Token currentToken(currentString, currentLine, colonDash());
      tokenList.push_back(currentToken);
    }
    else if (colonDash() == COLON_DASH) {
      currentString += next;
      Token currentToken(currentString, currentLine, colonDash());
      tokenList.push_back(currentToken);
      current = inFile.get();
    }
    else if(findStrings() != UNDEFINED) {
      Token currentToken(currentString, lineNumHolder, STRING);
      tokenList.push_back(currentToken);
      lineNumHolder = currentLine;
    }
    else if(findComments() != UNDEFINED) {
      Token currentToken(currentString, lineNumHolder, COMMENT);
      tokenList.push_back(currentToken);
      lineNumHolder = currentLine;
    }
    else {
      //cout << "scanners lineNumHolder is: " << lineNumHolder << endl;
      tokenType t = findIDs();
      Token currentToken(currentString, lineNumHolder, t);
      tokenList.push_back(currentToken);
    }
    current = inFile.get();
  }
  Token currentToken("", currentLine, END_OF_FILE);
  tokenList.push_back(currentToken);
  return tokenList;
}


bool Lexer::findWhitespace() {
  if (current == '\n') {
    currentString.clear();
    currentLine++;
    return true;
  }
  else if (isspace(current)) {
    currentString.clear();
    return true;
  }
  return false;
}

tokenType Lexer::simplePunct() {
  switch (current) {
    case ',' :
      return COMMA;
    case '.' :
      return PERIOD;
    case '?' :
      return Q_MARK;
    case ')' :
      return RIGHT_PAREN;
    case '(' :
      return LEFT_PAREN;
    case '*' :
      return MULTIPLY;
    case '+' :
      return ADD;
    default:
      return UNDEFINED;
  }
}

tokenType Lexer::colonDash() {
  if (current == ':') {
    if (next == '-') {
      return COLON_DASH;
    }
    return COLON;
  }
  return UNDEFINED;
}

tokenType Lexer::findStrings() {
  lineNumHolder = currentLine;
  if (current == '\'') {
    while (!inFile.eof()) {
      current = inFile.get();
      next = inFile.peek();
      checkIfLine();
      if (current == '\'') {
        if (next == '\'') {
          currentString += current;
          current = inFile.get();
          next = inFile.peek();
        }
        else {
          currentString += current;
          return STRING;
        }
      }
      currentString += current;
    }
    undefinedStringOrComment = true;
  }

  return UNDEFINED;
}

tokenType Lexer::findComments() {
  if (current == '#') {
    lineNumHolder = currentLine;
    if (next == '|') {
      current = inFile.get();
      currentString += current;
      while (!inFile.eof()) {
        current = inFile.get();
        next = inFile.peek();
        checkIfLine();
        if (current == '|') {
          if (next == '#') {
            currentString += current;
            current = inFile.get();
            currentString += current;
            return COMMENT;
          }
        }
        currentString += current;
      }
    }
    else {
      while (next != '\n' && !inFile.eof()) {
        current = inFile.get();
        next = inFile.peek();
        currentString += current;
      }
      return COMMENT;
    }
    undefinedStringOrComment = true;
  }
  return UNDEFINED;
}

tokenType Lexer::findIDs() {
  if (!undefinedStringOrComment) {
    lineNumHolder = currentLine;
  }
  if (isalpha(current)) {
    //cout << "findIDs lineNumHolder is: " << lineNumHolder << endl;
    while (isalpha(next) || isdigit(next)) {
      current = inFile.get();
      next = inFile.peek();
      currentString += current;
      checkIfLine();
      if(isSchemes()) {
        return SCHEMES;
      }
      else if (isFacts()) {
        return FACTS;
      }
      else if (isRules()) {
        return RULES;
      }
      else if (isQueries()) {
        return QUERIES;
      }
    }
    return ID;
  }
  else {
    return UNDEFINED;
  }

}

bool Lexer::isSchemes() {
  if (currentString == "Schemes") {
    if (!isalpha(next) && !isdigit(next)) {
      return true;
    }
  }
  return false;
}

bool Lexer::isFacts() {
  if (currentString == "Facts") {
    if (!isalpha(next) && !isdigit(next)) {
      return true;
    }
  }
  return false;
}

bool Lexer::isRules() {
  if (currentString == "Rules") {
    if (!isalpha(next) && !isdigit(next)) {
      return true;
    }
  }
  return false;
}

bool Lexer::isQueries() {
  if (currentString == "Queries") {
    if (!isalpha(next) && !isdigit(next)) {
      return true;
    }
  }
  return false;
}

bool Lexer::checkIfLine() {
  if (current == '\n') {
    currentLine++;
    return true;
  }
  return false;
}

string Lexer::printTokenList() {
  stringstream ss;
  for (unsigned int i = 0; i < tokenList.size(); i++) {
    ss << tokenList.at(i).toString();
  }
  ss << "Total Tokens = " << tokenList.size() << endl;

  return ss.str();

}
