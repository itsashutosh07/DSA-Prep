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

// Striver's Graphs Playlist #CourseScheduleI
// https://takeuforward.org/plus/dsa/problems/course-schedule-i?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/course-schedule/

/*
DESCRIPTION :
    There are numCourses courses labeled from 0 to numCourses - 1.
    prerequisites[i] = [ai, bi] means you must take bi before ai. Return true if you can finish all courses.

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true

Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000

*/ 


class Solution {
public:
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        //your code goes here
    }

    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> p1 = {{1, 0}};
    vector<vector<int>> p2 = {{1, 0}, {0, 1}};

    // Method Invocation & Result Visualization
    cout << boolalpha << sol.canFinish1(2, p1) << endl;
    cout << sol.canFinish1(2, p2) << endl;
    cout << sol.canFinish2(2, p1) << endl;
    cout << sol.canFinish2(2, p2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V+E) | DFS Cycle Detect
    # Detect cycle in directed graph

2. TC: O(V+E) | SC: O(V+E) | Kahn's Algorithm
    # Topo sort; fail if cannot order all
*/
