#include <iostream>
#include <fstream>
#include "../include/graph.h"
#include "matching.h"
#include "weighted_matching.h"

using namespace std;

int main() {

    int professors = 3;
    int courses = 3;

    Graph g(professors, courses);

    ifstream file("data/preferences.txt");

    string p, c;
    int weight;

    while(file >> p >> c >> weight){
        int profID = p[1] - '1';   // P1 → 0
        int courseID = c[1] - '1'; // C1 → 0

        g.addEdge(profID, courseID, weight);
    }

    file.close();

    cout << "Graph Built Successfully\n";

    WeightedMatching wm(g);
    wm.solve();

    cout << "\nFinal Course Allocation\n";
    cout << "-----------------------\n";

    for(int c = 0; c < courses; c++) {
        if(wm.matchCourse[c] != -1) {
            cout << "Course C" << c+1
                 << " -> Professor P"
                 << wm.matchCourse[c]+1
                 << endl;
        }
    }

    cout << "\nLoaded Preferences\n";

    for(int p = 0; p < g.P; p++) {
        for(auto &edge : g.adj[p]) {
            cout << "Professor P" << p+1
                 << " prefers Course C"
                 << edge.first+1
                 << " weight "
                 << edge.second << endl;
        }
    }

    int maxPossibleScore = professors * 5; // assuming max weight = 5

    double percentage =(double)wm.totalScore / maxPossibleScore * 100;

    cout << "Satisfaction Percentage: "
         << percentage << "%" << endl;

    return 0;
}