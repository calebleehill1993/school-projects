/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Interprets a query based off a relation. Stores the Queries in the DLP and creates a set of relations from the Facts and Schemes, stores these in the Database
Inputs: A datalog Program
Outputs: returns a string that shows the evaluated Queries.
*/

#include <iostream>
#include "Database.h"
#include "DatalogProgram.h"

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
    Schema schema(scheme.getVector());
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
    map<string, int> tupleOrder = getTupleOrder(r,q);
    if (tupleOrder.size() <= 0) {
      return newR;
    }
    // map<string, int>::iterator it = tupleOrder.end();
    // --it;
    // for (it; it != tupleOrder.begin(); --it) {
    //   s.insert((*it).first);
    // }
    // s.insert((*it).first);
    for (map<string,int>::iterator it = tupleOrder.begin(); it != tupleOrder.end(); ++it) {
       s.insert((*it).first);
    }
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
  map<string, int> getTupleOrder(Relation r, Query q) {
    vector<int> tupleOrder;
    int index = 0;
    map<string, int> tupleMap;
    index = 0;
    for (auto i:q.getParameters()) {
      if (i.getToken().getTokenType() != STRING) {
        if (tupleMap.find(i.getToken().getString()) == tupleMap.end()) {
          tupleMap.insert(make_pair(i.getToken().getString(), index));
        }
      }
      index++;
    }
    return tupleMap;
  }
  Relation project(Relation r, Query q) {
    Relation newR;
    Schema s;
    map<string, int> tupleOrder = getTupleOrder(r,q);
    for (auto i:r.getTuples()) {
      Tuple t;
      for (auto j:tupleOrder) {
        t.push_back(i.at(j.second));
        s.insert(j.first);
      }
      newR.addTuple(t);
    }
    newR.setSchema(s);
    return newR;
  }
  vector<int> projectIndices(vector<Parameter> parameters, int index) {
    vector<int> indices;
    for (int i = 0; i < parameters.size(); i++) {
      if (parameters.at(index).getToken().getString() == parameters.at(i).getToken().getString()) {
        indices.push_back(i);
      }
    }
    return indices;
  }
  Relation select(Query query) {
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
      for (int j = 0; j < indices.size(); j++) {
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

  int interpret() {
    cout << "interpreting test" << endl;
    addSchemaToDatabase(DLP.getSchemes());
    addTuplesToDatabase(DLP.getFacts());



    cout << "Rename test 1:" << endl;
    Relation r = reName(matchRelation("SK"),DLP.getQueries().at(0));
    if (r.toString() == matchRelation("key1").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;



    cout << "Rename test 2:" << endl;
    r = reName(matchRelation("SK"),DLP.getQueries().at(1));
    if (r.toString() == matchRelation("key2").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "project test 1:" << endl;
    r = project(matchRelation("SK"),DLP.getQueries().at(2));
    if (r.toString() == matchRelation("key3").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "project test 2:" << endl;
    r = project(matchRelation("SK"),DLP.getQueries().at(3));
    if (r.toString() == matchRelation("key4").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "select test 1:" << endl;
    r = select(DLP.getQueries().at(4));
    if (r.toString() == matchRelation("key5").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "select test 2:" << endl;
    r = select(DLP.getQueries().at(5));
    if (r.toString() == matchRelation("key6").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "Query test 1:" << endl;
    r = select(DLP.getQueries().at(5));
    r = project(r,DLP.getQueries().at(5));
    r = reName(r,DLP.getQueries().at(5));
    if (r.toString() == matchRelation("key7").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "Query test 2:" << endl;
    r = select(DLP.getQueries().at(4));
    r = project(r,DLP.getQueries().at(4));
    r = reName(r,DLP.getQueries().at(4));
    if (r.toString() == "Yes(1)") {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "Query test 3:" << endl;
    r = select(DLP.getQueries().at(3));
    r = project(r,DLP.getQueries().at(3));
    r = reName(r,DLP.getQueries().at(3));
    if (r.toString() == matchRelation("key9").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;

    cout << "Query test 4:" << endl;
    r = select(DLP.getQueries().at(2));
    r = project(r,DLP.getQueries().at(2));
    r = reName(r,DLP.getQueries().at(2));
    if (r.toString() == matchRelation("key10").toString()) {
      cout << "Pass" << endl;
    }
    else {
      cout << "Fail" << endl;
    }
    cout << r.toString() << endl;



    return 0;
  }
};
