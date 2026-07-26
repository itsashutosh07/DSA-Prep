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

// Striver's Graphs Playlist #MinimumMultiplicationsToReachEnd
// https://takeuforward.org/plus/dsa/problems/minimum-multiplications-to-reach-end?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://www.geeksforgeeks.org/minimum-multiplications-start-end-array-multiplication/

/*
DESCRIPTION :
    Given start, end and an array arr. In one operation multiply start by any number from arr and take modulo 100000.
    Find the minimum number of multiplications to convert start to end. Return -1 if impossible.

Example 1:
    Input: start = 3, end = 30, arr = [2,5,7]
    Output: 2

Example 2:
    Input: start = 7, end = 661751, arr = [3,4,65]
    Output: 4

Constraints:
    1 <= arr.length <= 10^4
    1 <= arr[i], start, end <= 10^5

*/ 


class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {2, 5, 7};
    vector<int> arr2 = {3, 4, 65};

    // Method Invocation & Result Visualization
    cout << sol.minimumMultiplications(arr1, 3, 30) << endl;
    cout << sol.minimumMultiplications(arr2, 7, 661751) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(100000 * n) | SC: O(100000) | BFS / Dijkstra
    # States are residues mod 100000
*/
