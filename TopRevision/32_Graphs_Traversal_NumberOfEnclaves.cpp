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

// Striver's Graphs Playlist #NumberOfEnclaves
// https://takeuforward.org/plus/dsa/problems/number-of-enclaves?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-enclaves/

/*
DESCRIPTION :
    Given an m x n binary matrix grid (0 = sea, 1 = land), return the number of land cells that cannot walk off
    the boundary of the grid in any number of 4-directional moves (enclaves).

Example 1:
    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3

Example 2:
    Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    Output: 0

Constraints:
    1 <= m, n <= 500
    grid[i][j] is 0 or 1

*/ 


class Solution {
public:
    int numEnclaves1(vector<vector<int>>& grid) {
        //your code goes here
    }

    int numEnclaves2(vector<vector<int>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    vector<vector<int>> g2 = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};

    // Method Invocation & Result Visualization
    cout << sol.numEnclaves1(g1) << endl;
    cout << sol.numEnclaves1(g2) << endl;
    cout << sol.numEnclaves2(g1) << endl;
    cout << sol.numEnclaves2(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n) | SC: O(m*n) | DFS
    # Mark boundary-connected land, count remaining

2. TC: O(m*n) | SC: O(m*n) | BFS
    # Multi-source BFS from boundary land
*/
