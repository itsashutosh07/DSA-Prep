
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 30, 2024
// Creation TIME: 23:56:52

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #169. Majority Element

/*
DESCRIPTION :
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
 

Constraints:

    n == nums.length
    1 <= n <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9

*/ 


class Solution {
    public:
    int majorityElement1(vector<int>& nums) {
        int n = nums.size(), nBy2 = floor(n/2), ans = -1;
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > nBy2) return x;
        }
        return ans;
    }
    int majorityElement2(vector<int>& nums) {
        int candidate, cnt = 0, n = nums.size();
        for (int x : nums) {
            if (cnt == 0) {
                candidate = x;
                cnt = 1;
            }
            else if (x == candidate) 
                cnt++;
            else
                cnt--;
        }
        return candidate;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {3, 2, 3};
    vector<int> arr2 = {2, 2, 1, 1, 1, 2, 2};
    vector<int> arr3 = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};


    // Method Invocation & Result Visualization
    cout << sol.majorityElement1(arr1) << endl;
    cout << sol.majorityElement2(arr2) << endl;
    cout << sol.majorityElement2(arr3) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    - We will run a loop that will select the elements of the array one by one.
    - For each element, run another loop and count its occurrence in the array.
    - If any element occurs more than the floor of (N/2), return it.


2. TC: O(n) | SC: O(n) | Better
    - Linear search by maintaining frequency count using unordered_map for each element
    - If frequency of current element in loop exceeds floor of n / 2 then simply return the current element.

3.  TC: O(n) | SC: O(1) | OPTIMIZED
    - Moore’s Voting Algorithm
    - use for loop to iterate over each element once
    - only maintain the max occuring element so far as a possible candidate
    - this is done by mainataining merely 2 variables
        - candidate -> denotes possible max occuring element
        - counter -> gets incremented if candidate element is encountered, else decremented
    - once counter reaches 0 then update the candidate with the current element and increase counter to 1.


*/

