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

// Striver's Graphs Playlist #BellmanFord
// https://takeuforward.org/plus/dsa/problems/bellman-ford-algorithm?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

/*
DESCRIPTION :
    Given a weighted directed graph with V vertices and edges[i] = [u, v, wt], and source S,
    find shortest distances from S. Unreachable distance is 1e8. If a negative cycle is reachable from S, return {-1}.

Example 1:
    Input: V = 3, edges = [[0,1,5],[1,2,-3],[0,2,10]], S = 0
    Output: [0, 5, 2]

Example 2:
    Input: Graph with a negative weight cycle reachable from S
    Output: [-1]

Constraints:
    1 <= V <= 500
    0 <= E <= V*(V-1)
    -1000 <= wt <= 1000

*/ 


class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> e1 = {{0, 1, 5}, {1, 2, -3}, {0, 2, 10}};

    // Method Invocation & Result Visualization
    printVector(sol.bellmanFord(3, e1, 0));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V*E) | SC: O(V) | Bellman-Ford
    # Relax all edges V-1 times; one more for negative cycle
*/
