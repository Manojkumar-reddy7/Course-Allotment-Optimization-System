# Project Overview

## Objective
To design and implement a course allotment system that maximizes professor satisfaction using graph-based optimization techniques.

## Problem Statement
Manual allocation of courses to professors may not satisfy preferences and may lead to inefficient assignments.

## Approach
The problem is modeled as a weighted bipartite graph:

- Left set: Professors
- Right set: Courses
- Edge weight: Preference score

The goal is to maximize total satisfaction score using weighted matching.

## System Architecture
1. Read input data from files.
2. Construct graph representation.
3. Apply weighted matching algorithm.
4. Output optimized allocation.