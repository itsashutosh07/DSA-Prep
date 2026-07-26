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

// Striver's Graphs Playlist #Dijkstra
// https://takeuforward.org/plus/dsa/problems/dijkstras-algorithm?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

/*
DESCRIPTION :
    Given a weighted, undirected and connected graph of V vertices and adjacency list adj where each entry is {neighbor, weight},
    and a source S, find the shortest distance of all vertices from S.

Example 1:
    Input: V = 3, S = 2, edges with weights such that distances from 2 are [4,3,0]
    Output: [4, 3, 0]

Example 2:
    Input: V = 2, S = 0, edge 0-1 weight 9
    Output: [0, 9]

Constraints:
    1 <= V <= 10^4
    0 <= E <= 10^5
    1 <= weight <= 100

*/ 


class Solution {
public:
    vector<int> dijkstra1(int V, vector<vector<int>> adj[], int S) {
        //your code goes here
    }

    vector<int> dijkstra2(int V, vector<vector<int>> adj[], int S) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int V1 = 3, S1 = 2;
    vector<vector<int>> adj1[3];
    adj1[0] = {{1, 1}, {2, 6}};
    adj1[1] = {{2, 3}, {0, 1}};
    adj1[2] = {{1, 3}, {0, 6}};

    // Method Invocation & Result Visualization
    printVector(sol.dijkstra1(V1, adj1, S1));
    printVector(sol.dijkstra2(V1, adj1, S1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O((V+E) log V) | SC: O(V) | Priority Queue
    # Binary heap Dijkstra

2. TC: O((V+E) log V) | SC: O(V) | Set-based
    # std::set Dijkstra with erase/update
*/
