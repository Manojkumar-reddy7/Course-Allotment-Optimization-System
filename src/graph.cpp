#include "graph.h"

Graph::Graph(int p, int c) {
    P = p;
    C = c;
    adj.resize(P);
}

void Graph::addEdge(int prof, int course, int weight) {
    adj[prof].push_back({course, weight});
}