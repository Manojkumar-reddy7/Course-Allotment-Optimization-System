#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Print final course allocation
void printAllocation(const vector<int>& matchCourse);

// Calculate satisfaction percentage
double calculateSatisfaction(int matched, int totalCourses);

#endif