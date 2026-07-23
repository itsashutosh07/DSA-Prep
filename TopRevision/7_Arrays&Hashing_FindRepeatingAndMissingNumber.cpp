
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: May 27, 2026
// Creation TIME: 00:37:14

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #Question_Title

/*
DESCRIPTION :
    Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
    Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.
    
    Note: You are not allowed to modify the original array.


Example 1
    Input: nums = [3, 5, 4, 1, 1]
    Output: [1, 2]
    Explanation:
    1 appears two times in the array and 2 is missing from nums

Example 2
    Input: nums = [1, 2, 3, 6, 7, 5, 7]
    Output: [7, 4]
    Explanation:
    7 appears two times in the array and 4 is missing from nums.


Constraints
    n == nums.length
    1 <= n <= 105
    n - 2 elements in nums appear exactly once and are valued between [1, n].
    1 element in nums appears twice, and is valued between [1, n].

*/ 


class Solution {
public:
    vector<int> findMissingRepeatingNumbersBrute(vector<int> nums) {
        // loop for each number from 1->N
        // lenear search in array and count the total occurance of the number
        // if at the end of iteration, 
        // cnt == 0 --> missingNumber
        // cnt == 2 --> repeating number
        // If both missing and repeating are found, break further iterartions and return result
        
        int missingNumber = -1, repeatingNumber = -1;
        for (int k = 1; k <= nums.size(); k++) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == k) cnt++;
            }
            if (cnt == 0) missingNumber = k;
            else if (cnt == 2) repeatingNumber = k;

            if (missingNumber != -1 && repeatingNumber != -1)
                break;
        }

        return {repeatingNumber, missingNumber};
    }
    vector<int> findMissingRepeatingNumbersMapBased(vector<int> nums) {
        // maintain a frequency of all the elements in the array in a hash map / simply a n+1 size array(since the numbers are from 1->n)
        // Once done, loop through the numbers from 1 -> N and find the element with missing / repeating element
        // return the {repeatingNumber, missingNumber}

        int n = nums.size(), repeatingNumber = -1, missingNumber = -1;
        vector<int> freq (n+1, 0);
        
        for(int x : nums) 
            freq[x]++;

        for (int i = 1; i <= n; i++) {
            if (freq.find(i) == freq.end()){
                // element not found
                missingNumber = i;
            }
            else if (freq[i] > 1) {
                // dupicate element
                repeatingNumber = i;
            }
        }
        
        return {repeatingNumber, missingNumber};
    }
    
    vector<int> findMissingRepeatingNumbersConvertToNegative(vector<int> nums) {
        // for finding repeating number
        int missing = -1, repeating = -1;
        for (int i = 0; i < arr.size(); i++) {
            int currNum = arr[i];
            if (arr[abs(currNum)-1] < 0) {
                repeating = abs(currNum);
            }
            else {
                arr[abs(currNum)-1] = arr[abs(currNum) - 1] * -1;
            }
        }
        
        // for finding the missing number
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                missing = i+1;
                break;
            }
        }
        
        return {repeating, missing};
    }
    vector<int> findMissingRepeatingNumbersSwapSort(vector<int> nums) {
        // 1 1 3 4 5
        // 1 2 3 4 5
        // (n * (n-1) / 2) - sn = a - b

        //  
    }
};

int main() 
{
    Solution sol;

    // Input Initialization


    // Method Invocation
    cout << sol.method_name(param1) << endl;



    // Result Visualization



    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    We loop through 1->N and then we check for each element via liner search the frequency of that number. This takes N*N TC.
    We do not store any other extra data structure other than the 2 varables for missing/repeating numbers.

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

