
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 02, 2024
// Creation TIME: 02:11:17

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #128. Longest Consecutive Sequence

/*
DESCRIPTION :
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.


Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
 

Constraints:
    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

*/ 


class Solution {
    public:
    bool linearSearch(vector<int>&a, int num) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }
    int longestConsecutive1(vector<int>&nums) {
        // TC: O(N^2) || SC: O(1)
        int n = nums.size();
        int longest = 1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 1;
            while (linearSearch(nums, x + 1) == true) {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }

    int longestConsecutive2(vector<int>& nums) {
        // TC: O(NlogN) + O(N) || SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size(), prev = INT_MIN, curr, currLen, ans = 0;
        for (int i = 0; i < n; i++) {
            curr = nums[i];
            if (curr - 1 == prev) {
                currLen++;
            }
            else if (curr != prev) {
                currLen = 1;
            }
            prev = curr;
            ans = max(ans, currLen);
        }
        return ans;
    }

    int longestConsecutive3(vector<int>& nums) {
        // TC: O(N) || SC: O(N)
        unordered_set<int> numSet (nums.begin(), nums.end());
        int ans = 0, currLen, prev;

        for (int x : numSet) {
            if (numSet.find(x-1) == numSet.end()) {
                currLen = 1;
                while (numSet.find(x+1) != numSet.end()) {
                    currLen++;
                    x++;
                }
                ans = max(ans, currLen);
            }
        }
        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {100, 4, 200, 1, 3, 2};
    vector<int> arr2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    // Method Invocation & Result Visualization
    cout << sol.longestConsecutive1(arr1) << endl;
    cout << sol.longestConsecutive1(arr2) << endl;

    cout << sol.longestConsecutive2(arr1) << endl;
    cout << sol.longestConsecutive2(arr2) << endl;

    cout << sol.longestConsecutive3(arr1) << endl;
    cout << sol.longestConsecutive3(arr2) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    # Linear search per each element in a loop
    - Use a for loop to iterate over each element
    - for each element x in the for loop, do a linear_search till the sequence formed by x is exhausted
    - initialize x as curr_element and set curr_cnt = 1
    - while next element of sequence existes: increment curr_cnt and increment element x
    - when the next element does not exist: challenge max_cnt with curr_cnt value 
    - for next element x of the for loop, repeat the same process till for loop is exhausted
    - return max_cnt

2. TC: O(NlogN) | SC: O(1) | Better
    # Sort to club sequence together then count longest sequence
    - Sort the array
    - elements in the sequence will be consecutive to each other now.
    - similar to lined list style, initalize prev as INT_MIN, curr as 1st element of array
    - in a for loop iterate over each element : 'x'
        - set curr_element = x
        - if x-1 == prev: this means sequence exists -> cnt++
        - else if x == prev: duplicate is encountered -> do nothing     *[skip this condition]*
        - else if x != prev: start of a new sequence is encountered -> reset curr_cnt to 1 
        - challenge max_cnt with curr_cnt
        - update prev as curr to prepare for next iteration
    - return max_cnt

3.  TC: O(N) | SC: O(N) | OPTIMIZED
    # transfer arr to set -> only for 1st element of each sequence, loop till sequence breaks
    - initalise an unordered_set with elements in arr
    - use for loop to iterate over each element in the set
    - for only thse elements that mark the start of the sequence, i.e. for element x -> x-1 not in set
        - use while loop to count the total elemets for that sequence.
    - challenge max_len with curr_len and update max_len if curr_len is greater
    - return max_len

*/

