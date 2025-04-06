
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


Constraint:
    1 <= arr.size() <= 50
    0 <= d  <= 50
    0 <= arr[i] <= 6

*/ 


class Solution {
    private:
    int countOfSubsetSumRecursive(vector<int>& nums, int sum, int n) {
        if (n == 0)
            return (sum == 0); 
        // if (sum == 0)
        //     return 1;

        if (nums[n-1] <= sum)
            return countOfSubsetSumRecursive(nums, sum - nums[n-1], n-1) + countOfSubsetSumRecursive(nums, sum, n-1);
        else
            return countOfSubsetSumRecursive(nums, sum, n-1);
    }

    int countOfSubsetSumMemoised(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        if (n == 0)
            return (sum == 0); 
        // else if (n == 0) return 0;

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
    int countGivenDiffSubsetSum (vector<int>& nums, int diff) {
        // Let s1 and s2 be the subset sums for 2 mutually exclusive subsets from 'nums'.
        // s1 - s2 = diff   --> (1)
        // s1 + s2 = total  --> (2)
        // -------------    --> add (1) and (2)
        // 2*s1 = diff + total
        // s1 = (diff + total)/2

        // We now know s1 as 'diff' and 'total' are known. Also we know how to find total no. of subsets w/ sum s1
        // Thus say if no. of subsets with sum as s1 is x, therefore no. of subsets with s2 will also be x.

        int total = 0, n = nums.size();
        vector<vector<int>> t (1001, vector<int> (1001, -1));

        for (int x : nums) total += x;

        if ((total + diff) % 2 != 0) return 0;
        int s1 = (total + diff) / 2;

        // return countOfSubsetSumRecursive(nums, s1, n);
        // return countOfSubsetSumMemoised(nums, s1, n, t);
        return countOfSubsetSumTabulation(nums, abs(s1), n, t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {1,1,1,1,1};            int diff1 = 3;
    vector<int> nums2 = {1};                    int diff2 = 1;
    vector<int> nums3 = {1};                    int diff3 = 2;
    vector<int> nums4 = {0};                    int diff4 = 0;
    vector<int> nums5 = {0,0,0};                int diff5 = 0;
    vector<int> nums6 = {100};                  int diff6 = -300;
    vector<int> nums7 = {5, 2, 6, 4};           int diff7 = 3;
    vector<int> nums8 = {1, 2, 3, 1, 2};        int diff8 = 1;
    vector<int> nums9 = {0,1,2,2,2,3,0,3,0,1};  int diff9 = 12;

    // Method Invocation & Result Visualization
    cout << "1. Actual: " << sol.countGivenDiffSubsetSum(nums1, diff1) << "\tExpected: 5" << endl;
    cout << "2. Actual: " << sol.countGivenDiffSubsetSum(nums2, diff2) << "\tExpected: 1" << endl;
    cout << "3. Actual: " << sol.countGivenDiffSubsetSum(nums3, diff3) << "\tExpected: 0" << endl;
    cout << "4. Actual: " << sol.countGivenDiffSubsetSum(nums4, diff4) << "\tExpected: 2" << endl;
    cout << "5. Actual: " << sol.countGivenDiffSubsetSum(nums5, diff5) << "\tExpected: 8" << endl;
    cout << "6. Actual: " << sol.countGivenDiffSubsetSum(nums6, diff6) << "\tExpected: 0" << endl;
    cout << "7. Actual: " << sol.countGivenDiffSubsetSum(nums7, diff7) << "\tExpected: 1" << endl;
    cout << "8. Actual: " << sol.countGivenDiffSubsetSum(nums8, diff8) << "\tExpected: 5" << endl;
    cout << "9. Actual: " << sol.countGivenDiffSubsetSum(nums9, diff9) << "\tExpected: 16" << endl;

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

