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

// Striver's Graphs Playlist #NumberOfProvinces
// https://takeuforward.org/plus/dsa/problems/number-of-provinces?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-provinces/

/*
DESCRIPTION :
    Given an n x n matrix isConnected where isConnected[i][j] = 1 means city i and city j are directly connected,
    return the total number of provinces (groups of directly or indirectly connected cities).

Example 1:
    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2

Example 2:
    Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    Output: 3

Constraints:
    1 <= n <= 200
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]

*/ 


class Solution {
public:
    int findCircleNum1(vector<vector<int>>& isConnected) {
        //your code goes here
    }

    int findCircleNum2(vector<vector<int>>& isConnected) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> g2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    // Method Invocation & Result Visualization
    cout << sol.findCircleNum1(g1) << endl;
    cout << sol.findCircleNum1(g2) << endl;
    cout << sol.findCircleNum2(g1) << endl;
    cout << sol.findCircleNum2(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^2) | SC: O(N) | DFS/BFS
    # Traverse adjacency matrix components

2. TC: O(N^2) | SC: O(N) | DSU
    # Union connected cities, count parents
*/
