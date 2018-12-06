#pragma once
#include <iostream>
#include <set>
#include "Tuple.h"
#include "Schema.h"

using namespace std;

class Relation {
protected:
  set<Tuple> tuples;
  Schema schema;
  string name;
public:
  Relation(){}
  ~Relation(){}
  string toString(){
    stringstream ss;
    bool first = true;
    if (tuples.size() == 0) {
      ss << "No";
      return ss.str();
    }
    if (schema.getVector().size() <= 0) {
      ss << "Yes(" << tuples.size() << ")";
      return ss.str();
    }
    ss << "Yes(" << tuples.size() << ")";
    for (auto i:tuples) {
      ss << endl;
      first = true;
      for (int j = 0; j < schema.getVector().size(); j++) {
        if (first) {
          ss << "  " << schema.getVector().at(j) << "=" << i.at(j);
        }
        else {
          ss << ", " << schema.getVector().at(j) << "=" << i.at(j);
        }
        first = false;
      }
    }
    return ss.str();
    
    
    // ss << schema.toString() << endl;
    // for (auto it:tuples) {
    //   for (int i = 0; i < it.size(); i++) {
    //     ss << it.at(i) << " ";
    //   }
    //   ss << endl;
    // }
    // return ss.str();
  }
  string onlyStrings() {
    stringstream ss;
    if (tuples.size() == 0) {
      ss << "no";
      return ss.str();
    }
    
  }
  void setSchema(Schema schema) {
    this->schema = schema;
  }
  void addTuple(Tuple tuple) {
    tuples.insert(tuple);
  }
  Schema getSchema() {
    return schema;
  }
  set<Tuple> getTuples() {
    return tuples;
  }
  int tupleCount() {
    return tuples.size();
  }
  void setTuples(set<Tuple> newTuples) {
    for (auto i:newTuples) {
      tuples.insert(i);
    }
  }
};
