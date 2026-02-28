#ifndef MATCHING_H
#define MATCHING_H

#include "graph.h"
#include <vector>

class Matching {
public:
    Graph &g;
    std::vector<int> matchCourse;  // course → professor
    std::vector<bool> visited;

    Matching(Graph &graph);
    bool dfs(int prof);
    int maxMatching();
};

#endif