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

// Striver's Graphs Playlist #DFS
// https://takeuforward.org/plus/dsa/problems/dfs?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

/*
DESCRIPTION :
    Depth First Search (DFS) explores as far as possible along each branch before backtracking.
    Given an undirected graph with V vertices and adjacency list adj, perform DFS traversal starting from node 0 and return the order of visited nodes.

Example 1:
    Input: V = 5, adj = [[2,3,1],[0],[0,4],[0],[2]]
    Output: [0, 2, 4, 3, 1]

Example 2:
    Input: V = 4, adj = [[1,3],[0,2],[1],[0]]
    Output: [0, 1, 2, 3]

Constraints:
    1 <= V <= 10^4
    0 <= E <= 10^4

*/ 


class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 5;
    vector<int> adj1[5] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    // Method Invocation & Result Visualization
    printVector(sol.dfsOfGraph(V1, adj1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | DFS
    # Recursive / stack-based depth traversal
*/
