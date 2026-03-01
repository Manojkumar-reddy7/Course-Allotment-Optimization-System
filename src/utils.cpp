#include "../include/utils.h"
#include <iostream>

using namespace std;

void printAllocation(const vector<int>& matchCourse) {
    cout << "\nFinal Course Allocation\n";
    cout << "-----------------------\n";

    for(int c = 0; c < matchCourse.size(); c++) {
        if(matchCourse[c] != -1) {
            cout << "Course C" << c+1
                 << " -> Professor P"
                 << matchCourse[c] + 1
                 << endl;
        }
    }
}

double calculateSatisfaction(int matched, int totalCourses) {
    if(totalCourses == 0) return 0;
    return (double)matched / totalCourses * 100.0;
}



#include <cstdlib>
#include <fstream>
#include <string>

double predictScore(int experience,
                    int publications,
                    int difficulty,
                    double success_rate)
{
    std::string command =
        "py ml/predict.py "
        + std::to_string(experience) + " "
        + std::to_string(publications) + " "
        + std::to_string(difficulty) + " "
        + std::to_string(success_rate)
        + " > temp.txt";

    system(command.c_str());

    std::ifstream file("temp.txt");
    double score;
    file >> score;
    file.close();

    return score;
}