#include <iostream>
#include <set>
#include <sstream>

using namespace std;

class Vertex
{
protected:
    set<int> paths;
    bool visited = false;

public:
    Vertex(){}
    ~Vertex(){}
    
    set<int> getPaths() {
        return paths;
    }
    
    string toString() {
        stringstream ss;
        bool first = true;
        for (auto i:paths) {
            if (first) {
                first = false;
                ss << i;
            }
            else {
                ss << ", " << i;
            }
        }
        return ss.str();
    }
    
    void insertVector(vector<int> addVector) {
        for (auto i:addVector) {
            paths.insert(i);
        }
    }
    
    void insertVertex(Vertex vertex) {
        for (auto i:vertex.getPaths()) {
            paths.insert(i);
        }
    }
    
    void insert(int insert) {
        paths.insert(insert);
    }
    
    bool getVisited() {
        return visited;
    }
    
    void setVisited(bool visited) {
        this->visited = visited;
    }

};