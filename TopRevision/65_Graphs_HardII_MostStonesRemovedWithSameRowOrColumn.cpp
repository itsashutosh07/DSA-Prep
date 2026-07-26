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

// Striver's Graphs Playlist #MostStonesRemovedWithSameRowOrColumn
// https://takeuforward.org/plus/dsa/problems/most-stones-removed-with-same-row-or-column?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

/*
DESCRIPTION :
    On a 2D plane, n stones are at distinct coordinates stones[i] = [xi, yi].
    A stone can be removed if it shares a row or column with another stone that has not been removed.
    Return the largest possible number of stones that can be removed.

Example 1:
    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    Output: 5

Example 2:
    Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
    Output: 3

Constraints:
    1 <= stones.length <= 1000
    0 <= xi, yi <= 10^4

*/ 


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> s1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    vector<vector<int>> s2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};

    // Method Invocation & Result Visualization
    cout << sol.removeStones(s1) << endl;
    cout << sol.removeStones(s2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N * alpha(N)) | SC: O(N) | DSU
    # Answer = N - number of connected components
*/
