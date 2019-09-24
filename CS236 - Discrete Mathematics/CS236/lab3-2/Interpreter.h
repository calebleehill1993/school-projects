#include <iostream>
#include "Database.h"
#include "DatalogProgram.h"
#include <algorithm>

using namespace std;

class Interpreter
{
protected:
  Database myDatabase;
  DatalogProgram DLP;
public:

  Interpreter(DatalogProgram DLP){
    this->DLP = DLP;
  }
  ~Interpreter(){}
  Tuple factToTuple(Fact fact) {
    Tuple tuple;
    tuple.set(fact.getVector());
    return tuple;
  }
  void addTuplesToDatabase(Facts facts) {
    for (auto i:facts.getFacts()) {
      for (auto j:myDatabase.getMap()) {
        if (i.getID() == j.first) {
          myDatabase.getMap()[j.first].addTuple(factToTuple(i));
          break;
        }
      }
    }
  }
  Relation makeNewRelation(Scheme scheme) {
    Relation relation;
    relation.setSchema(scheme.getVector());
    return relation;
  }
  Schema schemeToSchema(Scheme scheme) {
    return Schema(scheme.getVector());
  }
  void addSchemaToDatabase(Schemes schemes) {
    bool found = false;
    for (auto i:schemes.getSchemes()) {
      found = false;
      for (auto j:myDatabase.getMap()) {
        if (i.getID() == j.first) {
          j.second.setSchema(schemeToSchema(i));
          found = true;
        }
      }
      if (found == false) {
        myDatabase.insert(i.getID(), makeNewRelation(i));
      }
    }
  }
  Relation reName(Relation r, Query q) {
    Schema s;
    Relation newR = r;
    vector<pair<string, int>> tupleOrder = getTupleOrder(r,q);
    if (tupleOrder.size() <= 0) {
      return newR;
    }
    for (unsigned int i = 0; i < tupleOrder.size(); i++) {
      s.insert(tupleOrder.at(i).first);
    }
    // s.reverse();
    newR.setSchema(s);
    return newR;
  }
  Relation matchRelation(string name) {
    Relation r;
    for (auto i:myDatabase.getMap()) {
      if (i.first == name) {
        r = i.second;
      }
    }
    return r;
  }
  bool find(string check, vector<pair<string,int>> myPair) {
    for (unsigned int i = 0; i < myPair.size(); i++) {
      if (myPair.at(i).first == check) {
        return true;
      }
    }
    return false;
  }
  vector<pair<string, int>> getTupleOrder(Relation r, Query q) {
    vector<int> tupleOrder;
    int index = 0;
    vector<pair<string,int>> tupleMap;
    index = 0;
    for (auto i:q.getParameters()) {
      if (i.getToken().getTokenType() != STRING) {
        if (!find(i.getToken().getString(), tupleMap)) {
          tupleMap.push_back(make_pair(i.getToken().getString(), index));
        }
      }
      index++;
    }
    return tupleMap;
  }
  Relation project(Relation r, Query q) {
    Relation newR;
    Schema s;
    vector<pair<string,int>> tupleOrder = getTupleOrder(r,q);
    for (auto i:r.getTuples()) {
      Tuple t;
      for (auto j:tupleOrder) {
        t.push_back(i.at(j.second));
        s.insert(j.first);
      }
      // t.reverse();
      newR.addTuple(t);
    }
    newR.setSchema(s);
    return newR;
  }
  vector<int> projectIndices(vector<Parameter> parameters, int index) {
    vector<int> indices;
    for (unsigned int i = 0; i < parameters.size(); i++) {
      if (parameters.at(index).getToken().getString() == parameters.at(i).getToken().getString()) {
        indices.push_back(i);
      }
    }
    return indices;
  }
  Relation select(Query &query) {
    int index = 0;
    vector<int> indices;
    Relation r = matchRelation(query.getPredicateId().toString());
    for (auto i:query.getParameters()) {
      if (i.getToken().getTokenType() == STRING) {
        r = match(i.getToken(), index, r);
      }
      else {
        indices = projectIndices(query.getParameters(), index);
        r = match(indices, r);
      }
      index++;
    }
    return r;
  }
  Relation match(Token t, int index, Relation r) {
    Relation newR;
    newR.setSchema(r.getSchema());
    for (auto i:r.getTuples()) {
      if (i.at(index) == t.getString()) {
        newR.addTuple(i);
      }
    }
    return newR;
  }
  Relation match(vector<int> indices, Relation r) {
    set<Tuple> tuples;
    Relation newR;
    if (indices.size() == 0) {
      return newR;
    }
    newR.setSchema(r.getSchema());
    bool tupleBad = false;
    for (auto i:r.getTuples()) {
      tupleBad = false;
      string toCompare = i.at(indices.at(0));
      for (unsigned int j = 0; j < indices.size(); j++) {
        if (i.at(indices.at(j)) != toCompare) {
          tupleBad = true;
          break;
        }
      }
      if (!tupleBad) {
        tuples.insert(i);
      }
    }
    newR.setTuples(tuples);
    return newR;
  }
  void evaluateQueries() {
    bool first = true;
    Relation r;
    for (auto i:DLP.getQueries().getQueries()) {
      r = reName(project(select(i), i), i);
      if (first) {
        cout << i.toString() << "? " << r.toString();
      }
      else {
        cout << endl << i.toString() << "? " << r.toString();
      }
      first = false;
    }
  }
  int interpret() {
    addSchemaToDatabase(DLP.getSchemes());
    addTuplesToDatabase(DLP.getFacts());
    
    evaluateQueries();    
    
    
    
    
    
    return 0;
  }
};
