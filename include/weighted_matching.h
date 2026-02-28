#ifndef WEIGHTED_MATCHING_H
#define WEIGHTED_MATCHING_H

#include "graph.h"
#include <vector>

class WeightedMatching {
public:
    Graph &g;
    std::vector<int> matchCourse;
    int totalScore;

    WeightedMatching(Graph &graph);
    void solve();
};

#endif