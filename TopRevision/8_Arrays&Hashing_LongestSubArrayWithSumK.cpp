
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 03, 2026
// Creation TIME: 10:32:31

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver DSA #Longest subarray with sum K

/*
DESCRIPTION :
    Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.


Example 1 :
    Input: nums = [10, 5, 2, 7, 1, 9],  k=15
    Output: 4
    Explanation:
        The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2 :
    Input: nums = [-3, 2, 1], k=6
    Output: 0
    Explanation:
        There is no sub-array in the array that sums to 6. Therefore, the output is 0.


Constraints :
    1 <= n <= 10^5
    -10^5 <= nums[i] <= 10^5
    -10^9 <= k <= 10^9

*/ 


class Solution {
    public:
    int longestSubarrayBrute(vector<int> &nums, int k){
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) 
                    maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }

    int longestSubarrayPositiveAndNegativeOptimal(vector<int> &nums, int k){
        // This approach is most optimal one if the array has poitive & negative
        // This is not the most optimal approach if elements are only +ve in the array
        int maxLen = 0;
        unordered_map<int, int> preSum;
        preSum[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - k;
            if (preSum.find(rem) != preSum.end()) {
                maxLen = max(maxLen, i - preSum[rem]);
            }
            if (preSum.find(sum) == preSum.end()) // required if array has 0s and -ve elements
                preSum[sum] = i;
        }
        return maxLen;
    }

    int longestSubarrayPositivesOnlyOptimised(vector<int> &nums, int k){
        long long maxLen = 0, sum = 0, n = nums.size();
        long long l = 0, r = 0;
        while (r < n) {
            sum += nums[r];
            if (sum > k) {
                while (l <= r && sum > k) {
                    sum -= nums[l];
                    l++;
                }
            }
            if (sum == k)
                maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }


};


int main() 
{
    Solution sol;

    // Input Initialization


    // Method Invocation
    cout << sol.method_name(param1) << endl;



    // Result Visualization



    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

