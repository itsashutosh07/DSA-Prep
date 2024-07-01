
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 01, 2024
// Creation TIME: 02:53:11

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #493. Reverse Pairs

/*
DESCRIPTION :
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:
    Input: nums = [1,3,2,3,1]
    Output: 2
    Explanation: The reverse pairs are:
    (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
    (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:
    Input: nums = [2,4,3,5,1]
    Output: 3
    Explanation: The reverse pairs are:
        (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
        (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
        (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:
    1 <= nums.length <= 5 * 104
    -231 <= nums[i] <= 231 - 1


*/ 


class Solution {
    public:
    int reversePairs1(vector<int>&a) {
        int cnt = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > 2 * a[j]) cnt++;
            }
        }
        return cnt;
    }

    int countInverse(vector<int>& arr, int low, int mid, int high) {
        int i = low, j = mid+1, ans = 0;
        int r1 = mid, r2 = high;
        while (i <= r1 && j <= r2) {
            if ((long long)(arr[i]) > (long long)arr[j] * 2) {
                ans += (r1 - i + 1);
                j++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
    void merge(vector<int>& arr, int low, int mid, int high) {
        int l1 = low, r1 = mid;
        int l2 = mid+1, r2 = high;

        vector<int> temp;
        while (l1 <= r1 && l2 <= r2) {
            if (arr[l1] <= arr[l2])
                temp.push_back(arr[l1++]);
            else
                temp.push_back(arr[l2++]);
        }
        while (l1 <= r1)
            temp.push_back(arr[l1++]);
        while (l2 <= r2)
            temp.push_back(arr[l2++]);

        for (int i = 0; i < high-low+1; i++) {
            arr[low+i] = temp[i];
        }
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        // Base Condition
        if (low >= high) 
            return 0;

        // Calculate mid
        int mid = low + ((high - low) / 2);
        int ans = 0;

        ans += mergeSort(arr, low, mid);
        ans += mergeSort(arr, mid+1, high);
        ans += countInverse(arr, low, mid, high);
        merge(arr, low, mid, high);
        return ans;
    }
    int reversePairs2(vector<int>& nums) {
        int ans = 0;
        ans = mergeSort(nums, 0, nums.size()-1);
        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {1, 3, 2, 3, 1};
    vector<int> arr2 = {1, 3, 2, 3, 1, 4, 5, 2, 7, 8, 2, 1};


    // Method Invocation & Result Visualization
    cout << sol.reversePairs1(arr1) << endl;
    cout << sol.reversePairs1(arr2) << endl;

    cout << sol.reversePairs2(arr1) << endl;
    cout << sol.reversePairs2(arr2) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(N^2) | SC: O(1) | Brute Force
    # Nested search
    - Use nested loops to generate all possible pairs
    - First, we will run a loop(say i) from 0 to N-1 to select the a[i]. 
    - Since we know index i must be smaller than index j, run another loop i.e. j from i+1 to N-1 to select arr[j].
    - If they satisfy the condition (a[i] > 2*a[j]), we will increase the ans by 1.
    - return ans

2.  TC: O(logN * (N+N))) or O(2N*logN) | SC: O(N) | OPTIMIZED
    # Merge sort variation
    - This question is similar to count inverse where we were only required to tell if arr[i] > arr[j]
        - but there's a catch, the merge function intrensically worked by comapring if arr[i] > arr[j]
        - however we need to check if a[i] > 2*a[j]
        - Thus, it is not necessary if a[l1] is not greater than 2*arr[l2], elements right to arr[l2] would also not be greater. Our previous logic worked on that principle only.
    - Modified logic is to countPairs after 2 halves are sorted, but before they are merged!
    - For every element in the sorted left half, how many elements in the right half(also sorted) can make a pair.
    
    - implement whole merge sort code
    - after MERGE part of the code, call another method to count reverse pairs
    - initialize "i" as the start index of left sorted half and "j" as the start index of right sorted half 
    - if our condition of arr[i] > 2*arr[j]
        - increase the counter by (r1 - i + 1)
        => this is done since every element to right of i would also satisfy the condition
    - else increment "i" and check for next element at "i".
    => return count

    - Note: either use globle counter variable *[NOT RECCOMENDED]*
    OR 
    - Make the return types of merge sort to be integer 
        - and then return the counter by adding after each merge, merge sort & countInverse cycle.


*/

