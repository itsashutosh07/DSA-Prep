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

// Striver's Graphs Playlist #ShortestDistanceBinaryMaze
// https://takeuforward.org/plus/dsa/problems/shortest-distance-in-a-binary-maze?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

/*
DESCRIPTION :
    Given an n * m binary matrix grid (1 traversable, 0 blocked), a source and a destination,
    return the shortest distance from source to destination with 4-directional moves, or -1 if impossible.

Example 1:
    Input: grid = [[1,1,1,1],[1,1,0,1],[1,1,1,1],[1,1,0,0],[1,0,0,1]], source = [0,0], destination = [2,3]
    Output: 6

Example 2:
    Input: grid = [[1,1,1,1],[0,0,0,1],[1,1,1,1]], source = [0,0], destination = [0,3]
    Output: 3

Constraints:
    1 <= n, m <= 100
    grid[i][j] is 0 or 1

*/ 


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, pair<int,int> source, pair<int,int> destination) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,1}};

    // Method Invocation & Result Visualization
    cout << sol.shortestPath(g1, {0, 0}, {2, 3}) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(n*m) | BFS
    # Unit cost grid BFS
*/
