
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: March 30, 2025
// Creation TIME: 19:53:36

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// #494. Target Sum
// https://leetcode.com/problems/target-sum/description/

/*
DESCRIPTION :

    You are given an integer array nums and an integer target.

    You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.


Example 1:
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3

Example 2:
    Input: nums = [1], target = 1
    Output: 1

Constraints:

    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000

*/ 


class Solution {
// private:
    int countOfSubsetSumRecursive(vector<int>& nums, int sum, int n) {
        // Base condition
        if (n == 0)
            return (sum == 0);
        
        // Choice diagram
        if (nums[n-1] <= sum)
            return countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else 
            return countOfSubsetSumRecursive(nums, sum, n-1);
    }

    int countOfSubsetSumMemoised(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Base condition
        if (n == 0)
            return (sum == 0);
        
        if (t[n][sum] != -1)
            return t[n][sum];

        // Choice diagram
        if (nums[n-1] <= sum)
            t[n][sum] = countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else 
            t[n][sum] = countOfSubsetSumRecursive(nums, sum, n-1);

        return t[n][sum];
    }

    int countOfSubsetSumTabulation(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Initialization
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0)
                    t[i][j] = (j == 0) ? 1 : 0;
            }
        }

        // Choice diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i-1] <= j)
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

public:
    int targetSum (vector<int>& nums, int target) {
        // Let s1 and s2 be the subset sums for 2 mutually exclusive subsets from 'nums'.
        // s1 - s2 = target   --> (1)
        // s1 + s2 = total    --> (2)
        // -------------      --> add (1) and (2)
        // 2*s1 = target + total
        // s1 = (target + total) / 2

        // We now know s1 as 'target' and 'total' are known. 
        // Also we know how to find total no. of subsets w/ sum s1
        // Thus say if no. of subsets with sum as s1 is x, therefore no. of subsets with s2 will also be x.

        int total = 0;
        for (int x : nums) total += x;

        if ((total + target) % 2 != 0) return 0;

        int s1 = (total + target) / 2;
        int n = nums.size();

        if (s1 < 0) return 0; // s1 can never be negative since it is the sum of a subset of +ve elements.
        // Checking if (s1 < 0) returns 0, which is ((total + target)/2 < 0) correctly handles the scenario when the target is "too negative" relative to the total. Checking if (total < 0) would be inappropriate because total is always non-negative under the given constraints.

        vector<vector<int>> t (n+1, vector<int> (s1+1, -1)); // remember to make inner vector of size absolute value of s1 since s1 can be negative.

        // return countOfSubsetSumRecursive(nums, s1, n);
        // return countOfSubsetSumMemoised(nums, s1, n, t);
        return countOfSubsetSumTabulation(nums, s1, n, t);
    }


};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {1,1,1,1,1};            int target1 = 3;
    vector<int> nums2 = {1};                    int target2 = 1;
    vector<int> nums3 = {1};                    int target3 = 2;
    vector<int> nums4 = {0};                    int target4 = 0;
    vector<int> nums5 = {0,0,0};                int target5 = 0;
    vector<int> nums6 = {100};                  int target6 = -200;
    vector<int> nums7 = {0,0,0,1,2,2,2,3,3};    int target7 = 11;
    vector<int> nums8 = {0,0,0,1,1,2,2,2,3,3};  int target8 = 11;
    vector<int> nums9 = {0,0,0,1,1,2,2,2,3,3};  int target9 = 12;

    // Method Invocation & Result Visualization
    cout << "1. Actual: " << sol.targetSum(nums1, target1) << "\tExpected: 5" << endl;
    cout << "2. Actual: " << sol.targetSum(nums2, target2) << "\tExpected: 1" << endl;
    cout << "3. Actual: " << sol.targetSum(nums3, target3) << "\tExpected: 0" << endl;
    cout << "4. Actual: " << sol.targetSum(nums4, target4) << "\tExpected: 2" << endl;
    cout << "5. Actual: " << sol.targetSum(nums5, target5) << "\tExpected: 8" << endl;
    cout << "6. Actual: " << sol.targetSum(nums6, target6) << "\tExpected: 0" << endl;
    cout << "7. Actual: " << sol.targetSum(nums7, target7) << "\tExpected: 8" << endl;
    cout << "8. Actual: " << sol.targetSum(nums8, target8) << "\tExpected: 0" << endl;
    cout << "9. Actual: " << sol.targetSum(nums9, target9) << "\tExpected: 16" << endl;

    return 0;
}


/*
SOLUTIONS:-

# TC: O() | SC: O() | Recursion
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Memoization [Top-down]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Tabulation [Bottom-up]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

