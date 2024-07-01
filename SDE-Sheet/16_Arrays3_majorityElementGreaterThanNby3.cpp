
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 01, 2024
// Creation TIME: 00:24:47

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #229. Majority Element II

/*
DESCRIPTION :
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.


Example 1:
    Input: nums = [3,2,3]
    Output: [3]

Example 2:
    Input: nums = [1]
    Output: [1]

Example 3:
    Input: nums = [1,2]
    Output: [1,2]
 

Constraints:
    - 1 <= nums.length <= 5 * 10^4
    - -10^9 <= nums[i] <= 10^9
 

Follow up: 
    - Could you solve the problem in linear time and in O(1) space?


*/ 


class Solution {
    public:
    vector<int> majorityElement1(vector<int>& nums) {
        int n = nums.size(), threshold = floor(n/3);
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > threshold) ans.push_back(x);
        }
        return ans;
    }

    vector<int> majorityElement2(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, candidate1 = INT_MIN, candidate2 = INT_MIN, n = nums.size();
        int threshold = floor(n/3);
        // cout << threshold << endl;
        vector<int> ans;

        for (int x : nums) {
            if (cnt1 == 0 && x != candidate2) {
                cnt1 = 1;
                candidate1 = x;
            }
            else if (cnt2 == 0 && x != candidate1) {
                cnt2 = 1;
                candidate2 = x;
            }
            else if (candidate1 == x){
                cnt1++;
            }
            else if (candidate2 == x){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        //cnt1 & cnt2 does not signify the number of occurence of candidate1 or candidate2
        cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if(x == candidate1) cnt1++;
            if(x == candidate2) cnt2++;
        }
        
        if (cnt1 > threshold)
            ans.push_back(candidate1);
        if (cnt2 > threshold)
            ans.push_back(candidate2);
        
        return ans;        
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {4, 5, 4, 5, 0, 1};
    vector<int> arr2 = {1};
    vector<int> arr3 = {1, 2};
    vector<int> arr4 = {4, 5, 4, 5, 4, 5, 4, 5, 0, 1, 2};


    // Method Invocation & Result Visualization
    printVector(sol.majorityElement1(arr1));
    printVector(sol.majorityElement1(arr2));
    printVector(sol.majorityElement1(arr3));
    printVector(sol.majorityElement1(arr4));

    printVector(sol.majorityElement2(arr1));
    printVector(sol.majorityElement2(arr2));
    printVector(sol.majorityElement2(arr3));
    printVector(sol.majorityElement2(arr4));


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    - We will run a loop that will select the elements of the array one by one.
    - For each element, run another loop and count its occurrence in the array.
    - If any element occurs more than the floor of (N/3), return it.


2. TC: O(n) | SC: O(n) | Better
    - Linear search by maintaining frequency count using unordered_map for each element
    - If frequency of current element in loop exceeds floor of (n/3) then simply return the current element.

3.  TC: O(n) | SC: O(1) | OPTIMIZED
    - Moore’s Voting Algorithm is efficient for finding elements that appear more than a certain threshold.
    - use for loop to iterate over each element once
    - only maintain the max occuring element so far as a possible candidates
    - this is done by mainataining merely 2 variables per candidate
        - candidate1 & candidate2 -> denotes possible max occuring element
        - counter1 & counter2 -> each get incremented if their candidate element is encountered
            - Decrement BOTH counters if any of the candidates isn't encountered. 
    - once any counter reaches 0, update its candidate with the current element and increase the counter to 1.
    - after loop ends, cnt1 & cnt2 does not signify the number of occurence of candidate1 or candidate2
    - hence, in another loop, verify if the said candidates have indeed more than threshold cardinality

*/

