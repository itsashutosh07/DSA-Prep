
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
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

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
    vector<int> arr = {1,2,3};
    int sum = 6;
    
    if (sol.subsetSumRecursive(arr, sum, arr.size())) 
        cout << "subsetSumRecursive : True" << endl << endl;
    else 
        cout << "subsetSumRecursive : False" << endl << endl;

    
    // Method Invocation : Memoization [Top-down]
    vector<vector<int>> t (4, vector<int> (7, -1)); // [N+1 x Sum+1] size matrix
    if (sol.subsetSumMemoization(arr, sum, arr.size(), t)) 
        cout << "subsetSumMemoization : True" << endl;
    else 
        cout << "subsetSumMemoization : False" << endl;
    
    // Result Visualization : Memoization [Top-down]
    printMatrix(t, "\t");
    /* The memoized algorithm avoids recomputing overlapping subproblems by storing results, exploring only the solution space directly relevant to the final answer. It prunes:
        •	States that exceed the sum.
        •	States that are unnecessary due to the nature of the recursion. (Due to short-circuiting nature or || OR used in the recursive/memoised approach)
        •	States that are equivalent due to overlapping subproblems.
    */


    // Method Invocation : Tabulation [Bottom-up]
    vector<vector<int>> dp (4, vector<int> (7, -1)); // [N+1 x Sum+1] size matrix
    if (sol.subsetSumTabulation(arr, sum, arr.size(), dp))
        cout << "subsetSumTabulation : True" << endl;
    else
        cout << "subsetSumTabulation : False" << endl;

    // Result Visualization : Tabulation [Bottom-up]
    printMatrix(dp, "\t");

    return 0;
}

/*
SOLUTIONS:-

# TC: O(2^N) | SC: O(N) | Recursion
    Time Complexity: O(2^N) // Each element can either be included or excluded from the subset, leading to 2 possibilities for every element.
    Space Complexity: O(N)  // Maximum depth of the recursion call stack, corresponding to the size of the input array.

# TC: O(n*sum) | SC: O(n*sum) | Memoization
    Time Complexity: O(n*sum) // While table size is n*sum, the algorithm prunes unnecessary recursive branches.  Worst-case occurs when all states are explored.
    Space Complexity: O(n*sum) //  Space required for the memoization table of size [n+1][sum+1].

# TC: O(n*sum) | SC: O(n*sum) | Bottom-up
    Time Complexity: O(n*sum) //  The algorithm iterates through each element of 'nums' and all possible sums up to 'sum', building a table of n*sum size.
    Space Complexity: O(n*sum) // Stores results in a table of dimensions (n+1) x (sum+1).

# TC: O(n*sum) | SC: O(sum) | Space-Optimized
    Time Complexity: O(n*sum) // The approach remains the same.
    Space Complexity: O(sum)  // Only stores current and previous row information, both are of size 'sum + 1'.

*/

