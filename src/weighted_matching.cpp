#include "weighted_matching.h"
#include <algorithm>

WeightedMatching::WeightedMatching(Graph &graph) : g(graph) {
    matchCourse.assign(g.C, -1);
    totalScore = 0;
}

void WeightedMatching::solve() {

    for(int prof = 0; prof < g.P; prof++) {

        int bestCourse = -1;
        int bestWeight = -1;

        for(auto &edge : g.adj[prof]) {

            int course = edge.first;
            int weight = edge.second;

            // allow reassignment if better weight
            if(weight > bestWeight) {
                bestWeight = weight;
                bestCourse = course;
            }
        }

        if(bestCourse != -1) {
            matchCourse[bestCourse] = prof;
            totalScore += bestWeight;
        }
    }
}