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

// Striver's Graphs Playlist #EventualSafeStates
// https://takeuforward.org/plus/dsa/problems/find-eventual-safe-states?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/find-eventual-safe-states/

/*
DESCRIPTION :
    There is a directed graph of n nodes with values from 0 to n-1. A node is terminal if it has no outgoing edges.
    A node is safe if every possible path starting from that node leads to a terminal node. Return all safe nodes in ascending order.

Example 1:
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]

Example 2:
    Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    Output: [4]

Constraints:
    1 <= n <= 10^4
    0 <= graph[i].length <= n

*/ 


class Solution {
public:
    vector<int> eventualSafeNodes1(vector<vector<int>>& graph) {
        //your code goes here
    }

    vector<int> eventualSafeNodes2(vector<vector<int>>& graph) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<vector<int>> g2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};

    // Method Invocation & Result Visualization
    printVector(sol.eventualSafeNodes1(g1));
    printVector(sol.eventualSafeNodes1(g2));
    printVector(sol.eventualSafeNodes2(g1));
    printVector(sol.eventualSafeNodes2(g2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V+E) | DFS
    # Detect nodes leading into cycles

2. TC: O(V+E) | SC: O(V+E) | Topo / Kahn
    # Reverse edges + indegree based safe nodes
*/
