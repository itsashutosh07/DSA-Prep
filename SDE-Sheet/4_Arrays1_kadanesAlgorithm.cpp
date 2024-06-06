
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 06, 2024
// Creation TIME: 16:29:43

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #53. Maximum Subarray

/*
DESCRIPTION :




Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]
*/ 


class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 {1, 3, 5, 5, 2, 1, 1, 0, 0};
    vector<int> nums2 {1, 3, 5, 5};
    vector<int> nums3 {1, 3, 5, 1, 0, 0};
    vector<int> nums4 {5, 1, 0, 0};
    vector<int> nums5 {1,2,5,7,7,6,6,5,5,4,3,1,1,1,1,0};

    // Method Invocation
    sol.maxSubArray(nums1);
    sol.maxSubArray(nums2);
    sol.maxSubArray(nums3);
    sol.maxSubArray(nums4);
    sol.maxSubArray(nums5);
    // sol.method_name(param2);


    // Result Visualization
    printVector(nums1);
    printVector(nums2);
    printVector(nums3);
    printVector(nums4);
    printVector(nums5);

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

