
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 07, 2024
// Creation TIME: 19:29:43

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #75. Sort Colors

/*
DESCRIPTION :
    - Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    - We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    - You must solve this problem without using the library's sort function.


Example 1:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
Example 2:
    Input: nums = [2,0,1]
    Output: [0,1,2]
 

Constraints:
    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.

*/ 


class Solution {
    public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        
        // nums[] =  0 0 0 0 0 0    1 1 1 1 1    X X X X X X 2 2 2 2 2
        // indices = 0_________L-1__L_______M-1__M_________H_________N-1
        
        // X X X X X X -> unsorted part of array

        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        
        while (mid <= high) {
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else if (nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums {0,0,0,1,0,1,0,1,0,2,2,2,2,1,2,0};

    // Method Invocation
    sol.sortColors(nums);

    // Result Visualization
    printVector(nums);

    return 0;
}

/*
SOLUTIONS:-

1. O(N) Space & O(N*LogN) TC | Brute Force
    buit in sort funtion in C++ 

2. O(1) Space & O(2N) TC | Optimized
    - in 1st loop. Count number of 0s->a, 1s->b, 2s->c.
    - 2nd time use 3-loops, each for 0,1,2.
        - replace 0 in array for beganning a-times for 0s.
        - replace 1 in array for next b-times for 1s.
        - replace 2 in array for next c-times for 2s.

3.  O(1) extra space & O(N) TC | OPTIMIZED
    - DUTCH NATIONAL FLAG ALGO
    
    - Use this config for 3 pointer low, mid, high.
        // nums[] =  0 0 0 0 0 0    1 1 1 1 1    X X X X X X 2 2 2 2 2
        // indices = 0_________L-1__L_______M-1__M_________H_________N-1
        
        // X X X X X X -> unsorted part of array

    - here nums[mid->high] contains unsorted part.

    - LETS TAKE SLIDING WINDOW APPROACH 
    - WHERE WE SHIFT POINTERS LEFT/RIGHT AS PER OUR USE-CASE 
    - SINCE 3 NUMS LETS MAINTAIN 3 POINTERS

    - iterate for "mid-pointer" till its less than equal to high.
    
    - if nums[mid] == 0
        - swap(nums[mid], nums[low])
        - low++
        - mid++
    - if nums[mid] == 1
        - mid++
    - if nums[mid] == 2
        - swap(nums[mid], nums[high])
        - high--
*/

