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

// Striver's Greedy Playlist #Jump Game - I
// https://takeuforward.org/plus/dsa/problems/jump-game---i?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Given an array where each element represents the maximum number of steps you can jump forward from that element,
    return true if we can reach the last index starting from the first index. Otherwise, return false.

Example 1:
    Input: nums = [2, 3, 1, 0, 4]
    Output: true
    Explanation:
        We start at index 0, with value 2 this means we can jump to index 1 or 2.
        From index 1, with value 3, we can jump to index 2, 3, or 4.
        So we jump to index 1 then index 4 reaching the end of the array.
        Hence, we return true.

Example 2:
    Input: nums = [3, 2, 1, 0, 4]
    Output: false
    Explanation:
        We start at index 0, with value 3 which means we can jump to index 1, 2, or 3.
        From index 1, with value 2 we can only jump to index 2 or 3.
        From index 2, with value 1 we can only jump to index 3.
        From index 3, with value 0 we cannot jump any further.
        Hence, from all possibilities we are unable to jump to the last index so we return false.

Constraints:
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 10^5

*/ 


class Solution {
public:
    bool canJump(vector<int>& nums) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {2, 3, 1, 0, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};


    // Method Invocation & Result Visualization
    cout << boolalpha << sol.canJump(nums1) << endl;
    cout << sol.canJump(nums2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N) | SC: O(1) | Greedy
    # Track farthest reachable index while iterating

*/
