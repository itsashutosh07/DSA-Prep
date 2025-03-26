
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

    public:
    int minSubsetSumDifference(vector<int>& nums) {
        // Assume s1 and s2 are two subset for the given set of numbers: nums. Now we have to minimize (s2-s1)
        // (s2 - s1)    --------> minimize
        // total = s1 + s2 ==> s2 = (total - s1)
        // ((total - s1) - s1) -> minimize
        // (total - 2*s1)   ----> minimize

        // For each possible number in range [0, total], we check if it is possible to be formed by s1.
        // say s1 = (total/2 - x) ==> s2 = total - s1 ==> s2 = total - (total/2 - x) ==> s2 = (total/2 + x)
        // Therefore s1 and s2 are complementary for total
        // Thus we loop from 0 to (total/2) and find out all possible subsets with sum for each i in range

        int sum  = 0, minDifference = INT_MAX;
        vector<vector<int>> t (4, vector<int> (11, -1));
        for (int x : nums) sum += x;

        // for (int i = 0; i <= sum/2; i++) {
        //     if (subsetSum(nums, i, nums.size())) {
        //         cout << i << " ";
        //         minDifference = min(minDifference, (sum - (2*i)));
        //     }
        // }
        subsetSumMemoized(nums, sum, nums.size(), t);
        printMatrix(t);
        for (int i = 0; i <= sum/2; i++) {
            if (t[nums.size()][i] == true) {
                cout << i << " ";
                minDifference = min(minDifference, (sum - (2*i)));
            }
        }
        cout << endl;
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

    // Method Invocation
    printVector(nums1);
    cout << sol.minSubsetSumDifference(nums1) << endl << endl;
    // printVector(nums2);
    // cout << sol.minSubsetSumDifference(nums2) << endl << endl;
    // printVector(nums2);
    // cout << sol.minSubsetSumDifference(nums3) << endl << endl;



    // Result Visualization



    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

