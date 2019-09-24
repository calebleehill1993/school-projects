#pragma once
#include <map>
#include "Relation.h"

using namespace std;

class Database
{
protected:
  map<string, Relation> database;
public:
  Database(){}
  ~Database(){}
  string toString(){
    stringstream ss;
    for(auto elem : database){
      ss << elem.first << " " << elem.second.toString() << endl;
    }
    return ss.str();
  }
  map<string, Relation> &getMap() {
    return database;
  }
  void insert(string addString, Relation addRelation) {
    database.insert(std::pair<string,Relation>(addString,addRelation));
  }
  int getSize() {
    int size = 0;
    for (auto i:database) {
      size += i.second.tupleCount();
    }
    return size;
  }




};
