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

// Striver's Graphs Playlist #ConnectedComponents
// https://takeuforward.org/plus/dsa/problems/connected-components?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/

/*
DESCRIPTION :
    Given an undirected graph with V vertices and a list of edges, find the number of connected components.
    A connected component is a maximal set of vertices such that there is a path between every pair of vertices.

Example 1:
    Input: V = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2

Example 2:
    Input: V = 4, edges = [[0,1],[2,3]]
    Output: 2

Constraints:
    1 <= V <= 10^5
    0 <= E <= 10^5

*/ 


class Solution {
public:
    int findNumberOfComponent(int V, vector<vector<int>>& edges) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {3, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {2, 3}};

    // Method Invocation & Result Visualization
    cout << sol.findNumberOfComponent(5, edges1) << endl;
    cout << sol.findNumberOfComponent(4, edges2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(V+E) | SC: O(V) | DFS/BFS
    # Count components via traversal or DSU
*/
