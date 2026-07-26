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

// Striver's Graphs Playlist #NumberOfOperationsToMakeNetworkConnected
// https://takeuforward.org/plus/dsa/problems/number-of-operations-to-make-network-connected?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

/*
DESCRIPTION :
    There are n computers (0 to n-1) and connections[i] = [ai, bi] cables.
    Return the minimum number of cable moves to make all computers connected, or -1 if impossible.

Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1

Example 2:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2

Constraints:
    1 <= n <= 10^5
    1 <= connections.length <= min(n*(n-1)/2, 10^5)

*/ 


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> c1 = {{0,1},{0,2},{1,2}};
    vector<vector<int>> c2 = {{0,1},{0,2},{0,3},{1,2},{1,3}};

    // Method Invocation & Result Visualization
    cout << sol.makeConnected(4, c1) << endl;
    cout << sol.makeConnected(6, c2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N+E) | SC: O(N) | DSU
    # Extra edges >= components-1
*/
