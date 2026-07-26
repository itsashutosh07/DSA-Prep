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

// Striver's Graphs Playlist #FindTheCityWithSmallestNumberOfNeighbors
// https://takeuforward.org/plus/dsa/problems/find-the-city-with-the-smallest-number-of-neighbors?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

/*
DESCRIPTION :
    There are n cities numbered 0 to n-1 and bidirectional weighted edges.
    Return the city with the smallest number of reachable cities within distanceThreshold.
    If ties, return the city with the greatest number.

Example 1:
    Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    Output: 3

Example 2:
    Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
    Output: 0

Constraints:
    2 <= n <= 100
    1 <= edges.length <= n*(n-1)/2
    1 <= distanceThreshold <= 10^4

*/ 


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> e1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    vector<vector<int>> e2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};

    // Method Invocation & Result Visualization
    cout << sol.findTheCity(4, e1, 4) << endl;
    cout << sol.findTheCity(5, e2, 2) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^3) | SC: O(N^2) | Floyd-Warshall
    # All-pairs distances then count neighbors per city
*/
