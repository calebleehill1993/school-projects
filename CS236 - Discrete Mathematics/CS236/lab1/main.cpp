/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: uses the first arguement given as an input file name and creates a Lexer to scan that file.
outputs a string of the tokens contained in the lexer vector.
*/


#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"

using namespace std;

int main(int arc, char* argv[])
{
  Lexer myLexer;
  myLexer.scanner(argv[1]);
  cout << myLexer.getTokenList();

  return 0;
}
