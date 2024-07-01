
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 01, 2024
// Creation TIME: 22:19:25

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #18. 4Sum

/*
DESCRIPTION :
    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
        - 0 <= a, b, c, d < n
        - a, b, c, and d are distinct.
        - nums[a] + nums[b] + nums[c] + nums[d] == target
        - You may return the answer in any order.


Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
 

Constraints:
    - 1 <= nums.length <= 200
    - -10^9 <= nums[i] <= 10^9
    - -10^9 <= target <= 10^9


*/ 


class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n-3; i++) {
            if (i != 0 && nums[i-1] == nums[i]) continue;

            for (int j = i+1; j < n-2; j++) {
                if (j != i+1 && nums[j-1] == nums[j]) continue;

                int k = j+1, l = n-1;
                while (k < l) {
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k-1] == nums[k]) k++;
                        while (k < l && nums[l+1] == nums[l]) l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {1, 0, -1, 0, -2, 2};
    vector<int> arr2 = {2, 2, 2, 2, 2};


    // Method Invocation & Result Visualization
    printFormattedMatrix(sol.fourSum(arr1, 0));
    printFormattedMatrix(sol.fourSum(arr2, 8));


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^4) | SC: O(#quadruplets) | Brute Force
    # 4 nested loop since we want 4 unique elemets
    - declare a set data structure as we want unique quadruplets
    - using 4 nested loops where inintialization is as follows, i=0, j = i+1, k=j+1, l=k+1.
    - inside these four nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k]+arr[l]
        - if it is equal to the target we will sort this quadruplet (to maintain uniqueness)
        - and insert it in the set data structure.
    - return the copied list of stored quadruplets from the set.


2. TC: O(n^3) | SC: O(#quadruplets)+O(N) | Better
    # 3 nested loops with hash map
    - declare a set data structure as we want unique quadruplets
    - use the 3 loops (say i, j & k) that will run i: 0 -> n-1 , j: i+ -> n-1 , k: j+1 -> n-1.
    - Before 3rd loop, declare a HashMap to store elements as we intend to search 4th element in that HashSet.
    - Inside the third loop, calculate the value of the fourth element i.e. target - (nums[i]+nums[j]+nums[k]).
    - if 4th element found in target, sort the 4 values nums[i], nums[j], nums[k], 4th element and store in set.
    - insert the k-th element i.e. nums[k] in the HashSet
    - return the copied list of stored quadruplets from the set.


3.  TC: O(N^3) | SC: O(1) | OPTIMIZED
    # 4 pointer - 2 fixed, 2 moving
    - Similar to 3 sum where after softing array, we kept 1 pointer anchored to left side and move other 2 pointers
    - Here we keep 'i', 'j' anchored to left side and move 'k' from left to right & move 'l' from right to left.
    - this is just like 2 pointers moving inwards in a sorted array with added skipping duplicates for each pointer
    - sort the entire array.
    - use the 2 loops (say i & j) that will run i: 0 -> n-1 & j: i+ -> n-1.
    - Inside the 2nd loop, we'll be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index).
    - move 'k' forward and 'l' backward until they cross each other, while the value of i and j will be fixed.
    - check the sum = nums[i]+nums[j]+nums[k]+nums[l].
        - if sum is greater than target, l--
        - if sum is smaller than target, k++
        - if sum is equal to target then, simply insert the quadruplet into our answer 
    - Move the pointers k & l skipping the duplicates(i.e. by checking the adjacent elements while moving).
    - As array is sorted, the duplicates will be in consecutive places. 
        - So, while moving a pointer, we will check the current element and the adjacent element.
        - Until they become different, we will move the pointer by 1 place. 
        - Follow this process for all 4 pointers. 

*/

