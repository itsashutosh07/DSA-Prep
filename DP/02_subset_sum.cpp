
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: March 24, 2025
// Creation TIME: 02:46:26

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// #Subset Sum Problem

/*
DESCRIPTION :
    Given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum. 

Example 1:
    Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
    Output: True
    Explanation: There is a subset (4, 5) with sum 9.

Example 2:
    Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
    Output: False
    Explanation: There is no subset that add up to 30.

*/ 


class Solution {
    public:
    bool subsetSumRecursive(vector<int>& nums, int sum, int n) {
        // Base Condition
        if (sum == 0) return true;
        else if (n == 0) return false;

        // Choice Diagram
        if (nums[n-1] <= sum) {
            return subsetSumRecursive(nums, sum - nums[n-1], n-1) || subsetSumRecursive(nums, sum, n-1);
        }
        else {
            return subsetSumRecursive(nums, sum, n-1);
        }
    } 

    bool subsetSumMemoization(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Base Condition
        if (sum == 0)
            return true;
        else if (n == 0)
            return false;

        // Return from memory if already stored
        if (t[n][sum] != -1)
            return t[n][sum];

        // Choice Diagram
        if (nums[n-1] <= sum)
            t[n][sum] = subsetSumMemoization(nums, sum - nums[n-1], n-1, t) || subsetSumMemoization(nums, sum, n-1, t);
        else
            t[n][sum] = subsetSumMemoization(nums, sum, n-1, t);

        return t[n][sum];
    }

    bool subsetSumTabulation(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // Base Condition -> Initialization
        // Start from 0th row and column 
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) // if no item is there, we cannot achieve a non-zero sum
                    t[i][j] = false;
                if (j == 0) // sum = 0 can be achieved with any number of items, empty sub-set
                    t[i][j] = true; // sum = 0 with n = 0 items is also overrided to true here
            }
        }

        // Choice Diagram
        // Start from 1st row and column since 0th row has already been considered during initialisation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i-1] <= j) {
                    t[i][j] = (t[i-1][j - nums[i-1]]) || (t[i-1][j]); // take || not-take
                }
                else if (nums[i-1] > j) {
                    t[i][j] = t[i-1][j]; // not take
                }
            }
        }

        return t[n][sum];
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 14;
    vector<vector<int>> t (1001, vector<int> (1001, -1));
    // Method Invocation & Result Visualization
    if (sol.subsetSumTabulation(arr, sum, arr.size(), t))
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

