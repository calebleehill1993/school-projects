/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: stores a vector of Query
Inputs: A Query via the addToVector function
Outputs: the list of Query as a string.
*/

#pragma once
#include <vector>
#include "Query.h"

using namespace std;

class Queries
{
protected:
  Query myQuery;
  vector<Query> queries;
public:
  Queries(){}
  ~Queries(){}
  void addToVector(Query query) {
    queries.push_back(query);
  }
  string toString() {
    stringstream ss;
    ss << "Queries(" << queries.size() << "):" << endl;
    for (int i = 0; i < queries.size(); i++) {
      ss << "  " << queries.at(i).toString() << "?" << endl;
    }
    return ss.str();
  }
  vector<Query> getQueries() {
    return queries;
  }
  Query at(int index) {
    return queries.at(index);
  }
  vector<Predicate> getPredicates() {
    vector<Predicate> preds;
    for (auto i:queries) {
      preds.push_back(i);
    }
    return preds;
  }
};
