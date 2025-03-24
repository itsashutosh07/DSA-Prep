
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: March 25, 2025
// Creation TIME: 01:23:57

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Count of subsets with sum equal to target

/*
DESCRIPTION :
    Given an array arr[] of length n and an integer target, the task is to find the number of subsets with a sum equal to target.

Example-1: 
    Input: arr[] = [1, 2, 3, 3], target = 6 
    Output: 3 
    Explanation: All the possible subsets are [1, 2, 3], [1, 2, 3] and [3, 3]

Example-2: 
    Input: arr[] = [1, 1, 1, 1], target = 1 
    Output: 4 
    Explanation: All the possible subsets are [1], [1], [1] and [1]

*/ 


class Solution {
    public:
    int countOfSubsetSumRecursive(vector<int>& nums, int sum, int n) {
        // Base Condition
        if (sum == 0) return 1;
        else if (n == 0) return 0;

        // Choice Diagram
        if (nums[n-1] <= sum) 
            return countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else 
            return countOfSubsetSumRecursive(nums, sum, n-1);
    }

    int countOfSubsetSumMemoised(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        if (sum == 0) return 1;
        else if (n == 0) return 0;

        if (t[n][sum] != -1) return t[n][sum];

        if (nums[n-1] <= sum) 
            t[n][sum] = countOfSubsetSumMemoised(nums,sum-nums[n-1],n-1,t) + countOfSubsetSumMemoised(nums,sum,n-1,t);
        else if (nums[n-1] > sum)
            t[n][sum] = countOfSubsetSumMemoised(nums, sum, n-1, t);

        return t[n][sum];
    }

    int countOfSubsetSumTabulation(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) t[i][j] = 0;
                if (j == 0) t[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i-1] <= j) 
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                else if (nums[i-1] > j) 
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr = {2,3,5,6,8,10};
    int n = arr.size();
    int target = 10;
    vector<vector<int>> t (1001, vector<int>(1001, -1));

    // Method Invocation & Result Visualization
    cout << sol.countOfSubsetSumRecursive(arr, target, n) << endl;
    cout << sol.countOfSubsetSumMemoised(arr, target, n, t) << endl;
    cout << sol.countOfSubsetSumTabulation(arr, target, n, t) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

