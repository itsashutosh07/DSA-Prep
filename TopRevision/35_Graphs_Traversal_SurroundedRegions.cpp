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

// Striver's Graphs Playlist #SurroundedRegions
// https://takeuforward.org/plus/dsa/problems/surrounded-regions?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/surrounded-regions/

/*
DESCRIPTION :
    Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'
    by flipping those 'O's to 'X'. Any 'O' on the border (or connected to a border 'O') cannot be captured.

Example 1:
    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Example 2:
    Input: board = [["X"]]
    Output: [["X"]]

Constraints:
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'

*/ 


class Solution {
public:
    void solve1(vector<vector<char>>& board) {
        //your code goes here
    }

    void solve2(vector<vector<char>>& board) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<char>> b1 = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char>> b2 = {{'X'}};

    // Method Invocation & Result Visualization
    sol.solve1(b1); printMatrix(b1);
    sol.solve1(b2); printMatrix(b2);

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n) | SC: O(m*n) | DFS
    # Mark border-connected O, flip remaining O to X

2. TC: O(m*n) | SC: O(m*n) | BFS
    # Multi-source BFS from border O cells
*/
