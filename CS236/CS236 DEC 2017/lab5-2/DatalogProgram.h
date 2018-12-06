/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores the Facts, Rules, Queries, and Schemes class. Also keeps the domain.
Inputs: takes a fact, rule, scheme, or query and put it into the cooresponding class. Also takes a domain and stores it as domain.
Outputs: returns a string that shows all of the Facts, Rules, Schemes, Queries, and the domain.
*/


#pragma once
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "Domain.h"

using namespace std;

class DatalogProgram
{
protected:
  Rules DLPRules;
  Queries DLPQueries;
  Schemes DLPSchemes;
  Facts DLPFacts;
  Domain domain;
public:
  DatalogProgram(){}
  ~DatalogProgram(){}
  void addToSchemes(Scheme &scheme) {
    DLPSchemes.addToVector(scheme);
  }
  void addToFacts(Fact &fact) {
    DLPFacts.addToVector(fact);
  }
  void addToRules(Rule &rule) {
    DLPRules.addToVector(rule);
  }
  void addToQueries(Query &query) {
    DLPQueries.addToVector(query);
  }
  void setDomain(Domain &domain) {
    this->domain = domain;
  }
  Facts &getFacts() {
    return DLPFacts;
  }
  Schemes &getSchemes() {
    return DLPSchemes;
  }
  Queries &getQueries() {
    return DLPQueries;
  }
  Rules &getRules() {
    return DLPRules;
  }
  string toString() {
    stringstream ss;
    ss << DLPSchemes.toString();
    ss << DLPFacts.toString();
    ss << DLPRules.toString();
    ss << DLPQueries.toString();
    ss << domain.toString();
    return ss.str();
  }
};
