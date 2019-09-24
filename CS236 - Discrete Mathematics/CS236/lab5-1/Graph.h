#include <iostream>
#include <map>
#include <algorithm>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
    map<int, Vertex> adjList;
    map<int, Vertex> reverseList;
    vector<int> topOrder;
    vector<Vertex> SCC;
public:
    Graph(){}
    ~Graph(){}
    void reverseGraph() {
        for (auto i:adjList) {
            for (auto j:i.second.getPaths()) {
                if (reverseList.find(j) == reverseList.end()) {
                    reverseList[j] = Vertex();
                }
                reverseList[j].insert(i.first);
            }
        }
    }
    string toString() {
        stringstream ss;
        for (auto i:adjList) {
            ss << i.first << ": " << i.second.toString() << endl;
        }
        return ss.str();
    }
    string reverseToString() {
        stringstream ss;
        for (auto i:reverseList) {
            ss << i.first << ": " << i.second.toString() << endl;
        }
        return ss.str();
    }
    string TOToString() {
        stringstream ss;
        int index = 0;
        for (int i = topOrder.size() - 1; i >= 0; i--) {
            ss << "(" << topOrder.at(i) << ") = " << index << endl;
            index++;
        }
        return ss.str();
    }
    string SCCToString() {
        stringstream ss;
        for (auto i:SCC) {
            ss << "{" << i.toString() << "}" << endl;
        }
        return ss.str();
    }
    void addToGraph(int addInt, vector<int> addVector) {
        Vertex addVertex;
        addVertex.insertVector(addVector);
        adjList[addInt] = addVertex;
    }
    void findTO(int index) {
        reverseList[index].setVisited(true);
        for (auto i:reverseList[index].getPaths()) {
            if (!reverseList[i].getVisited()) {
                findTO(i);
            }
        }
        topOrder.push_back(index);
    }
    void findAllTO() {
        for (auto i:reverseList) {
            if (!i.second.getVisited()) {
                findTO(i.first);
            }
        }
        reverse(topOrder.begin(), topOrder.end());
    }
    Vertex findSCC(int index) {
        Vertex vertex;
        adjList[index].setVisited(true);
        for (auto i:adjList[index].getPaths()) {
            if (!adjList[i].getVisited()) {
                vertex.insertVertex(findSCC(i));
            }
        }
        vertex.insert(index);
        return vertex;
    }
    void findAllSCC() {
        for (auto i:topOrder) {
            if (!adjList[i].getVisited()) {
                SCC.push_back(findSCC(i));
            }
        }
    }
};