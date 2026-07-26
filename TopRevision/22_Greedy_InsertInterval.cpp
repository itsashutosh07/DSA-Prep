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

// Striver's Greedy Playlist #Insert Interval
// https://takeuforward.org/plus/dsa/problems/insert-interval?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval,
    the array represents non-overlapping intervals sorted in ascending order by start[i].
    Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval,
    insert newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].
    Return Intervals after the insertion of newInterval.

Example 1:
    Input: Intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
    Output: [[1, 5], [6, 9]]
    Explanation:
        After inserting the newInterval, the Intervals array becomes [[1, 3], [2, 5], [6, 9]].
        To make them non-overlapping, we merge the intervals [1, 3] and [2, 5].
        Thus, the final Intervals array is [[1, 5], [6, 9]].

Example 2:
    Input: Intervals = [[1, 2], [3, 5], [6, 7], [8, 10]], newInterval = [4, 8]
    Output: [[1, 2], [3, 10]]
    Explanation:
        The Intervals array after inserting newInterval is [[1, 2], [3, 5], [4, 8], [6, 7], [8, 10]].
        We merge the intervals [3, 5], [4, 8], and [6, 7], as they overlap.
        Thus, the final Intervals array is [[1, 2], [3, 10]].

Constraints:
    0 <= Intervals.length <= 10^4
    Intervals[i].length == 2
    Intervals is sorted in ascending order by start[i]
    newInterval.length == 2

*/ 


class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval2 = {4, 8};


    // Method Invocation & Result Visualization
    printMatrix(sol.insertNewInterval(intervals1, newInterval1));
    printMatrix(sol.insertNewInterval(intervals2, newInterval2));


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(n) | SC: O(n) | Greedy
    # Add left non-overlapping, merge overlapping with newInterval, add right non-overlapping

*/
