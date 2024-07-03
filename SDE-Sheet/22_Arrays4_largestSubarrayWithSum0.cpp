
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 02, 2024
// Creation TIME: 21:10:49

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// GFG #Largest subarray with 0 sum

/*
DESCRIPTION :
    Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Examples:

    Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
    Output: 5
    Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

    Input: arr[] = {2,10,4}, n = 3
    Output: 0
    Explanation: There is no subarray with 0 sum.

    Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
    Output: 5
    Explanation: The subarray is 0 -4 3 1 0.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
    1 <= n <= 10^5
    -1000 <= arr[i] <= 1000, for each valid i


*/ 


class Solution {
    public:
    int maxLen1(vector<int>&A, int n) {   // Edge case approach 1
        unordered_map<int, int> sums; // prefixSum : index
        sums[0] = -1; // initalise our "sums" hash_map to contain initial value of prefixSum i.e. 0
        int prefixSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += A[i];
            if (sums.find(prefixSum) != sums.end()) {
                ans = max(ans, i - sums[prefixSum]);
            }
            else {
                sums[prefixSum] = i;
            }

        }
        return ans;
    }

    int maxLen2(vector<int>&A, int n) {   // Edge case approach2
        unordered_map<int, int> sums; // prefixSum : index
        int prefixSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += A[i];
            if(prefixSum == 0) 
                ans = i + 1; 
            else {
                if (sums.find(prefixSum) != sums.end()) 
                    ans = max(ans, i - sums[prefixSum]);
                else 
                    sums[prefixSum] = i;
            }
        }
        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {15,-2,2,-8,1,7,10,23};
    vector<int> arr2 = {2,10,4};
    vector<int> arr3 = {1, 0, -4, 3, 1, 0};
    vector<int> arr4 = {1, -1, 1, -1};

    // Method Invocation & Result Visualization
    cout << sol.maxLen1(arr1, 8) << endl;
    cout << sol.maxLen1(arr2, 3) << endl;
    cout << sol.maxLen1(arr3, 6) << endl;
    cout << sol.maxLen1(arr4, 4) << endl;

    cout << sol.maxLen2(arr1, 8) << endl;
    cout << sol.maxLen2(arr2, 3) << endl;
    cout << sol.maxLen2(arr3, 6) << endl;
    cout << sol.maxLen2(arr4, 4) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    # Find all possible sub-arrays -> check if subarray has sum 0 -> return one with max len
    - Use 2 loops and find all possible subarrays of the given array
    - initialize max_len variable to store the max len of sub array with sum 0
    - inside 2nd loop maintain the prefix sum of the current subarray and keep a max
    - if current subArray sum reaches 0 then challenge max_len 
    - return max_len 

2. TC: O(n) | SC: O(n) | OPTIMIZED-edgeCase1
    # maintain hash map with of [prefix_sum : index] -> return max len such that curr prefixSum is previously seen
    - declare a



2.  TC: O(n) | SC: O(n) | OPTIMIZED-edgeCase2


*/

