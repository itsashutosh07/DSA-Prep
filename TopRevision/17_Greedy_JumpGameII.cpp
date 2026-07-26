#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 07:48:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Greedy Playlist #Jump Game - II
// https://takeuforward.org/plus/dsa/problems/jump-game-ii?source=strivers-a2z-dsa-track
// https://www.youtube.com/watch?v=7SBVnw7GSTk&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=5
// https://leetcode.com/problems/jump-game-ii/

/*
DESCRIPTION :
    You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
    Each element nums[i] represents the maximum length of a forward jump from index i.
    In other words, if you are at index i, you can jump to any index (i + j) where:
        - 0 <= j <= nums[i] and
        - i + j < n
    Return the minimum number of jumps to reach index n - 1.
    The test cases are generated such that you can reach index n - 1.

Example 1:
    Input: nums = [2, 3, 1, 1, 4]
    Output: 2
    Explanation:
        The minimum number of jumps to reach the last index is 2.
        Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
    Input: nums = [2, 3, 0, 1, 4]
    Output: 2
    Explanation:
        Jump from index 0 to 1, then to the last index. Minimum jumps = 2.

Constraints:
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].

*/ 


class Solution {
public:
    int jump1(vector<int>& nums) {
        //your code goes here
        
    }

    int jump2(vector<int>& nums) {
        //your code goes here
    }

    int jump3(vector<int>& nums) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};


    // Method Invocation & Result Visualization
    cout << sol.jump1(nums1) << endl;
    cout << sol.jump1(nums2) << endl;

    cout << sol.jump2(nums1) << endl;
    cout << sol.jump2(nums2) << endl;

    cout << sol.jump3(nums1) << endl;
    cout << sol.jump3(nums2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(2^N) | SC: O(N) | Brute Force
    # Recursion exploring all jump choices from each index

2. TC: O(N^2) | SC: O(N) | Better
    # DP / tabulation - min jumps to reach each index

3. TC: O(N) | SC: O(1) | OPTIMIZED
    # Greedy range jump (farthest within current jump window)
    # https://www.youtube.com/watch?v=7SBVnw7GSTk&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=5

*/
