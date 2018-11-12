#include "DataLogProgram.h"
DataLogProgram::DataLogProgram()
{

}

DataLogProgram::DataLogProgram(LexicalAnalyzer& la)
{
  la.Print();
  lex = la;
  GrabSchemes();
}

void DataLogProgram::GrabSchemes()
{
  while(lex.tokens.at(0).type == "SCHEME")
  {
    std::cout << "this is a scheme";
    lex.tokens.erase(lex.tokens.begin());
  }
}

void DataLogProgram::GrabFacts()
{

}

void DataLogProgram::GrabRules()
{

}

void DataLogProgram::GrabQueries()
{

}

DataLogProgram::~DataLogProgram()
{

}
