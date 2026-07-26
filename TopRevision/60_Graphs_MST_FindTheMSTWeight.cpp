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

// Striver's Graphs Playlist #FindTheMSTWeight
// https://takeuforward.org/plus/dsa/problems/minimum-spanning-tree?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

/*
DESCRIPTION :
    Given a weighted, undirected and connected graph of V vertices and adjacency list of {neighbor, weight},
    find the sum of weights of the edges of the Minimum Spanning Tree.

Example 1:
    Input: V = 3, edges = [[0,1,5],[1,2,3],[0,2,1]]
    Output: 4

Example 2:
    Input: V = 2, edges = [[0,1,5]]
    Output: 5

Constraints:
    1 <= V <= 1000
    0 <= E <= min(1000, V*(V-1)/2)

*/ 


class Solution {
public:
    int spanningTree1(int V, vector<vector<int>> adj[]) {
        //your code goes here
    }

    int spanningTree2(int V, vector<vector<int>> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 3;
    vector<vector<int>> adj1[3];
    adj1[0] = {{1, 5}, {2, 1}};
    adj1[1] = {{0, 5}, {2, 3}};
    adj1[2] = {{0, 1}, {1, 3}};

    // Method Invocation & Result Visualization
    cout << sol.spanningTree1(V1, adj1) << endl;
    cout << sol.spanningTree2(V1, adj1) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(E log V) | SC: O(V+E) | Prim's Algorithm
    # Priority queue grow MST

2. TC: O(E log E) | SC: O(V) | Kruskal's Algorithm
    # Sort edges + DSU
*/
