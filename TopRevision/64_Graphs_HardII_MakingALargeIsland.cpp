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

// Striver's Graphs Playlist #MakingALargeIsland
// https://takeuforward.org/plus/dsa/problems/making-a-large-island?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/making-a-large-island/

/*
DESCRIPTION :
    You are given an n x n binary matrix grid. You may change at most one 0 to 1.
    Return the size of the largest island after this operation.

Example 1:
    Input: grid = [[1,0],[0,1]]
    Output: 3

Example 2:
    Input: grid = [[1,1],[1,0]]
    Output: 4

Constraints:
    1 <= n <= 500
    grid[i][j] is 0 or 1

*/ 


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{1, 0}, {0, 1}};
    vector<vector<int>> g2 = {{1, 1}, {1, 0}};

    // Method Invocation & Result Visualization
    cout << sol.largestIsland(g1) << endl;
    cout << sol.largestIsland(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(n^2) | DFS/DSU + Paint
    # Label islands with sizes, try flipping each 0
*/
