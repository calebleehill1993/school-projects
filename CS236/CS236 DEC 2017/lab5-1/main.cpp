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
#include "Graph.h"

using namespace std;

int main(/*int argc, char *argv[]*/)
{
  Lexer myLexer;
  vector<Token> lexerTokens = myLexer.scanner("test1.txt");
  Parser myParser(lexerTokens);
  myParser.parse();
  Interpreter myInterpreter(myParser.getDLP());
  myInterpreter.interpret();
  
  Graph test1;
  vector<int> test1Vector1;
  vector<int> test1Vector2;
  vector<int> test1Vector3;
  test1Vector1.push_back(1);
  test1Vector2.push_back(2);
  test1Vector3.push_back(0);
  test1.addToGraph(0, test1Vector1);
  test1.addToGraph(1, test1Vector2);
  test1.addToGraph(2, test1Vector3);
  test1.reverseGraph();
  test1.findAllTO();
  test1.findAllSCC();
  cout << "Graph1: " << endl;
  cout << test1.toString() << endl;
  cout << "1: Graph1 reverse test: SUCCESS" << endl;
  cout << test1.reverseToString() << endl;
  cout << "2: Graph1 Topological Order test: SUCCESS" << endl;
  cout << test1.TOToString() << endl;
  cout << "3: Graph1 Strongly Connected Component test: SUCCESS" << endl;
  cout << test1.SCCToString() << endl;
  
  Graph test2;
  vector<int> test2Vector0;
  vector<int> test2Vector1;
  vector<int> test2Vector2;
  vector<int> test2Vector3;
  vector<int> test2Vector4;
  test2Vector0.push_back(1);
  test2Vector0.push_back(2);
  test2Vector1.push_back(0);
  test2Vector2.push_back(1);
  test2Vector2.push_back(2);
  test2Vector4.push_back(3);
  test2Vector4.push_back(4);
  test2.addToGraph(0, test2Vector0);
  test2.addToGraph(1, test2Vector1);
  test2.addToGraph(2, test2Vector2);
  test2.addToGraph(3, test2Vector3);
  test2.addToGraph(4, test2Vector4);
  test2.reverseGraph();
  test2.findAllTO();
  test2.findAllSCC();
  cout << "Graph2: " << endl;
  cout << test2.toString() << endl;
  cout << "4: Graph2 reverse test: SUCCESS" << endl;
  cout << test2.reverseToString() << endl;
  cout << "5: Graph2 Topological Order test: SUCCESS" << endl;
  cout << test2.TOToString() << endl;
  cout << "6: Graph2 Strongly Connected Component test: SUCCESS" << endl;
  cout << test2.SCCToString() << endl;
  
  Graph test3;
  vector<int> test3Vector0;
  vector<int> test3Vector1;
  vector<int> test3Vector2;
  vector<int> test3Vector3;
  vector<int> test3Vector4;
  vector<int> test3Vector5;
  vector<int> test3Vector6;
  vector<int> test3Vector7;
  vector<int> test3Vector8;
  vector<int> test3Vector9;
  test3Vector0.push_back(1);
  test3Vector1.push_back(2);
  test3Vector2.push_back(1);
  test3Vector2.push_back(3);
  test3Vector3.push_back(4);
  test3Vector4.push_back(2);
  test3Vector0.push_back(4);
  test3Vector4.push_back(5);
  test3Vector5.push_back(5);
  test3Vector6.push_back(6);
  test3Vector7.push_back(8);
  test3Vector8.push_back(9);
  test3Vector9.push_back(7);
  test3.addToGraph(0, test3Vector0);
  test3.addToGraph(1, test3Vector1);
  test3.addToGraph(2, test3Vector2);
  test3.addToGraph(3, test3Vector3);
  test3.addToGraph(4, test3Vector4);
  test3.addToGraph(5, test3Vector5);
  test3.addToGraph(6, test3Vector6);
  test3.addToGraph(7, test3Vector7);
  test3.addToGraph(8, test3Vector8);
  test3.addToGraph(9, test3Vector9);
  test3.reverseGraph();
  test3.findAllTO();
  test3.findAllSCC();
  cout << "Graph3: " << endl;
  cout << test3.toString() << endl;
  cout << "7: Graph3 reverse test: SUCCESS" << endl;
  cout << test3.reverseToString() << endl;
  cout << "8: Graph3 Topological Order test: SUCCESS" << endl;
  cout << test3.TOToString() << endl;
  cout << "9: Graph3 Strongly Connected Component test: SUCCESS" << endl;
  cout << test3.SCCToString() << endl;
  
  Graph test4;
  vector<int> test4Vector0;
  vector<int> test4Vector1;
  vector<int> test4Vector2;
  vector<int> test4Vector3;
  vector<int> test4Vector4;
  test4Vector0.push_back(1);
  test4Vector0.push_back(4);
  test4Vector1.push_back(2);
  test4Vector2.push_back(2);
  test4Vector3.push_back(3);
  test4Vector4.push_back(3);
  test4.addToGraph(0, test4Vector0);
  test4.addToGraph(1, test4Vector1);
  test4.addToGraph(2, test4Vector2);
  test4.addToGraph(3, test4Vector3);
  test4.addToGraph(4, test4Vector4);
  test4.reverseGraph();
  test4.findAllTO();
  test4.findAllSCC();
  cout << "Graph4: " << endl;
  cout << test4.toString() << endl;
  cout << "10: Graph4 reverse test: SUCCESS" << endl;
  cout << test4.reverseToString() << endl;
  cout << "11: Graph4 Topological Order test: SUCCESS" << endl;
  cout << test4.TOToString() << endl;
  cout << "12: Graph4 Strongly Connected Component test: SUCCESS" << endl;
  cout << test4.SCCToString() << endl;
  
  
  

  return 0;
}
