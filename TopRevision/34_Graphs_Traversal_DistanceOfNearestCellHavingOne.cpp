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

// Striver's Graphs Playlist #DistanceOfNearestCellHavingOne
// https://takeuforward.org/plus/dsa/problems/distance-of-nearest-cell-having-1?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/distance-nearest-cell-1-binary-matrix/
// https://leetcode.com/problems/01-matrix/

/*
DESCRIPTION :
    Given a binary grid of n*m, find the distance of the nearest 1 for each cell.
    Distance is |i1 - i2| + |j1 - j2|. Return a matrix of the same size with these distances.

Example 1:
    Input: grid = [[0,1,1,0],[1,1,0,0],[0,0,1,1]]
    Output: [[1,0,0,1],[0,0,1,1],[1,1,0,0]]

Example 2:
    Input: grid = [[1,0,1],[1,1,0],[1,0,0]]
    Output: [[0,1,0],[0,0,1],[0,1,2]]

Constraints:
    1 <= n, m <= 500
    grid[i][j] is 0 or 1
    At least one 1 exists in the grid

*/ 


class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    vector<vector<int>> g2 = {{1,0,1},{1,1,0},{1,0,0}};

    // Method Invocation & Result Visualization
    printMatrix(sol.nearest(g1));
    printMatrix(sol.nearest(g2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(n*m) | Multi-source BFS
    # BFS from all cells having 1
*/
