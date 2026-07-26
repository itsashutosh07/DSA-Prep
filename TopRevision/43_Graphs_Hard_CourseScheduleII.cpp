#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 08:03:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Graphs Playlist #CourseScheduleII
// https://takeuforward.org/plus/dsa/problems/course-schedule-ii?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/course-schedule-ii/

/*
DESCRIPTION :
    There are numCourses courses labeled from 0 to numCourses - 1.
    prerequisites[i] = [ai, bi] means you must take bi before ai.
    Return any valid order of courses to finish all, or empty array if impossible.

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]

Example 2:
    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)

*/ 


class Solution {
public:
    vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
        //your code goes here
    }

    vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> p1 = {{1, 0}};
    vector<vector<int>> p2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    // Method Invocation & Result Visualization
    printVector(sol.findOrder1(2, p1));
    printVector(sol.findOrder1(4, p2));
    printVector(sol.findOrder2(2, p1));
    printVector(sol.findOrder2(4, p2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V+E) | DFS Topo
    # DFS finishing order

2. TC: O(V+E) | SC: O(V+E) | Kahn's Algorithm
    # BFS indegree topological order
*/
