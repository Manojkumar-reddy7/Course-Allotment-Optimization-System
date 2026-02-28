#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
public:
    int P;
    int C;

    // (course, weight)
    vector<vector<pair<int,int>>> adj;

    Graph(int p, int c);

    void addEdge(int prof, int course, int weight);
};

#endif