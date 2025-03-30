
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: March 26, 2025
// Creation TIME: 01:03:40

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Partition a set into two subsets such that the difference of subset sums is minimum
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

/*
DESCRIPTION :
    Given an array arr[] of size n, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
    If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.


Example 1:
    Input: arr = [1, 6, 11, 5]
    Output: 1
    Explanation: S1 = [1, 5, 6], sum = 12,  S2 = [11], sum = 11,  Absolute Difference (12 – 11) = 1

Example 2:
    Input: arr = [1, 5, 11, 5]
    Output: 0
    Explanation: S1 = [1, 5, 5], sum = 11, S2 = [11], sum = 11, Absolute Difference (11 – 11) = 0     

*/ 


class Solution {
    private:
    bool subsetSumRecursive(vector<int>& nums, int sum, int n) {
        // Base Condition
        if (sum == 0) return true;
        else if (n == 0) return false;

        // Choice Diagram
        if (nums[n-1] <= sum) 
            return subsetSumRecursive(nums, sum - nums[n-1], n-1) || subsetSumRecursive(nums, sum, n-1);
        else
            return subsetSumRecursive(nums, sum, n-1);
    }

    bool subsetSumMemoized(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        if (sum == 0) 
            return true;
        else if (n == 0)
            return false;

        if (t[n][sum] != -1) 
            return t[n][sum];

        if (nums[n-1] <= sum) 
            t[n][sum] = subsetSumMemoized(nums, sum - nums[n-1], n-1, t) || subsetSumMemoized(nums, sum, n-1, t);
        else
            t[n][sum] = subsetSumMemoized(nums, sum, n-1, t);

        return t[n][sum];
    }

    bool subsetSumTabulation(vector<int>& nums, int sum, int n, vector<vector<int>>& t) {
        // t[n+1][sum+1]
        // Initialisation
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j == 0)
                    t[i][j] = true;
                else if (i == 0)
                    t[i][j] = false;
            }
        }

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i-1] <= j) 
                    t[i][j] = (t[i-1][j - nums[i-1]]) || (t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

    public:
    int minSubsetSumDifference(vector<int>& nums) {
        // Assume s1 and s2 are the sum of two mutually exclusive subset for the given set of numbers: nums. 
        // Now we have to minimize (s2-s1)

        // (s2 - s1)    --------> minimize
        // s1 + s2 = total ==> s2 = (total - s1)
        // ((total - s1) - s1) -> minimize
        // (total - 2*s1)   ----> minimize

        // For each possible number in range [0, total], we check if it is possible to be formed by s1.
        // Say, s1 is some number 'x' lesser than the 'total/2'. So s2 will be:
        // say s1 = (total/2 - x) ==> s2 = total - s1 ==> s2 = total - (total/2 - x) ==> s2 = (total/2 + x)
        // Therefore if s1 = (total/2 - x) then s2 = (total/2 + x), hence they are complementary to each other around the total
        // Thus we loop from 0 to (total/2) and find out all possible subsets with sum for each i in range

        /*
            nums = {1,2,7};
            total = 10;
            => possible values for s1:
            {0  1   2   3   4   5   6   7   8   9   10}

            so if,
                s1 = 0 ==> s2 = 10 ***
                s1 = 1 ==> s2 = 9  ***
                s1 = 2 ==> s2 = 8  ***
                s1 = 3 ==> s2 = 7  xxx
                s1 = 4 ==> s2 = 6  xxx
                s1 = 5 ==> s2 = 5  xxx

            *** -> possible
            xxx -> not possible
        */

        int sum  = 0, minDifference = INT_MAX, n = nums.size();
        vector<vector<int>> t (5, vector<int> (24, -1));
        for (int x : nums) sum += x;

        // Recursive Execution
        // for (int i = 0; i <= sum/2; i++) {
        //     if (subsetSumRecursive(nums, i, nums.size())) {
        //         minDifference = min(minDifference, (sum - (2*i)));
        //     }
        // }

        // Memoized Execution
        // for (int i = 0; i <= sum/2; i++) {
        //     vector<vector<int>> t (5, vector<int> (24, -1));
        //     if (subsetSumMemoized(nums, i, nums.size(), t)) {
        //         minDifference = min(minDifference, (sum - (2*i)));
        //     }
        // }

        // Bottom-up Execution
        subsetSumTabulation(nums, sum/2, n, t); // We can call this only with sum/2 since below we are only going up till sum/2
        for (int i = 0; i <= sum/2; i++) {
            if (t[n][i])
                minDifference = min(minDifference, (sum - (2*i)));
        }
        // printMatrix(t);
        return minDifference;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 = {1,2,7};
    vector<int> nums2 = {1,6,11,5};
    vector<int> nums3 = {1,5,11,5};

    // Method Invocation & Result Visualization
    cout << sol.minSubsetSumDifference(nums1) << endl;
    cout << sol.minSubsetSumDifference(nums2) << endl;
    cout << sol.minSubsetSumDifference(nums3) << endl;

    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^N + N*(totalSum/2)) | SC: O(N) | Recursion
    Time Complexity:  O(2^N + N*(totalSum/2))  // O(2^N) for subset generation using recursive helper function calls, and O(N *totalSum) for going thorugh the loop.
    Space Complexity: O(N)   //  Recursion stack space for the helper function is is equal to the length of array, 'n'.

# TC: O(N*totalSum) | SC: O((N+1)*totalSum/2 +N) | Memoization [Top-down]
    Time Complexity:  O(N*totalSum) // 'subsetSumMemoized' has O(N * totalSum/2) time + iteration space, so we explore (totalSum/2) with recursive stack O(N) space to account. Memoization cuts short some of redundant recursive calls, and can be assumed.
    Space Complexity: O((N+1)*totalSum/2 + N)  // Memoization table t[n+1][sum+1] and space for helper recursive function calls.

# TC: O((N+1) * totalSum + N + (totalSum/2)) | SC: O((N+1) * totalSum) | Tabulation [Bottom-up]
    Time Complexity:  O((N+1)*totalSum/2 + N + (totalSum/2))  // 'subsetSumTabulation' has O(N * totalSum/2) + finding total for sum  + for going to minDifference that requires loop sum/2 which we use.
    Space Complexity: O((N+1) * totalSum)   // Size of the table for storing subset sum results.

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/
