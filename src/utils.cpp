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