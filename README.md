# Course Allotment Optimization System

## Problem
Manual course allocation is inefficient and may not satisfy professor preferences and can lead to inefficient assignments.

## Solution
This project models course allocation as a weighted bipartite matching problem using graph algorithms to maximize satisfaction.

## Features
- Graph-based modeling
- Weighted preference optimization
- Satisfaction percentage calculation
- Modular C++ project structure

## Tech Stack
- C++
- Graph Algorithms
- Optimization Techniques

## Sample Output

![Allocation Output](screenshots/allocation_output.png)

## System Architecture
![Architecture](docs/system_design.png)

## How to Run
g++ src/main.cpp src/graph.cpp src/weighted_matching.cpp src/utils.cpp -Iinclude -o allot
./allot 