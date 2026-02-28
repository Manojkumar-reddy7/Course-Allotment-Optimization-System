# Algorithm Explanation

## Graph Modeling

The course allotment problem is modeled as a bipartite graph:

- Set P = Professors
- Set C = Courses
- Edge (P_i, C_j) with weight W represents preference.

## Weighted Matching

The algorithm iterates through each professor and selects the course with the highest available weight.

Steps:
1. Initialize all courses as unassigned.
2. For each professor:
   - Traverse preference edges.
   - Select highest weight course.
   - Assign if unallocated.
3. Compute total satisfaction score.

## Time Complexity

Let:
- P = number of professors
- C = number of courses
- E = number of preference edges

Time Complexity: O(E)

## Space Complexity

O(P + C + E)