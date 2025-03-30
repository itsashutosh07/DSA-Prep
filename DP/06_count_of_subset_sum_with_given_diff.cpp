
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: March 30, 2025
// Creation TIME: 16:39:52

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Count of Subsets with given Difference
// https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/

/*
DESCRIPTION :

    Given an array arr[] of size N and a given difference diff, the task is to count the number of partitions that we can perform such that the difference between the sum of the two subsets is equal to the given difference.

    Note: A partition in the array means dividing an array into two parts say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only of the subsets.

Example-1:
    Input: N = 4, arr[] = [5, 2, 6, 4], diff = 3
    Output: 1
    Explanation: We can only have a single partition which is shown below:
    {5, 2} and {6, 4} such that S1 = 7 and S2 = 10 and thus the difference is 3

Example-2:
    Input: N = 5, arr[] = [1, 2, 3, 1, 2], diff = 1
    Output: 5
    Explanation: We can have five partitions which is shown below
    {1, 3, 1} and {2, 2} – S1 = 5, S2 = 4
    {1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
    {3, 2} and {1, 1, 2} – S1 = 5, S2 = 4
    {1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
    {3, 2} and {1, 1, 2} – S1 = 5, S2 = 4

*/ 


class Solution {
    private:
    int countOfSubsetSumRecursive(vector<int>& nums, int sum, int n) {
        if (sum == 0)
            return 1;
        else if (n == 0)
            return 0;

        if (nums[n-1] <= sum)
            return countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else
            return countOfSubsetSumRecursive(nums, sum, n-1);
    }

    int countOfSubsetSumMemoised(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        if (sum == 0) return 1;
        else if (n == 0) return 0;

        if (t[n][sum] != -1)
            return t[n][sum];

        if (nums[n-1] <= sum)
            t[n][sum] = countOfSubsetSumMemoised(nums, sum - nums[n-1], n-1, t) + countOfSubsetSumMemoised(nums, sum, n-1, t);
        else
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
                else    
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

    public:
    int countGivenDiffSubsetSum (vector<int>& nums, int diff) {
        // Let s1 and s2 be the subset sums for 2 mutually exclusive subsets from 'nums'.
        // s1 - s2 = diff   --> (1)
        // s1 + s2 = total  --> (2)
        // -------------    --> add (1) and (2)
        // 2*s1 = diff + total
        // s1 = (diff + total)/2

        // We now know s1 as 'diff' and 'total' are known. Also we know how to find total no. of subsets w/ sum s1
        // Thus say if no. of subsets with sum as s1 is x, therefore no. of subsets with s2 will also be x.

        int total = 0, s1 = 0, n = nums.size();
        vector<vector<int>> t (1001, vector<int> (1001, -1));
        for (int x : nums) total += x;

        s1 = (total + diff) / 2;

        // return countOfSubsetSumRecursive(nums, s1, n);
        // return countOfSubsetSumMemoised(nums, s1, n, t);
        return countOfSubsetSumTabulation(nums, s1, n, t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {5, 2, 6, 4};
    int diff1 = 3;
    vector<int> nums2 = {1, 2, 3, 1, 2};
    int diff2 = 1;

    // Method Invocation & Result Visualization
    cout << sol.countGivenDiffSubsetSum(nums1, diff1) << endl;
    cout << sol.countGivenDiffSubsetSum(nums2, diff2) << endl;

    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^N) | SC: O(N) | Recursion
    Time Complexity:  O(2^N)  // For every element we either include it or exclude it, leading to 2 options per element.
    Space Complexity: O(N)    //  Maximum recursion depth corresponds to input size.

# TC: O(N*s1) | SC: O(N*s1) | Memoization [Top-down]
    Time Complexity:  O(N*s1) //  Memoization table of size N x s1 filled after the process.
    Space Complexity: O(N*s1)  //  Size of the memoization table t[N+1][s1+1] dominates the space usage, where s1 = (total + diff) / 2.

# TC: O(N*s1) | SC: O(N*s1) | Tabulation [Bottom-up]
    Time Complexity:  O(N*s1)  //  Nested loops iterate N x s1 times.
    Space Complexity: O(N*s1)   // Table of size (N+1) x (s1+1).

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

