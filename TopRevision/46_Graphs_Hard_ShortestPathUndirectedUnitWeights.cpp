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

// Striver's Graphs Playlist #ShortestPathUndirectedUnitWeights
// https://takeuforward.org/plus/dsa/problems/shortest-path-in-undirected-graph-with-unit-weights?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/shortest-path-unweighted-graph/

/*
DESCRIPTION :
    Given an undirected graph of N vertices (0 to N-1) with unit edge weights and source src,
    return shortest distances from src to all nodes. Unreachable nodes have distance -1.

Example 1:
    Input: N = 9, edges = [[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]], src = 0
    Output: [0,1,2,1,2,3,3,4,4]

Example 2:
    Input: N = 4, edges = [[0,1],[1,2]], src = 0
    Output: [0,1,2,-1]

Constraints:
    1 <= N <= 10^4
    0 <= edges.length <= 10^4

*/ 


class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int src) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> e1 = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

    // Method Invocation & Result Visualization
    printVector(sol.shortestPath(e1, 9, 0));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N+E) | SC: O(N+E) | BFS
    # Unit-weight shortest path via BFS
*/
