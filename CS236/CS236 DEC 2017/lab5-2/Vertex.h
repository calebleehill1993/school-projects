#include <iostream>
#include <set>
#include <sstream>

using namespace std;

class Vertex
{
protected:
    set<int> paths;
    bool visited = false;
    bool SD = false;
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
                ss << "R" << i;
            }
            else {
                ss << ",R" << i;
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
    void clear() {
        visited = false;
        paths.clear();
    }
    int size() {
        return paths.size();
    }
    bool getSD(int index) {
        cout << "index: " << index << endl;
        for (auto i:paths) {
            cout << "i: " << i << endl;
            if (i == index) {
                return true;
            }
        }
        return false;
    }
};