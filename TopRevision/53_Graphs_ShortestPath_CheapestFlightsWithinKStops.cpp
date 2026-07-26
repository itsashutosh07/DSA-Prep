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

// Striver's Graphs Playlist #CheapestFlightsWithinKStops
// https://takeuforward.org/plus/dsa/problems/cheapest-flights-within-k-stops?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

/*
DESCRIPTION :
    There are n cities connected by flights where flights[i] = [fromi, toi, pricei].
    Return the cheapest price from src to dst with at most k stops. If no such route exists, return -1.

Example 1:
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700

Example 2:
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200

Constraints:
    1 <= n <= 100
    0 <= flights.length <= n*(n-1)/2
    0 <= k < n

*/ 


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> f1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    vector<vector<int>> f2 = {{0,1,100},{1,2,100},{0,2,500}};

    // Method Invocation & Result Visualization
    cout << sol.findCheapestPrice(4, f1, 0, 3, 1) << endl;
    cout << sol.findCheapestPrice(3, f2, 0, 2, 1) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(k*(V+E)) | SC: O(V) | Bellman-Ford / BFS-PQ
    # Relax edges up to k+1 times / Dijkstra with stops
*/
