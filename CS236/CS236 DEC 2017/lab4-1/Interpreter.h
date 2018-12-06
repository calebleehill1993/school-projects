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
    vector<pair<string, int>> tupleOrder = getTupleOrder(r,q);
    if (tupleOrder.size() <= 0) {
      return newR;
    }
    for (int i = 0; i < tupleOrder.size(); i++) {
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
    for (int i = 0; i < myPair.size(); i++) {
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
    for (int i = 0; i < parameters.size(); i++) {
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
  void evaluateQueries() {
    bool first = true;
    Relation r;
    for (auto i:DLP.getQueries().getQueries()) {
      r = reName(project(select(i), i), i);
      if (first) {
        //cout << i.toString() << "? " << r.toString();
      }
      else {
        //cout << endl << i.toString() << "? " << r.toString();
      }
      first = false;
    }
  }
  
  
  
  void evaluateRules() {}
  Schema joinSchema(Schema s1, Schema s2) {
    Schema s = s1;
    bool match = false;
    for (auto i:s2.getVector()) {
      match = false;
      for (auto j:s1.getVector()) {
        if (i == j) {
          match = true;
          break;
        }
      }
      if (!match) {
        s.insert(i);
      }
    }
    return s;
  }
  Tuple joinTuple(Schema s1, Schema s2, Tuple t1, Tuple t2) {
    Tuple t = t1;
    bool match = false;
    for (int i = 0; i < s2.getVector().size(); i++) {
      match = false;
      for (auto j:s1.getVector()) {
        if (s2.getVector().at(i) == j) {
          match = true;
          break;
        }
      }
      if (!match) {
        t.push_back(t2.at(i));
      }
    }
    return t;
  }
  Relation join(Relation r1, Relation r2) {
    Relation r;
    Schema s;
    s = joinSchema(r1.getSchema(), r2.getSchema());
    r.setSchema(s);
    for (auto i:r1.getTuples()) {
      for (auto j:r2.getTuples()) {
        if (canJoin(r1.getSchema(), r2.getSchema(), i, j)) {
          r.addTuple(joinTuple(r1.getSchema(), r2.getSchema(), i, j));
        }
      }
    }
    return r;
  }
  bool canJoin(Schema s1, Schema s2, Tuple t1, Tuple t2) {
    for (int i = 0; i < s1.getVector().size(); i++) {
      for (int j = 0; j < s2.getVector().size(); j++) {
        if(s1.getVector().at(i) == s2.getVector().at(j) && t1.at(i) != t2.at(j)) {
          return false;
        }
      }
    }
    return true;
  }
  Relation unionRelation(Relation r1, Relation r2) {
    Relation r;
    if (r1.getSchema().getVector() != r2.getSchema().getVector()) {
      return r;
    }
    r = r1;
    for (auto i:r2.getTuples()) {
      r.addTuple(i);
    }
    cout << r.toString() << endl;
    return r;
  }
  
  
  
  
  
  
  
  
  int interpret() {
    addSchemaToDatabase(DLP.getSchemes());
    addTuplesToDatabase(DLP.getFacts());
    evaluateQueries();
    
    
    cout << "1: Schema join test 1" << endl;
    if ((joinSchema(myDatabase.getMap()["JOIN"].getSchema(), myDatabase.getMap()["TEST"].getSchema()).getVector() == myDatabase.getMap()["KEY1"].getSchema().getVector())) {
      cout << "success" << endl;
      cout << myDatabase.getMap()["KEY1"].getSchema().toString() << endl;
    }
    cout << "2: Schema join test 2" << endl;
    if (joinSchema(myDatabase.getMap()["SK"].getSchema(), myDatabase.getMap()["JOINSK"].getSchema()).getVector() == myDatabase.getMap()["KEY2"].getSchema().getVector()) {
      cout << "success" << endl;
      cout << myDatabase.getMap()["KEY2"].getSchema().toString() << endl;
    }
    cout << "3: Schema join test 3" << endl;
    if (joinSchema(myDatabase.getMap()["SNAP"].getSchema(), myDatabase.getMap()["JOINSNAP"].getSchema()).getVector() == myDatabase.getMap()["KEY3"].getSchema().getVector()) {
      cout << "success" << endl;
      cout << myDatabase.getMap()["KEY3"].getSchema().toString() << endl;
    }
    cout << "4: join test 1" << endl;
    if (join(myDatabase.getMap()["JOIN"], myDatabase.getMap()["TEST"]).toString() == matchRelation("KEY1").toString()) {
      cout << "success" << endl;
      cout << matchRelation("KEY1").toString() << endl;
    }
    cout << "5: join test 2" << endl;
    if (join(myDatabase.getMap()["SK"], myDatabase.getMap()["JOINSK"]).toString() == matchRelation("KEY2").toString()) {
      cout << "success" << endl;
      cout << matchRelation("KEY2").toString() << endl;
    }
    cout << "6: join test 3" << endl;
    if (join(myDatabase.getMap()["SNAP"], myDatabase.getMap()["JOINSNAP"]).toString() == matchRelation("KEY3").toString()) {
      cout << "success" << endl;
      cout << matchRelation("KEY3").toString() << endl;
    }
    cout << "7: join test 4" << endl;
    if (join(myDatabase.getMap()["SNAP"], myDatabase.getMap()["JOINSNAP1"]).toString() == matchRelation("KEY4").toString()) {
      cout << "success" << endl;
      cout << matchRelation("KEY4").toString() << endl;
    }
    cout << "8: union test 1" << endl;
    if (unionRelation(myDatabase.getMap()["UNION"], myDatabase.getMap()["UNIONTEST"]).toString() == matchRelation("KEY8").toString()) {
      cout << "success" << endl;
    }
    cout << "9: union test 2" << endl;
    if (unionRelation(myDatabase.getMap()["SK"], myDatabase.getMap()["UNIONSK"]).toString() == matchRelation("KEY9").toString()) {
      cout << "success" << endl;
    }
    cout << "10: union test 3" << endl;
    Relation r;
    if (unionRelation(myDatabase.getMap()["SK"], myDatabase.getMap()["JOINSK"]).toString() == r.toString()) {
      cout << "success" << endl;
    }
    cout << "join disjointed" << endl;
    if (join(myDatabase.getMap()["JOIN"], myDatabase.getMap()["DIS"]).toString() == matchRelation("KEY5").toString()) {
      cout << "success" << endl;
      cout << matchRelation("KEY5").toString() << endl;
    }
    
    return 0;
  }
};
