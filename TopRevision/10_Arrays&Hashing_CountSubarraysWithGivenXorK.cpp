
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: May 26, 2026
// Creation TIME: 10:41:35

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's-79 #Count of subarrays with XOR as K

/*
DESCRIPTION :
    Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.


Example 1
    Input : nums = [4, 2, 2, 6, 4], k = 6
    Output : 4
    Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

Example 2
    Input :nums = [5, 6, 7, 8, 9], k = 5
    Output : 2
    Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


Constraints
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    1 <= k <= 10^9

*/ 


class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {4, 2, 2, 6, 4};
    int k1 = 6;
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int k2 = 5;

    // Method Invocation & Result Visualization
    cout << sol.subarraysWithXorK(nus1, k1) << endl;
    cout << sol.subarraysWithXorK(nums2, k2) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

