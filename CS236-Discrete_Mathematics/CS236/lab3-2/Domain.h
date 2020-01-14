/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Holds a vector of strings, Puts these strings in an order and eliminates duplicates
Inputs: strings that are then passed into the vector of strings
Outputs: the toString function returns the vector of strings, the getDomain returns the vector of strings
*/



#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Domain
{
protected:
    vector<string> domain;
public:
    Domain(){}
    ~Domain(){}
    void addString(string inString) {
        domain.push_back(inString);
    }
    string toString() {
        stringstream ss;
        sortDomain();
        set<string> domainSet(domain.begin(), domain.end());
        ss << "Domain(" << domainSet.size() << "):" << endl;
        for (set<string>::iterator it = domainSet.begin(); it != domainSet.end(); ++it) {
            ss << "  " << *it << endl;
        }
        return ss.str();
    }
    void sortDomain() {
        sort(domain.begin(), domain.end());
    }
    vector<string> getDomain() {
        return domain;
    }
    void addDomain(Domain inDomain) {
        for (unsigned int i = 0; i < inDomain.getDomain().size(); i++) {
            domain.push_back(inDomain.getDomain().at(i));
        }
    }
};
