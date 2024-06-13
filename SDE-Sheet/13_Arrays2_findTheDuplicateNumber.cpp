
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 19:33:48

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #287. Find the Duplicate Number

/*
DESCRIPTION :

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    There is only one repeated number in nums, return this repeated number.

    You must solve the problem without modifying the array nums and uses only constant extra space.


Example 1:
    Input: nums = [1,3,4,2,2]
    Output: 2
Example 2:
    Input: nums = [3,1,3,4,2]
    Output: 3
Example 3:
    Input: nums = [3,3,3,3,3]
    Output: 3
 

Constraints:
    1 <= n <= 10^5
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:
    How can we prove that at least one duplicate number must exist in nums?
    Can you solve the problem in linear runtime complexity?
*/ 


class Solution {
    public:
    int findDuplicate1(vector<int>& nums) {
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i])] < 0){
                ans = nums[i];
                break;
            }
            else
                nums[abs(nums[i])] *= -1;
        }
        return abs(ans);
    }

    int findDuplicate2(vector<int>& nums) {
        // Find the intersection point of two runners
        // slow moves 0.5x the speed of fast till they meet
        int slow = 0, fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);


        // Find the "entrace" to the cycle 
        // move 1 pace both the pointers till they meet
        slow = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);

        return fast;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 {3,3,3,3,3};
    vector<int> nums2 {3,1,3,4,2};
    vector<int> nums3 {1,1};
    vector<int> nums4 {2,2,2};
    vector<int> nums5 {1,3,4,2,2};

    // Method Invocation & Result Visualization
    cout << sol.findDuplicate1(nums1) << endl;
    cout << sol.findDuplicate1(nums2) << endl;
    cout << sol.findDuplicate1(nums3) << endl;
    cout << sol.findDuplicate1(nums4) << endl;
    cout << sol.findDuplicate1(nums5) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(NlogN) TC | Brute Force
    - sort array
    - traverse array and return element where arr[i] == arr[i-1] 


2. O(n) Space & O(n) TC | Optimized
    - use hash map to store duplicate values


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED | NeetCode https://youtu.be/wjYnzkAhcNk?si=0p-yAu7RHr_-BPR0&t=692
    - think the values in the nums array as indices, or better as pointer
    - since we know that all the integers in nums appear only once
        - except for precisely 1 integer which appears two or more times.
    - the duplicate values, say (nums[i],nums[j]) having same numbers in it
        - and therefore indices: i,j both point to the same value of nums[i (or nums[j])
        - index= 0 1 2 3 4  //
        - nums = 1 3 4 2 2  // this means that index4 & index3 both point to index2
        -   1-->[3]-->2-->[4]
                      ^    |
                      |____|
        - this tells us that multiple nodes are going to point at index2 => index2 is the start of our cycle
    - derivation of our algo can be derived by using:
        - length 'p' = distance of start to intersection point
        - length 'c' = length of our cycle
        - length 'x' = distance of point where slow & fast pointers meet to the intersection point

        - our goal is to prove (p = x)


*/

