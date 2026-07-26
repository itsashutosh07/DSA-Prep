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

// Striver's Graphs Playlist #FloydWarshall
// https://takeuforward.org/plus/dsa/problems/floyd-warshall-algorithm?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

/*
DESCRIPTION :
    Find shortest distances between every pair of vertices in an edge-weighted directed graph.
    matrix[i][j] is edge weight; -1 means no edge. Modify matrix in-place to store shortest distances.

Example 1:
    Input: matrix = [[0,1,43],[-1,0,6],[-1,-1,0]]
    Output: [[0,1,7],[-1,0,6],[-1,-1,0]]

Example 2:
    Input: matrix = [[0,-1],[1,0]]
    Output: [[0,-1],[1,0]]

Constraints:
    1 <= n <= 100
    -1 <= matrix[i][j] <= 1000

*/ 


class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> m1 = {{0, 1, 43}, {-1, 0, 6}, {-1, -1, 0}};
    vector<vector<int>> m2 = {{0, -1}, {1, 0}};

    // Method Invocation & Result Visualization
    sol.shortest_distance(m1); printMatrix(m1);
    sol.shortest_distance(m2); printMatrix(m2);

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^3) | SC: O(1) | Floyd-Warshall
    # Triple loop DP over intermediate nodes
*/
