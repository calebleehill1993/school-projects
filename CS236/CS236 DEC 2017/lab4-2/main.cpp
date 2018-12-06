/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: uses the first arguement given as an input file name and creates a Lexer to scan that file.
Uses the Parser class to parse the Lexed file.
*/


#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char *argv[])
{
  Lexer myLexer;
  vector<Token> lexerTokens = myLexer.scanner(argv[1]);
  Parser myParser(lexerTokens);
  myParser.parse();
  Interpreter myInterpreter(myParser.getDLP());
  myInterpreter.interpret();

  return 0;
}
