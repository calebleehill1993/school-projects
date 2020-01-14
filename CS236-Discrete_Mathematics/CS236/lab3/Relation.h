/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a schema and a set of tuples
Inputs: Takes a tuple and stores it in the set, takes a schema and stores it as the schema.
Outputs: returns a string that shows every element in the tuple and what relation it coorelates with. Also shows the size of the set.
*/

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
public:
  Relation(){}
  ~Relation(){}
  string toString() {
    stringstream ss;
        bool first = true;
        if (tuples.size() == 0) {
          ss << "No";
          return ss.str();
        }
        if (schema.getVector().size() <= 0) {
          ss << "Yes(" << tuples.size() << ")";
          for (auto i:tuples) {
          }
          return ss.str();
        }
        ss << "Yes(" << tuples.size() << ")";
        for (auto i:tuples) {
          ss << endl;
          first = true;
          for (int j = 0; j < i.size(); j++) {
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
