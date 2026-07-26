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

// Striver's Graphs Playlist #Kosaraju
// https://takeuforward.org/plus/dsa/problems/kosarajus-algorithm?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/strongly-connected-components/

/*
DESCRIPTION :
    Given a directed graph with V vertices and adjacency list adj, find the number of Strongly Connected Components (SCCs) using Kosaraju's algorithm.

Example 1:
    Input: V = 5, edges = [[1,0],[0,2],[2,1],[0,3],[3,4]]
    Output: 3

Example 2:
    Input: V = 3, edges = [[0,1],[1,2]]
    Output: 3

Constraints:
    1 <= V <= 10^4
    0 <= E <= 10^4

*/ 


class Solution {
public:
    int kosaraju(int V, vector<int> adj[]) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 5; vector<int> adj1[5] = {{2, 3}, {0}, {1}, {4}, {}};

    // Method Invocation & Result Visualization
    cout << sol.kosaraju(V1, adj1) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V+E) | Kosaraju's Algorithm
    # DFS order + transpose graph DFS
*/
