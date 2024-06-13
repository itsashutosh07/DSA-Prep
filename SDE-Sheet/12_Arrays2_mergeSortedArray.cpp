
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 14:42:41

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #88. Merge Sorted Array

/*
DESCRIPTION :
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
    To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].

Example 3:
    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:
    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
 

    Follow up: Can you come up with an algorithm that runs in O(m + n) time?



Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]
*/ 


class Solution {
    public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force | TC: O((N+M)*log(N+M)) SC: O(1)
        for (int i = 0; i < n; i++) {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());

        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Optimized O(2(N+M)) & TC O(N+M)
        vector<int> temp (m+n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n && k < m+n) {
            if (nums1[i] <= nums2[j]) 
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }

        while (i < m) 
            temp[k++] = nums1[i++];
        while (j < n)
            temp[k++] = nums2[j++];
        
        for (int a = 0; a < m+n; a++) 
            nums1[a] = temp[a];
    }

    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Most Optimal: TC: O(N+M) & SC: O(1)
        int i = n+m-1;
        m--; n--; // decreased because indices start from m-1 & n-1
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n])
                nums1[i--] = nums1[m--];
            else
                nums1[i--] = nums2[n--];
        }

        while(n >= 0)
            nums1[i--] = nums2[n--];
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    int m1 = 3, n1 = 3;
    vector<int> nums1 {1,5,6,0,0,0};
    vector<int> nums2 {-5,2,4};

    // Method Invocation
    sol.merge3(nums1, m1, nums2, n1);

    // Result Visualization
    printVector(nums1);

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

