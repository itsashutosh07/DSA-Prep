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

// Striver's Graphs Playlist #NumberOfIslandsII
// https://takeuforward.org/plus/dsa/problems/number-of-islands-ii?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-islands-ii/

/*
DESCRIPTION :
    You are given an empty m x n binary grid and positions where land is added over time.
    After each land addition, return the number of islands. Return ans where ans[i] is islands after the ith addition.

Example 1:
    Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
    Output: [1,1,2,3]

Example 2:
    Input: m = 1, n = 1, positions = [[0,0]]
    Output: [1]

Constraints:
    1 <= m, n <= 10^4
    1 <= positions.length <= min(m*n, 10^4)

*/ 


class Solution {
public:
    vector<int> numIslandsII(int m, int n, vector<vector<int>>& positions) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> p1 = {{0,0},{0,1},{1,2},{2,1}};

    // Method Invocation & Result Visualization
    printVector(sol.numIslandsII(3, 3, p1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(K * alpha(m*n)) | SC: O(m*n) | DSU
    # Add land cells online and union with neighbors
*/
