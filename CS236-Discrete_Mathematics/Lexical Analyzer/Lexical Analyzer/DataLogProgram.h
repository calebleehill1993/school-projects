#include "LexicalAnalyzer.h"

class DataLogProgram
{
public:
  DataLogProgram();
  DataLogProgram(LexicalAnalyzer& la);
  ~DataLogProgram();
  LexicalAnalyzer lex;
  void GrabSchemes();
  void GrabFacts();
  void GrabRules();
  void GrabQueries();
};
