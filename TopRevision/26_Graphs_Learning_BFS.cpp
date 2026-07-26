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

// Striver's Graphs Playlist #BFS
// https://takeuforward.org/plus/dsa/problems/bfs?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

/*
DESCRIPTION :
    Breadth First Search (BFS) is a graph traversal algorithm that visits nodes level by level starting from a given source.
    Given an undirected graph with V vertices and adjacency list adj, perform BFS traversal starting from node 0 and return the order of visited nodes.

Example 1:
    Input: V = 5, adj = [[2,3,1],[0],[0,4],[0],[2]]
    Output: [0, 2, 3, 1, 4]

Example 2:
    Input: V = 3, adj = [[1],[0,2],[1]]
    Output: [0, 1, 2]

Constraints:
    1 <= V <= 10^4
    0 <= E <= 10^4

*/ 


class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
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
    printVector(sol.bfsOfGraph(V1, adj1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | BFS
    # Queue-based level order traversal
*/
