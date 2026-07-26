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

// Striver's Graphs Playlist #TopologicalSort
// https://takeuforward.org/plus/dsa/problems/topological-sort?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/topological-sorting/
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

/*
DESCRIPTION :
    Given a Directed Acyclic Graph (DAG) with V vertices and adjacency list adj, return a valid topological ordering of the vertices.
    Implement both DFS-based topological sort and Kahn's algorithm (BFS / indegree).

Example 1:
    Input: V = 6, edges = [[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
    Output: [4, 5, 0, 2, 3, 1]  (any valid topo order)

Example 2:
    Input: V = 4, edges = [[1,0],[2,0],[3,0]]
    Output: [3, 2, 1, 0]  (any valid topo order)

Constraints:
    1 <= V <= 10^5
    0 <= E <= 10^5
    Graph is a DAG

*/ 


class Solution {
public:
    vector<int> topoSort1(int V, vector<int> adj[]) {
        //your code goes here
    }

    vector<int> topoSort2(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 6; vector<int> adj1[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    // Method Invocation & Result Visualization
    printVector(sol.topoSort1(V1, adj1));
    printVector(sol.topoSort2(V1, adj1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | DFS
    # Post-order stack of finishing times

2. TC: O(V+E) | SC: O(V) | Kahn's Algorithm
    # BFS using indegrees
*/
