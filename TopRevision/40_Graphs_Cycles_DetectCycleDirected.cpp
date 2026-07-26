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

// Striver's Graphs Playlist #DetectCycleDirected
// https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-a-directed-graph?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

/*
DESCRIPTION :
    Given a Directed Graph with V vertices and adjacency list adj, return true if the graph contains a cycle, otherwise false.

Example 1:
    Input: V = 4, edges = [[0,1],[1,2],[2,3],[3,1]]
    Output: true

Example 2:
    Input: V = 4, edges = [[0,1],[1,2],[2,3]]
    Output: false

Constraints:
    1 <= V <= 10^5
    0 <= E <= 2*10^5

*/ 


class Solution {
public:
    bool isCyclic1(int V, vector<int> adj[]) {
        //your code goes here
    }

    bool isCyclic2(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 4; vector<int> adj1[4] = {{1}, {2}, {3}, {1}};
    int V2 = 4; vector<int> adj2[4] = {{1}, {2}, {3}, {}};

    // Method Invocation & Result Visualization
    cout << boolalpha << sol.isCyclic1(V1, adj1) << endl;
    cout << sol.isCyclic1(V2, adj2) << endl;
    cout << sol.isCyclic2(V1, adj1) << endl;
    cout << sol.isCyclic2(V2, adj2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | DFS
    # Path recursion stack / colors

2. TC: O(V+E) | SC: O(V) | BFS / Kahn's
    # If topo count < V then cycle
*/
