/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Stores a map of Relations and strings
Inputs: takes a string and relation and puts them into the map.
Outputs: returns a string of the map
*/

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





};
