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

// Striver's Greedy Playlist #Minimum number of platforms required for a railway
// https://takeuforward.org/plus/dsa/problems/minimum-number-of-platforms-required-for-a-railway?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    We are given two arrays that represent the arrival and departure times of trains that stop at the platform.
    We need to find the minimum number of platforms needed at the railway station so that no train has to wait.
    (If a train arrives at the same time another departs, they need different platforms.)

Example 1:
    Input: Arrival = [900, 940, 950, 1100, 1500, 1800], Departure = [910, 1200, 1120, 1130, 1900, 2000]
    Output: 3
    Explanation:
        Between 940-1130, at least 3 trains are present at the station, so 3 platforms are needed.

Example 2:
    Input: Arrival = [900, 1100, 1235], Departure = [1000, 1200, 1240]
    Output: 1
    Explanation:
        No trains overlap in a way that requires more than one platform.

Constraints:
    1 <= n <= 10^5
    0000 <= Arrival[i] <= Departure[i] <= 2359
    Arrival and Departure times are in 24-hour format (HHMM)

*/ 


class Solution {
public:
    int findPlatform1(vector<int>& Arrival, vector<int>& Departure) {
        //your code goes here
    }

    int findPlatform2(vector<int>& Arrival, vector<int>& Departure) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arrival1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure1 = {910, 1200, 1120, 1130, 1900, 2000};
    vector<int> arrival2 = {900, 1100, 1235};
    vector<int> departure2 = {1000, 1200, 1240};


    // Method Invocation & Result Visualization
    cout << sol.findPlatform1(arrival1, departure1) << endl;
    cout << sol.findPlatform1(arrival2, departure2) << endl;

    cout << sol.findPlatform2(arrival1, departure1) << endl;
    cout << sol.findPlatform2(arrival2, departure2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^2) | SC: O(1) | Brute Force
    # For each train, count overlaps with all others

2. TC: O(N*logN) | SC: O(1) | OPTIMIZED
    # Sort arrival and departure, two-pointer sweep for max overlap

*/
