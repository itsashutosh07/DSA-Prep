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

// Striver's Graphs Playlist #NumberOfDistinctIslands
// https://takeuforward.org/plus/dsa/problems/number-of-distinct-islands?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/find-number-distinct-islands-set-1/
// https://leetcode.com/problems/number-of-distinct-islands/

/*
DESCRIPTION :
    Given a boolean 2D matrix grid of size n * m, find the number of distinct islands where an island is a group of connected 1s
    (4-directionally). Two islands are distinct if and only if one is not equal to another (not considering rotation/reflection).

Example 1:
    Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    Output: 1

Example 2:
    Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
    Output: 3

Constraints:
    1 <= n, m <= 50
    grid[i][j] is 0 or 1

*/ 


class Solution {
public:
    int countDistinctIslands1(vector<vector<int>>& grid) {
        //your code goes here
    }

    int countDistinctIslands2(vector<vector<int>>& grid) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> g1 = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    vector<vector<int>> g2 = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};

    // Method Invocation & Result Visualization
    cout << sol.countDistinctIslands1(g1) << endl;
    cout << sol.countDistinctIslands1(g2) << endl;
    cout << sol.countDistinctIslands2(g1) << endl;
    cout << sol.countDistinctIslands2(g2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(n*m) | DFS + HashSet
    # Store relative path/signature of each island

2. TC: O(n*m) | SC: O(n*m) | BFS + HashSet
    # Same idea with BFS traversal signature
*/
