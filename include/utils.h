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



double predictScore(int experience,
                    int publications,
                    int difficulty,
                    double success_rate);