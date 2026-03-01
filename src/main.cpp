#include <iostream>
#include <fstream>
#include "../include/graph.h"
#include "weighted_matching.h"
#include "utils.h"
#include <map>
#include <tuple>

using namespace std;

int main() {

    map<string, tuple<int,int,double>> professorData;
    map<string, int> courseData;

    ifstream profFile("data/professors.txt");

    string profName;
    int exp, pubs;
    double success;

    while(profFile >> profName >> exp >> pubs >> success){
        professorData[profName] = make_tuple(exp, pubs, success);
    }

    profFile.close();


    ifstream courseFile("data/courses.txt");

    string courseName;
    int difficulty;

    while(courseFile >> courseName >> difficulty){
        courseData[courseName] = difficulty;
    }

    courseFile.close();



    int professors = 4;
    int courses = 4;

    Graph g(professors, courses);

    ifstream file("data/preferences.txt");

    string p, c;
    int weight;

    while(file >> p >> c >> weight){

        int profID = p[1] - '1';
        int courseID = c[1] - '1';

        // Get professor info
        auto profInfo = professorData[p];

        int experience = get<0>(profInfo);
        int publications = get<1>(profInfo);
        double success_rate = get<2>(profInfo);

        // Get course difficulty
        int difficulty = courseData[c];

        // Ask ML model
        double predictedScore =predictScore(experience, publications, difficulty, success_rate);

        // Add ML weight to graph
        g.addEdge(profID, courseID, predictedScore);
    }   



    file.close();

    cout << "Graph Built Successfully\n";

    WeightedMatching wm(g);
    wm.solve();

    // Use utils to print allocation
    printAllocation(wm.matchCourse);

    // Calculate satisfaction percentage
    double satisfaction = calculateSatisfaction(wm.totalScore, professors * 10);

    cout << "\nSatisfaction Percentage: "
         << satisfaction << "%" << endl;

    return 0;
}