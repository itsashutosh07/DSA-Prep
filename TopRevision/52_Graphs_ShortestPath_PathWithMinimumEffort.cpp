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

// Striver's Graphs Playlist #PathWithMinimumEffort
// https://takeuforward.org/plus/dsa/problems/path-with-minimum-effort?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/path-with-minimum-effort/

/*
DESCRIPTION :
    You are given heights, a 2D array of size rows x columns. Start at (0,0) and go to (rows-1, columns-1).
    Effort of a path is the maximum absolute difference between consecutive cells.
    Return the minimum effort required to travel from top-left to bottom-right.

Example 1:
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2

Example 2:
    Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    Output: 1

Constraints:
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 10^6

*/ 


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> h1 = {{1,2,2},{3,8,2},{5,3,5}};
    vector<vector<int>> h2 = {{1,2,3},{3,8,4},{5,3,5}};

    // Method Invocation & Result Visualization
    cout << sol.minimumEffortPath(h1) << endl;
    cout << sol.minimumEffortPath(h2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(m*n log(m*n)) | SC: O(m*n) | Dijkstra
    # Priority queue on effort difference
*/
