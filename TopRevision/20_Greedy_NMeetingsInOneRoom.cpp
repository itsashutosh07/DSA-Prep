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

// Striver's Greedy Playlist #N Meetings in One Room
// https://takeuforward.org/plus/dsa/problems/n-meetings-in-one-room?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    There is one meeting room in a firm. You are given two arrays, start and end each of size N.
    For an index i, start[i] denotes the starting time of the ith meeting while end[i] denotes the ending time of the ith meeting.
    Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time.

Example 1:
    Input: start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation:
        Meetings that can be performed: (1,2), (3,4), (5,7), (8,9)
        Maximum meetings = 4

Example 2:
    Input: start = [10, 12, 20], end = [20, 25, 30]
    Output: 1
    Explanation:
        Only one meeting can be held in the room at a time.
        Maximum meetings = 1

Constraints:
    1 <= N <= 10^5
    0 <= start[i] < end[i] <= 10^9

*/ 


class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> end1 = {2, 4, 6, 7, 9, 9};
    vector<int> start2 = {10, 12, 20};
    vector<int> end2 = {20, 25, 30};


    // Method Invocation & Result Visualization
    cout << sol.maxMeetings(start1, end1) << endl;
    cout << sol.maxMeetings(start2, end2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N*logN) + O(N) | SC: O(N) | Greedy
    # Sort meetings by end time, pick next non-overlapping meeting

*/
