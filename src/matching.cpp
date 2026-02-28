#include "matching.h"

Matching::Matching(Graph &graph) : g(graph) {
    matchCourse.assign(g.C, -1);
}

bool Matching::dfs(int prof) {

    for(auto &edge : g.adj[prof]) {

        int course = edge.first;   // extract course ID

        if(visited[course]) continue;
        visited[course] = true;

        if(matchCourse[course] == -1 ||
           dfs(matchCourse[course])) {

            matchCourse[course] = prof;
            return true;
        }
    }

    return false;
}

int Matching::maxMatching() {
    int count = 0;

    for(int prof = 0; prof < g.P; prof++) {

        visited.assign(g.C, false);

        if(dfs(prof))
            count++;
    }

    return count;
}