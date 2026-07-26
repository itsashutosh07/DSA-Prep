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

// Striver's Graphs Playlist #BipartiteGraph
// https://takeuforward.org/plus/dsa/problems/bipartite-graph?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/is-graph-bipartite/

/*
DESCRIPTION :
    Given an undirected graph with V vertices and adjacency list adj, check whether the graph is bipartite.
    A graph is bipartite if vertices can be divided into two independent sets such that every edge connects different sets.

Example 1:
    Input: V = 4, edges create an odd cycle
    Output: false

Example 2:
    Input: V = 3, edges = [[0,1],[1,2]]
    Output: true

Constraints:
    1 <= V <= 10^5
    0 <= E <= 2*10^5

*/ 


class Solution {
public:
    bool isBipartite1(int V, vector<int> adj[]) {
        //your code goes here
    }

    bool isBipartite2(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 4; vector<int> adj1[4] = {{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    int V2 = 3; vector<int> adj2[3] = {{1}, {0, 2}, {1}};

    // Method Invocation & Result Visualization
    cout << boolalpha << sol.isBipartite1(V1, adj1) << endl;
    cout << sol.isBipartite1(V2, adj2) << endl;
    cout << sol.isBipartite2(V1, adj1) << endl;
    cout << sol.isBipartite2(V2, adj2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | BFS Coloring
    # 2-color graph using BFS

2. TC: O(V+E) | SC: O(V) | DFS Coloring
    # 2-color graph using DFS
*/
