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

// Striver's Graphs Playlist #PrintShortestPath
// https://takeuforward.org/plus/dsa/problems/print-shortest-path?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/

/*
DESCRIPTION :
    You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges.
    Find any shortest path between vertex 1 and vertex n. If none exists return [-1].

Example 1:
    Input: n = 5, m = 6, edges = [[1,2,2],[2,5,5],[2,3,4],[1,4,1],[4,3,3],[3,5,1]]
    Output: [1, 4, 3, 5]

Example 2:
    Input: n = 2, m = 1, edges = [[1,2,1]]
    Output: [1, 2]

Constraints:
    2 <= n <= 10^5
    0 <= m <= 10^5

*/ 


class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> e1 = {{1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}};

    // Method Invocation & Result Visualization
    printVector(sol.shortestPath(5, 6, e1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O((V+E) log V) | SC: O(V+E) | Dijkstra + Parent
    # Track parent array while running Dijkstra
*/
