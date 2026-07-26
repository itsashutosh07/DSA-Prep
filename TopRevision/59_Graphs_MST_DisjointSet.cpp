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

// Striver's Graphs Playlist #DisjointSet
// https://takeuforward.org/plus/dsa/problems/disjoint-set?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

/*
DESCRIPTION :
    Implement a Disjoint Set (Union-Find) data structure supporting findParent with path compression,
    unionByRank and unionBySize. Useful for cycle detection and Kruskal's MST.

Example 1:
    Operations: union(1,2), union(2,3), find(1)==find(3) -> true

Example 2:
    Operations: union(1,2), union(3,4), find(1)==find(4) -> false

Constraints:
    1 <= n <= 10^5
    Number of operations up to 10^5

*/ 


class Solution {
public:
    void unionByRank1(int u, int v) {
        //your code goes here
    }

    void unionBySize2(int u, int v) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    // Implement DisjointSet class helpers inside Solution as needed.
    // Sample usage once you fill the methods:
    // sol.unionByRank1(1, 2);
    // sol.unionBySize2(3, 4);

    // Method Invocation & Result Visualization
    cout << "Fill Disjoint Set implementation" << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(alpha(N)) | SC: O(N) | Union by Rank
    # Path compression + rank

2. TC: O(alpha(N)) | SC: O(N) | Union by Size
    # Path compression + size
*/
