#include <iostream>
#include "Database.h"
#include "DatalogProgram.h"
#include <algorithm>
#include "Graph.h"

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
  void print() {
    cout << endl << "Query Evaluation" << endl;
    bool first = true;
    Relation r;
    for (auto i:DLP.getQueries().getQueries()) {
      r = evaluateQuery(i);
      if (first) {
        cout << i.toString() << "? " << r.toString();
      }
      else {
        cout << endl << i.toString() << "? " << r.toString();
      }
      first = false;
    }
  }
  Tuple factToTuple(Fact &fact) {
    Tuple tuple;
    tuple.set(fact.getVector());
    return tuple;
  }
  void addTuplesToDatabase(Facts &facts) {
    for (auto i:facts.getFacts()) {
      for (auto j:myDatabase.getMap()) {
        if (i.getID() == j.first) {
          myDatabase.getMap()[j.first].addTuple(factToTuple(i));
          break;
        }
      }
    }
  }
  Relation makeNewRelation(Scheme &scheme) {
    Relation relation;
    relation.setSchema(scheme.getVector());
    return relation;
  }
  Schema schemeToSchema(Scheme &scheme) {
    return Schema(scheme.getVector()); 
  }
  void addSchemaToDatabase(Schemes &schemes) {
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
  Relation reName(Relation &r, Predicate &p) {
    Schema s;
    Relation newR = r;
    vector<pair<string, int>> tupleOrder = getTupleOrder(r,p,true);
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
  bool find(string check, vector<pair<string,int>> &myPair) {
    for (unsigned int i = 0; i < myPair.size(); i++) {
      if (myPair.at(i).first == check) {
        return true;
      }
    }
    return false;
  }
  vector<pair<string, int>> getTupleOrder(Relation &r, Predicate &p, bool isQuery) {
    vector<int> tupleOrder;
    int index = 0;
    vector<pair<string,int>> tupleMap;
    index = 0;
    for (auto i:p.getParameters()) {
      if (i.getToken().getTokenType() != STRING) {
        if (!find(i.getToken().getString(), tupleMap)) {
          if (isQuery) {
            tupleMap.push_back(make_pair(i.getToken().getString(), index));
          }
          else {
            tupleMap.push_back(make_pair(i.getToken().getString(), r.findInScheme(i.getToken().getString())));
          }
        }
      }
      index++;
    }
    return tupleMap;
  }
  Relation project(Relation &r, Predicate &p, bool isQuery) {
    Relation newR;
    Schema s;
    bool first = true;
    vector<pair<string,int>> tupleOrder = getTupleOrder(r,p,isQuery);
    for (auto i:r.getTuples()) {
      Tuple t;
      for (auto j:tupleOrder) {
        t.push_back(i.at(j.second));
        if (first) {
          s.insert(j.first);
          first = false;
        }
      }
      // t.reverse();
      newR.addTuple(t);
    }
    newR.setSchema(s);
    return newR;
  }
  vector<int> projectIndices(vector<Parameter> &parameters, int index) {
    vector<int> indices;
    for (unsigned int i = 0; i < parameters.size(); i++) {
      if (parameters.at(index).getToken().getString() == parameters.at(i).getToken().getString()) {
        indices.push_back(i);
      }
    }
    return indices;
  }
  Relation select(Predicate &predicate) {
    int index = 0;
    vector<int> indices;
    Relation r = matchRelation(predicate.getPredicateId().toString());
    for (auto i:predicate.getParameters()) {
      if (i.getToken().getTokenType() == STRING) {
        r = match(i.getToken(), index, r);
      }
      else {
        indices = projectIndices(predicate.getParameters(), index);
        r = match(indices, r);
      }
      index++;
    }
    return r;
  }
  Relation match(Token t, int index, Relation &r) {
    Relation newR;
    newR.setSchema(r.getSchema());
    for (auto i:r.getTuples()) {
      if (i.at(index) == t.getString()) {
        newR.addTuple(i);
      }
    }
    return newR;
  }
  Relation match(vector<int> indices, Relation &r) {
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
  Relation evaluateQuery(Predicate &p) {
    Relation r = select(p);
    r = project(r, p, true);
    return reName(r, p);
  }
  Relation evaluateQueries(vector<Predicate> &preds, bool add) {
    Relation r;
    for (auto i:preds) {
      if (add) {
        if (r.tupleCount() == 0) {
          r = evaluateQuery(i);
        }
        else {
          Relation temp = evaluateQuery(i);
          r = join(r, temp);
        }
      }
      else {
        r = evaluateQuery(i);
        cout << r.toString() << endl;
      }
    }
    return r;
  }
  void processRules(Rules &rules) {
    Relation r;
    for (auto i:rules.getRules()) {
      r = evaluateQueries(i.getPredicates(),true);
      r = project(r, i.getHead(), false);
      myDatabase.getMap()[i.getHeadString()].setTuples(r.getTuples());
    }
  }
  void evaluateRules(Rules &rules, Vertex &vertex, int index) {
    int originSize = 0;
    int numCycles = 0;
    if (!rules.needRepass()) {
      originSize = myDatabase.getSize();
      processRules(rules);
      numCycles++;
    }
    else {
      while (originSize != myDatabase.getSize()) {
      originSize = myDatabase.getSize();
      processRules(rules);
      numCycles++;
      }
    }
    cout << numCycles << " passes: " << vertex.toString() << endl;
  }
  Schema joinSchema(Schema &s1, Schema &s2) {
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
  Tuple joinTuple(Schema &s1, Schema &s2, Tuple &t1, Tuple &t2) {
    Tuple t = t1;
    bool match = false;
    for (unsigned int i = 0; i < s2.getVector().size(); i++) {
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
  Relation join(Relation &r1, Relation &r2) {
    Relation r;
    Schema s;
    Schema s1 = r1.getSchema();
    Schema s2 = r2.getSchema();
    s = joinSchema(s1, s2);
    r.setSchema(s);
    for (auto i:r1.getTuples()) {
      for (auto j:r2.getTuples()) {
        if (canJoin(s1, s2, i, j)) {
          r.addTuple(joinTuple(s1, s2, i, j));
        }
      }
    }
    return r;
  }
  bool canJoin(Schema &s1, Schema &s2, Tuple &t1, Tuple &t2) {
    for (unsigned int i = 0; i < s1.getVector().size(); i++) {
      for (unsigned int j = 0; j < s2.getVector().size(); j++) {
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
  // map<Rule,int> getRuleOrder() {
  //   map<Rule,int> ruleOrder;
  //   int index = 0;
  //   for (auto i:DLP.getRules().getRules()) {
  //     ruleOrder[i] = index;
  //     index++;
  //   }
  //   return ruleOrder;
  // }
  Graph getGraph() {
    Graph graph;
    // map<Rule,int> ruleOrder = getRuleOrder();
    Vertex vertex;
    int index = 0;
    for (auto i:DLP.getRules().getRules()) {
      vertex.clear();
      for (auto j:i.getPredicates()) {
        for (unsigned int k = 0; k < DLP.getRules().getRules().size(); k++) {
          if (DLP.getRules().getRules().at(k).getHeadString() == j.getPredicateIdString()) {
            vertex.insert(k);
          }
        }
      }
      graph.addToGraph(index, vertex);
      index++;
    }
    return graph;
  }
  
  Rules getSCCRules(Vertex SCC){
    Rules rules;
    for (auto i:SCC.getPaths()) {
      rules.addToVector(DLP.getRules().getRules().at(i));
    }
    return rules;
  }
  
  void evaluateGraph() {
    Graph myGraph = getGraph();
    myGraph.reverseGraph();
    myGraph.findAllTO();
    myGraph.findAllSCC();
    cout << myGraph.toString();
    cout << endl << "Rule Evaluation" << endl;
    for (unsigned int i = 0; i < myGraph.getSCC().size(); i++) {
      Rules rules = getSCCRules(myGraph.getSCC().at(i));
      evaluateRules(rules, myGraph.getSCC().at(i), i);
    }
    
    return;
  }
  
  
  
  int interpret() {
    addSchemaToDatabase(DLP.getSchemes());
    addTuplesToDatabase(DLP.getFacts());
    evaluateGraph();
    print();
    
    
    
    
    return 0;
  }
};
