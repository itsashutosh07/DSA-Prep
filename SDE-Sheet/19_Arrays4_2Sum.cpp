
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 01, 2024
// Creation TIME: 21:39:44

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #1. Two Sum

/*
DESCRIPTION :
    - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    - You may assume that each input would have exactly one solution, and you may not use the same element twice.
    - You can return the answer in any order.


Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]
 

Constraints:
    - 2 <= nums.length <= 10^4
    - -10^9 <= nums[i] <= 10^9
    - -10^9 <= target <= 10^9
    - Only one valid answer exists.
 

Follow-up: 
    - Can you come up with an algorithm that is less than O(n2) time complexity?


*/ 


class Solution {
    public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        // TC - O(n^2) | SC - O(1)
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; 
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        // TC : O(n) | SC - O(n)
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end())
                return {i, seen[diff]};
            seen[nums[i]] = i;
        }
        return {};
    }
    string twoSum3(vector<int>& nums, int target) {
        // TC : O(NlogN) | SC - O(1)
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return "Yes";
            }
            else if (sum < target) {
                i++;
            }
            else { 
                j--;
            }
        }
        return "No";
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {2, 7, 11, 15};
    vector<int> arr2 = {3, 2, 4};
    vector<int> arr3 = {3, 3, 5, 4, 2, 1, 8, 3};


    // Method Invocation & Result Visualization
    printVector(sol.twoSum1(arr1, 9), ", ", "\n");
    printVector(sol.twoSum1(arr2, 6), ", ", "\n");
    printVector(sol.twoSum1(arr3, 6), ", ", "\n");

    printVector(sol.twoSum2(arr1, 9));
    printVector(sol.twoSum2(arr2, 6));
    printVector(sol.twoSum2(arr3, 6));

    cout << sol.twoSum3(arr1, 9) << endl;
    cout << sol.twoSum3(arr2, 6) << endl;
    cout << sol.twoSum3(arr3, 6) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    # Nested for loop
    - use nested for loops to generate all possible pairs
    - then in each iteration check if the elements at i and j sum up to the target
    - if yes then return {i & j}
    - else after exhausting i & j return empty vector {}

2. TC: O(n) | SC: O(n) | Better
    # Hashing the indices
    - use unordered_map to store elment and the index at which it was seen
    - Using a for loop check if the target - arr[i] was seen earlier using the hashmap
    - if it was seen earlier then return vector containing {i, map[arr[i]]}
    - else siply return empty vector at the end of for loop if the target was not encountered

3.  TC: O(NlogN + N) | SC: O(1) | OPTIMIZED **
    # 2 pointer approach - Cannot return index since array is now sorted
    - sort the array
    - initialize i = 0 & j = as last index of array
    - in a while loop till i does not cross j
        - check if sum of element at i & j is equal to target, if yes the return true
        - else if sum > target then reduce right boundary by doing j--
        - else sum < target then increase left boundary by doing i++
    - return false if target was not encountered.

*/

