
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
    // Better || Most optimal in case array has +ve, -ve and 0s
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
            cout << prefixSum << endl;
        }
        return ans;
    }

    // Better || Most optimal in case array has +ve, -ve and 0s
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

    // Optimal || Only works if array has 0s or +ve
    int maxLen3(vector<int>&A, int k) {   // Edge case approach2
        int l = 0, r = 0, sum = 0, n = A.size(), ans = 0;
        while (l <= r && r < n) {
            sum += A[r];
            while (l <= r && sum > k) {
                sum -= A[l];
                l++;
            }
            if (sum == k) {
                ans = max(ans, r - l + 1);
            }
            r++;
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
    vector<int> arr5 = {5,6,-1,5,-4,-2,-2,5,-1,0,1,1};
    vector<int> arr6 = {1,2,3,1,1,1,1,3,3};

    // Method Invocation & Result Visualization
    cout << sol.maxLen1(arr1, 8) << endl;
    cout << sol.maxLen1(arr2, 3) << endl;
    cout << sol.maxLen1(arr3, 6) << endl;
    cout << sol.maxLen1(arr4, 4) << endl;
    cout << sol.maxLen1(arr5, 12) << endl;

    cout << sol.maxLen2(arr1, 8) << endl;
    cout << sol.maxLen2(arr2, 3) << endl;
    cout << sol.maxLen2(arr3, 6) << endl;
    cout << sol.maxLen2(arr4, 4) << endl;
    cout << sol.maxLen2(arr5, 12) << endl;

    cout << sol.maxLen3(arr2, 16) << endl;
    cout << sol.maxLen3(arr6, 6) << endl;

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

2. TC: O(n) | SC: O(n) | Better-edgeCase1*
    < Better in case where array only has zeros and positive numbers >
    < OPTIMIZED in case where array has negative numbers too >

    # hash map [prefixSum : idx] initialized with [sum:0, idx:-1] 
    - declare a unordered_map 'prefixSums' for [prefixSum : index]
    - *initialize 'currSum' as 0 and initially store prefixSum of '0' as '-1' since we initially start with sum 0 
    - iterate over the array using a for loop 
        - if sum value is NOT found in map then add (current sum value, index)
            - do not update value of index if current sum value is found in map, since we want largest subArray
        - else if current sum value is found in map calculate currLen as (curr_idx - prev_idx) //Not +1
            - not +1 since the 1st occurance of the prefix sum is at an index before our desired subArray
        - challenge and update max_len with curr_len at the end of each iteration if necessary
    - return max_len

                idx    ->   0*   1   2    3   4   5*  6   7  
                arr[]   =  [15, -2,  2,  -8,  1,  7,  4,  8]
                prefixSum = 15  13  15    7   8   15  19  27
                res=5-0=[5]     <------max_lex-----> 

2.  TC: O(n) | SC: O(n) | Better-edgeCase2
    < Better in case where array only has zeros and positive numbers >
    < OPTIMIZED in case where array has negative numbers too >

    # maintain hash_map [prefixSum : idx] return i+1 if prefixSum@i itself is 0
    - declare a unordered_map 'prefixSums' for [prefixSum : index]
    - iterate over the arr using for loop & calculate prefixSum by adding current element to sum
    - if prefixSum at index i is itself 0 then our ans max_len should directly be updated as i+1
    - else if value of prefixSum at idx i was encountered previously 
        - curr_len will become curr_idx - index where curr_sum was previously encountered
        - challenge and update max_len with curr_len if necessary
    - else current value of prefixSum is seen first time -> add [prefixSum, idx] to hash map
    - return max_len

3.  TC: O(n) | SC: O(1) | OPTIMIZED-edgeCase2
    < OPTIMIZED but works ONLY in case where array has zeros or positive numbers >

    # 2 pointer sliding window
    - initialize left, right, sum, ans as 0
    - iterate over the array untill right is less than n and left is less than right
        - add element at right to the sum
        - if sum becomes larger than our target -> shorten the window size
            - decrement from sum  by the element at left index 
            - increase left index then again to check if there's still need to shorten the window size
        - check if sum became equal to our target
            - if yes, then update our max_len if curr window size (r-l+1) is max so far
        - increase window size
    - return max_len
*/

