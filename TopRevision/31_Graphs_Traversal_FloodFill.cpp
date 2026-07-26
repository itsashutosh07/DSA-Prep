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

// Striver's Graphs Playlist #FloodFill
// https://takeuforward.org/plus/dsa/problems/flood-fill-algorithm?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/flood-fill/

/*
DESCRIPTION :
    An image is represented by an m x n integer grid. Starting at (sr, sc), replace the color of the starting pixel
    and all 4-directionally connected pixels with the same original color with the given color. Return the modified image.

Example 1:
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]

Example 2:
    Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
    Output: [[0,0,0]]

Constraints:
    1 <= m, n <= 50
    0 <= image[i][j], color < 2^16
    0 <= sr < m, 0 <= sc < n

*/ 


class Solution {
public:
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int color) {
        //your code goes here
    }

    vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int color) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> img1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> img2 = {{0, 0, 0}, {0, 0, 0}};

    // Method Invocation & Result Visualization
    printMatrix(sol.floodFill1(img1, 1, 1, 2));
    printMatrix(sol.floodFill1(img2, 0, 0, 0));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n) | SC: O(m*n) | DFS
    # Recolor connected same-color pixels

2. TC: O(m*n) | SC: O(m*n) | BFS
    # Queue-based flood fill
*/
