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

// Striver's Graphs Playlist #RottenOranges
// https://takeuforward.org/plus/dsa/problems/rotten-oranges?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/rotting-oranges/

/*
DESCRIPTION :
    You are given an m x n grid where each cell is 0 (empty), 1 (fresh orange), or 2 (rotten orange).
    Every minute, any fresh orange 4-directionally adjacent to a rotten orange becomes rotten.
    Return the minimum minutes until no fresh orange remains, or -1 if impossible.

Example 1:
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

Example 2:
    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1

Constraints:
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2

*/ 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> g2 = {{2,1,1},{0,1,1},{1,0,1}};

    // Method Invocation & Result Visualization
    cout << sol.orangesRotting(g1) << endl;
    cout << sol.orangesRotting(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n) | SC: O(m*n) | Multi-source BFS
    # BFS from all initially rotten oranges
*/
