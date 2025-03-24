
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: March 24, 2025
// Creation TIME: 15:47:27

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Partition a Set into Two Subsets of Equal Sum
// https://www.geeksforgeeks.org/partition-problem-dp-18/

/*
DESCRIPTION :
    Given an array arr[], the task is to check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
    Note: Each element is present in either the first subset or the second subset, but not in both.


Example-1: 
    Input: arr[] = [1, 5, 11, 5]
    Output: true 
    Explanation: The array can be partitioned as [1, 5, 5] and [11]
Example-2: 
    Input: arr[] = [1, 5, 3]
    Output: false
    Explanation: The array cannot be partitioned into equal sum sets.

*/ 


class Solution {
    private:
    bool recursiveHelper(vector<int>& nums, int sum, int n) {
        // Base Condition
        if (sum == 0)
            return true;
        else if (n == 0)
            return false;

        // Choice Diagram
        if (nums[n-1] <= sum) {
            return recursiveHelper(nums, sum-nums[n-1], n-1) || recursiveHelper(nums, sum, n-1);
        }
        else if (nums[n-1] > sum)
            return recursiveHelper(nums, sum, n-1);

        return -1;
    }

    bool memoizedHelper(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Base Condition
        if (sum == 0) return true;
        else if (n == 0) return false;

        // Check if present in memory
        if (t[n][sum] != -1)
            return t[n][sum];

        // Choice Diagram
        if (nums[n-1] <= sum) 
            t[n][sum] = memoizedHelper(nums, sum - nums[n-1], n-1, t) || memoizedHelper(nums, sum, n-1, t);
        else
            t[n][sum] = memoizedHelper(nums, sum, n-1, t);

        return t[n][sum];
    }

    bool tabulationHelper(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Base Condition -> Initialization
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) 
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i-1] <= j) 
                    t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][sum];
    }

    public:
    bool equalSumPartition(vector<int>& nums) {
        int sum = 0;
        vector<vector<int>> t (1001, vector<int>(1001, -1));

        for (int x : nums) sum += x;

        if (sum % 2 != 0) {
            cout << "Sum is odd.\n";
            return false;
        }

        // 1. Recursive approach
        // return recursiveHelper(nums, sum/2, nums.size());

        // 2. Memoized Approach
        return memoizedHelper(nums, sum/2, nums.size(), t);

        // 3. Tabulation Approach
        // return tabulationHelper(nums, sum/2, nums.size(), t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr = {5,1,11,5};
    // Method Invocation & Result Visualization
    if (sol.equalSumPartition(arr))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

