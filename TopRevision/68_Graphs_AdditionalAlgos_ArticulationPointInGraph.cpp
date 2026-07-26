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

// Striver's Graphs Playlist #ArticulationPointInGraph
// https://takeuforward.org/plus/dsa/problems/articulation-point-in-graph?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

/*
DESCRIPTION :
    Given an undirected connected graph with V vertices and adjacency list adj, find all Articulation Points.
    An articulation point is a vertex whose removal increases the number of connected components.
    Return a sorted list of articulation points, or [-1] if none exist.

Example 1:
    Input: V = 5, adj = [[1],[0,4],[3,4],[2],[1,2]]
    Output: [1, 4]

Example 2:
    Input: V = 4, edges form a simple cycle
    Output: [-1]

Constraints:
    1 <= V <= 10^5
    0 <= E <= 10^5

*/ 


class Solution {
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 5; vector<int> adj1[5] = {{1}, {0, 4}, {3, 4}, {2}, {1, 2}};
    int V2 = 4; vector<int> adj2[4] = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    // Method Invocation & Result Visualization
    printVector(sol.articulationPoints(V1, adj1));
    printVector(sol.articulationPoints(V2, adj2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | Tarjan's / DFS tin-low
    # Root with >=2 children or low[child] >= tin[node]
*/
