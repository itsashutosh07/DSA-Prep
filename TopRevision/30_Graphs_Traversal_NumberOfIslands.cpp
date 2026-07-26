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

// Striver's Graphs Playlist #NumberOfIslands
// https://takeuforward.org/plus/dsa/problems/number-of-islands?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-islands/

/*
DESCRIPTION :
    Given an m x n 2D binary grid of '1's (land) and '0's (water), return the number of islands.
    An island is formed by connecting adjacent lands horizontally or vertically.

Example 1:
    Input: grid = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
    Output: 1

Example 2:
    Input: grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
    Output: 3

Constraints:
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'

*/ 


class Solution {
public:
    int numIslands1(vector<vector<char>>& grid) {
        //your code goes here
    }

    int numIslands2(vector<vector<char>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<char>> g1 = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<vector<char>> g2 = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

    // Method Invocation & Result Visualization
    cout << sol.numIslands1(g1) << endl;
    cout << sol.numIslands1(g2) << endl;
    cout << sol.numIslands2(g1) << endl;
    cout << sol.numIslands2(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n) | SC: O(m*n) | DFS
    # Flood each unvisited land cell

2. TC: O(m*n) | SC: O(min(m,n)) | BFS
    # Queue-based flood fill per island
*/
