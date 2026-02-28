#include <iostream>
#include <fstream>
#include "../include/graph.h"
#include "weighted_matching.h"
#include "utils.h"

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

    // Use utils to print allocation
    printAllocation(wm.matchCourse);

    // Calculate satisfaction percentage
    double satisfaction =
        calculateSatisfaction(wm.totalScore, professors * 5);

    cout << "\nSatisfaction Percentage: "
         << satisfaction << "%" << endl;

    return 0;
}