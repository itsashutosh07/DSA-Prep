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

// Striver's Graphs Playlist #ShortestPathInDAG
// https://takeuforward.org/plus/dsa/problems/shortest-path-in-dag?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

/*
DESCRIPTION :
    Given a DAG of N vertices (0 to N-1) and edges where edges[i] = [u, v, wt],
    find the shortest path from source 0 to all nodes. Unreachable nodes have distance -1.

Example 1:
    Input: N = 6, edges = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
    Output: [0, 2, 3, 6, 1, 5]

Example 2:
    Input: N = 3, edges = [[0,1,2],[1,2,3]]
    Output: [0, 2, 5]

Constraints:
    1 <= N <= 100
    1 <= edges.length <= min(N*(N-1)/2, 100)

*/ 


class Solution {
public:
    vector<int> shortestPath(int N, vector<vector<int>>& edges) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> e1 = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

    // Method Invocation & Result Visualization
    printVector(sol.shortestPath(6, e1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N+E) | SC: O(N+E) | Topo + Relaxation
    # Topo order then relax edges in order
*/
