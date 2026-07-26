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

// Striver's Graphs Playlist #NumberOfWaysToArriveAtDestination
// https://takeuforward.org/plus/dsa/problems/number-of-ways-to-arrive-at-destination?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

/*
DESCRIPTION :
    You are given n intersections (0 to n-1) and roads[i] = [ui, vi, timei] bidirectional roads.
    Return the number of ways to arrive at n-1 from 0 in the shortest time, modulo 10^9 + 7.

Example 1:
    Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    Output: 4

Example 2:
    Input: n = 2, roads = [[1,0,10]]
    Output: 1

Constraints:
    1 <= n <= 200
    n - 1 <= roads.length <= n*(n-1)/2

*/ 


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> r1 = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    vector<vector<int>> r2 = {{1, 0, 10}};

    // Method Invocation & Result Visualization
    cout << sol.countPaths(7, r1) << endl;
    cout << sol.countPaths(2, r2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O((V+E) log V) | SC: O(V+E) | Dijkstra + DP
    # Track ways[] while computing shortest distances
*/
