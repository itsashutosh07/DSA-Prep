
#include <bits/stdc++.h>
#include "../dgb.hpp"

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
    Given an integer array nums, find the subarray with the largest sum, and return its sum.

Constraints:
    -   1 <= nums.length <= 10^5
    -   -10^4 <= nums[i] <= 10^4

Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]
*/ 


class Solution {
    public:
    int maxSubArray1(vector<int>& nums) {
        int n = nums.size(), curr = INT_MIN, ans = nums[0];

        for (int i = 0; i < n; i++) {
            curr = nums[i];
            if (curr > ans) ans = curr;
            for (int j = i+1; j < n; j++) {
                curr += nums[j];
                if (curr > ans) ans = curr;
            }
        }
        return ans;
        
    }

    int maxSubArray2(vector<int>& nums) {
        int n = nums.size(), currSum = nums[0], maxSum = nums[0];
        int s = 0; // potential start
        int start = 0, end = 0; // actual start & end
        for (int i = 1; i < n; i++) {
            // Kadane's Algorithm
            if (currSum < 0) {
                currSum = nums[i];
                s = i;
            }
            else {
                currSum += nums[i];
            }
            /* 
            // NORMAL CASE CODE
            // Simply update max_sum if curr_sum is greater than max_sum
            if (currSum > maxSum) { 
                maxSum = currSum;     
            }
            */

            // FOLLOW-UP CASE TO ALSO PRINT : MAX SUM LONGEST SUB-ARRAY
            if (currSum > maxSum) { // update maxSum if currSum is greater
                maxSum = currSum;       
                printf("%d %d %d %d\n", i, s, end, start); // additional check to only update when 
                start = s;
                end = i;
                
            } else if (currSum == maxSum && (i - s) > (end - start)) { // updated maxSum is equal to currSum
                // additional check to only update start and end if longer sub-string is present
                printf("%d %d %d %d\n", i, s, end, start);
                start = s;
                end = i;
            }
        }

        // Print maximum subarray
        cout << "Maximum subarray: ";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl << "Max Sum: ";
        return maxSum;
    }

};


int main() 
{
    Solution sol;
    // Input Initialization
    vector<int> nums1 {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 {1};
    vector<int> nums3 {5,4,-1,7,8};
    vector<int> nums4 {-10};
    vector<int> nums5 {1,2,5,-7,7,6,-6,5,-15,-4,-3,1,1,1,8,3,-3};

    // Method Invocation & Result Visualization
    // cout << sol.maxSubArray2(nums1) << endl << endl;
    // cout << sol.maxSubArray2(nums2) << endl << endl;
    // cout << sol.maxSubArray2(nums3) << endl << endl;
    // cout << sol.maxSubArray2(nums4) << endl << endl;
    cout << sol.maxSubArray2(nums5) << endl << endl;
    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^2) TC | Brute Force
    - use two pointer i,j approach to generate all possible find all contagious sub-arrays 
    - find curr_sum for each starting element arr[i]
    - updte max_sum if curr_sum > max_sum
    - returm max_sum  

2. O(1) extra space & O(n) TC | OPTIMIZED
    - Watch pepCoding video on kadane's Algo
    - For each element in nums, check if the element itself is greater than element + curr_sum (nums[i] > nums[i] + curr_sum)
        - if this is the case then no need to continue the chain, i.e. start new chain of subArray starting from nums[i]
    - Else, continue the chain of subArray by adding nums[i] into curr_sum (curr_sum += nums[i])
    
    - If curr_sum > max_sum then update max_sum 
    - Return max_sum at the end

*/

