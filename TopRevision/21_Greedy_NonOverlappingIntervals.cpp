#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 07:40:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Greedy Playlist #Non-overlapping Intervals
// https://takeuforward.org/plus/dsa/problems/non-overlapping-intervals?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Given an array of N intervals in the form of (start[i], end[i]), where start[i] is the starting point of the interval and end[i] is the ending point of the interval,
    return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping.

Example 1:
    Input: intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
    Output: 1
    Explanation:
        Remove [1, 3] so that the remaining intervals are non-overlapping: [1, 2], [2, 3], [3, 4]

Example 2:
    Input: intervals = [[1, 2], [1, 2], [1, 2]]
    Output: 2
    Explanation:
        Remove two of the [1, 2] intervals to make the remaining intervals non-overlapping.

Constraints:
    1 <= intervals.length <= 10^5
    intervals[i].length == 2
    -5 * 10^4 <= start[i] < end[i] <= 5 * 10^4

*/ 


class Solution {
public:
    int MaximumNonOverlappingIntervals1(vector<vector<int>>& Intervals) {
        //your code goes here
    }

    int MaximumNonOverlappingIntervals2(vector<vector<int>>& Intervals) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};


    // Method Invocation & Result Visualization
    cout << sol.MaximumNonOverlappingIntervals1(intervals1) << endl;
    cout << sol.MaximumNonOverlappingIntervals1(intervals2) << endl;

    cout << sol.MaximumNonOverlappingIntervals2(intervals1) << endl;
    cout << sol.MaximumNonOverlappingIntervals2(intervals2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(2^N * N log N) | SC: O(N) | Brute Force
    # Generate all subsets and check non-overlapping

2. TC: O(n log n) | SC: O(1) | OPTIMIZED
    # Sort by end time, greedily keep max non-overlapping (answer = N - kept)

*/
