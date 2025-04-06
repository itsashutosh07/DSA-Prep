
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
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/0

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
        if (n == 0)     // Corrected and combined base case
            return (sum == 0);  // Returns 1 if sum is also 0, 0 otherwise
        /*
        - Incorrect base case
            if (sum == 0) return 1;
            else if (n == 0) return 0;

            - Above base case does not work for case: 
                - arr = {0,0,0,0} , target = 0
                - Actual Output : 1
                - Expected output: 16 (2^4)
        */

        // Choice Diagram
        if (nums[n-1] <= sum) 
            return countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else 
            return countOfSubsetSumRecursive(nums, sum, n-1);
    }

    int countOfSubsetSumMemoised(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        if (n == 0)
            return (sum == 0);  // Returns 1 if sum is also 0, 0 otherwise

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
            for (int j = 0; j <= sum; j++) {
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
    vector<int> arr1 = {5,2,3,10,6,8};
    int n1 = arr1.size(), target1 = 10;
    vector<vector<int>> t1 (n1+1, vector<int>(target1+1, -1));
    vector<vector<int>> dp1 (n1+1, vector<int>(target1+1, -1));

    vector<int> arr2 = {0,0,0,0,0};
    int n2 = arr2.size(), target2 = 0;
    vector<vector<int>> t2 (n2+1, vector<int>(target2+1, -1));
    vector<vector<int>> dp2 (n2+1, vector<int>(target2+1, -1));
    
    
    // Method Invocation & Result Visualization
    cout << sol.countOfSubsetSumRecursive(arr1, target1, n1) << endl;
    cout << sol.countOfSubsetSumMemoised(arr1, target1, n1, t1) << endl;
    cout << sol.countOfSubsetSumTabulation(arr1, target1, n1, dp1) << endl << endl;

    cout << sol.countOfSubsetSumRecursive(arr2, target2, n2) << endl;
    cout << sol.countOfSubsetSumMemoised(arr2, target2, n2, t2) << endl;
    cout << sol.countOfSubsetSumTabulation(arr2, target2, n2, dp2) << endl;

    return 0;
}

/*
SOLUTIONS:-

# TC: O(2^N) | SC: O(N) | Recursion
    Time Complexity:  O(2^N)  //  Each element has two choices: be included or excluded, leading to 2^N possibilities.
    Space Complexity: O(N)    //  Maximum recursion depth is proportional to the number of elements.

# TC: O(N*sum) | SC: O(N*sum) | Memoization [Top-down]
    Time Complexity:  O(N*sum)  // Each subproblem (n, sum) is solved at most once.
    Space Complexity: O(N*sum)   // Size of the memoization table t[N+1][sum+1].

# TC: O(N*sum) | SC: O(N*sum) | Tabulation [Bottom-up]
    Time Complexity:  O(N*sum)  // The nested loops iterate through each element and sum.
    Space Complexity: O(N*sum)   //  Stores intermediate results in a table of size (N+1) x (sum+1).

# TC: O(N*sum) | SC: O(sum) | Space-Optimized
    Time Complexity:  O(N*sum)  //  The approach remains the same.
    Space Complexity: O(sum)    //  Only two rows are stored at any time.

*/

