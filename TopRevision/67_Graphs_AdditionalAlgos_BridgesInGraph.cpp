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

// Striver's Graphs Playlist #BridgesInGraph
// https://takeuforward.org/plus/dsa/problems/bridges-in-graph?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/critical-connections-in-a-network/
// https://www.geeksforgeeks.org/bridge-in-a-graph/

/*
DESCRIPTION :
    Given an undirected connected graph, find all bridges (critical connections).
    A bridge is an edge whose removal increases the number of connected components.

Example 1:
    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]

Example 2:
    Input: n = 2, connections = [[0,1]]
    Output: [[0,1]]

Constraints:
    1 <= n <= 10^5
    0 <= connections.length <= 10^5

*/ 


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> c1 = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> c2 = {{0,1}};

    // Method Invocation & Result Visualization
    printMatrix(sol.criticalConnections(4, c1));
    printMatrix(sol.criticalConnections(2, c2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V+E) | Tarjan's / DFS tin-low
    # Bridge if low[child] > tin[node]
*/
