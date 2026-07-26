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

// Striver's Graphs Playlist #DetectCycleUndirected
// https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-an-undirected-graph?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

/*
DESCRIPTION :
    Given an undirected graph with V vertices and adjacency list adj, return true if the graph contains a cycle, otherwise false.

Example 1:
    Input: V = 5, edges form a cycle through node 1
    Output: true

Example 2:
    Input: V = 3, edges = [[0,1],[1,2]]
    Output: false

Constraints:
    1 <= V <= 10^5
    0 <= E <= 2*10^5

*/ 


class Solution {
public:
    bool isCycle1(int V, vector<int> adj[]) {
        //your code goes here
    }

    bool isCycle2(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 5; vector<int> adj1[5] = {{1}, {0, 2, 4}, {1, 3}, {2}, {1}};
    int V2 = 3; vector<int> adj2[3] = {{1}, {0, 2}, {1}};

    // Method Invocation & Result Visualization
    cout << boolalpha << sol.isCycle1(V1, adj1) << endl;
    cout << sol.isCycle1(V2, adj2) << endl;
    cout << sol.isCycle2(V1, adj1) << endl;
    cout << sol.isCycle2(V2, adj2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | BFS
    # Parent tracking during BFS

2. TC: O(V+E) | SC: O(V) | DFS
    # Parent tracking during DFS
*/
