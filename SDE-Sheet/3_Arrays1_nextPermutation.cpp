
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 06, 2024
// Creation TIME: 10:42:21

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #31. Next Permutation

/*
DESCRIPTION :
    A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
    - For example, for arr = [1,2,3], the following are all the permutations of arr: 
        [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

    The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    - For example, the next permutation of arr = [1,2,3] is [1,3,2].
    - Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    - While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
    
    Given an array of integers nums, find the next permutation of nums.

    The replacement must be in place and use only constant extra memory.

Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]

Example 3:
    Input: nums = [1,1,5]
    Output: [1,5,1]
*/ 


class Solution {
    public:
    void nextPermutation1(vector<int>& nums) {
        // Brute Force | TC ~~ O(n! * n) ~~ extremly high order
        
        // 1. Generate all possible permutations
        // 2. sort them
        // 3. Match each permutation with the given nums[] permutation
            // if permutation is last in sorted order return 1st in sorted permutations.
            // else return next permutation
    }
    void nextPermutation2(vector<int>& nums) {
        // STL only in C++
        next_permutation(nums.begin(), nums.end());
    }
    void nextPermutation3(vector<int>& nums) {
        // 1  3  5  5  2  2  1  0  0 
        //    i  i+1

        // Next_Permutation should be the one having maximum commonality from the beganning
            // so lets assume all the numbers are common -> no new perm possiblity
            // 1 less num from end -> no new num possiblity.
            // 2 less nums from end -> new larger num not possible since (0 0)
            // 3 less nums from end -> new larger num not possible since (1 0 0)           
            // 4 less nums from end -> new larger num not possible since (2 1 0 0) 
            // . . .
            // This is happening since nums are in decreasing order at end of arr
            // . . .
            
        // Find break point (i) from end, such that nums[i] < nums[i+1] 
            // if such i does not exist then reverse the whole array 
            // since its the last permutation & RETURN 
            
        // If i exists, then all element in its right are in decreasing order 
        // 1   3   5   5   2   2   1   0   0 
        //    idx      k
        // Now find the rightmost index(idx) at right of i such that, nums[idx] > nums[i]
        
        // swap(nums[i], nums[idx])
        // 1  5  5  3  2  2  1  0  0 
        //    |<--->|
        //    idx<->i

        // sort everything after break point 
        // since the next permutation should be next smallest
        // 1  5  0  0  1  2  2  3  5
        int n = nums.size(), idx = -1, k;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }

        reverse(nums.begin()+idx+1, nums.end());
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> nums1 {1, 3, 5, 5, 2, 1, 1, 0, 0};
    vector<int> nums2 {1, 3, 5, 5};
    vector<int> nums3 {1, 3, 5, 1, 0, 0};
    vector<int> nums4 {5, 1, 0, 0};
    vector<int> nums5 {1,2,5,6,5,5,4,3,1,1,1,1,0};

    // Method Invocation
    sol.nextPermutation3(nums1);
    sol.nextPermutation3(nums2);
    sol.nextPermutation3(nums3);
    sol.nextPermutation3(nums4);
    sol.nextPermutation3(nums5);
    // sol.method_name(param2);


    // Result Visualization
    printVector(nums1);
    printVector(nums2);
    printVector(nums3);
    printVector(nums4);
    printVector(nums5);

    return 0;
}

/*
SOLUTIONS:-

1. Brute Force | TC ~~ O(n! * n) ~~ extremly high order
    Generate all possible permutations
    sort them
    Match each permutation with the given nums[] permutation
        if : permutation is last in sorted order return 1st in sorted permutations.
        else : return next permutation

2. TC O(n^2) TC | OPTIMIZED
    STL only in C++

3.  O(1) extra space & O(3n) ~~ O(N) TC | OPTIMIZED
    - Find the break-point, idx: Break-point means the first index idx from the back of the given array where arr[idx] becomes smaller than arr[idx+1].
    - If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, in this case, we will reverse the whole array and will return it as our answer.
    - If a break-point exists:
        - Find the smallest number i.e. > arr[i] and in the right half of index idx(i.e. from index idx+1 to n-1) therefore we do this by travelling backwards to find arr[k] > arr[idx] and swap it with arr[idx].
        - Reverse the entire right half(i.e. from index idx+1 to n-1) of index idx. And finally, return the array.

*/

