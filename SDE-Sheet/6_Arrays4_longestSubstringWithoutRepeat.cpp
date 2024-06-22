
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 07, 2024
// Creation TIME: 20:51:47

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #3. Longest Substring Without Repeating Characters

/*
DESCRIPTION :
    Given a string s, find the length of the longest substring without repeating characters.


Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.

- Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:
    - 0 <= s.length <= 5 * 104
    - s consists of English letters, digits, symbols and spaces.

*/ 


class Solution {
    public:
    int lengthOfLongestSubstring1(string s) {
        int n = s.size();
        int currLen = 0, maxLen = 0;
        unordered_set<char> seen;
        for (int i = 0; i < n; i++) {
            currLen = 0;
            for (int j = i; j < n; j++) {
                if (seen.find(s[j]) == seen.end()) {
                    seen.insert(s[j]);
                    currLen++;
                    // if (currLen > maxLen) {
                    //     maxLen = currLen;
                    // }
                    continue;
                }
                else {
                    // if (currLen > maxLen) {
                    //     maxLen = currLen;
                    // }
                    break;
                }
            }
            if (currLen > maxLen) maxLen = currLen;
            seen.clear();
        }
        return maxLen;
    }

    int lengthOfLongestSubstring2(string s) {
        // TC: O(2N) and SC: O(n)
        int n = s.size();
        int currLen = 0, maxLen = 0;
        unordered_set<char> seen;

        int i = 0, j = 0;
        while (i < n && j<= i) {
            if (seen.find(s[i]) == seen.end()) {
                seen.insert(s[i]);
                i++;
            }
            else {
                seen.erase(s[j]);
                j++;
            }
            if (i-j > maxLen)
                maxLen = i-j;
        }

        return maxLen;
    }

    int lengthOfLongestSubstring3(string s) {
        // TC: O(N) and SC: O(n)
        int n = s.size();
        int currLen = 0, maxLen = 0;
        unordered_map<char, int> seen;

        int i = 0, j = 0;
        while (i < n) {
            if (seen.find(s[i]) != seen.end()) {
                int idx = seen[s[i]];
                if (j <= idx) {
                    j = idx+1;
                }
            }
            seen[s[i]] = i;
            i++;

            if (i-j > maxLen)
                maxLen = i-j;
        }

        return maxLen;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    string s1 = "ab";
    string s2 = "abcaabcdba";
    string s3 = "b";
    string s4 = "";
    string s5 = "aaaaaa";
    string s6 = "aaaabb00sjkbw3795@#VUYD*&YGVUY6r67fKHg97tTYSUJbu97r6DFUOG(&R8yfYFhjhjjhjhtswgcjcraujhb";


    // Method Invocation & Result Visualization
    cout << sol.lengthOfLongestSubstring3(s1) << endl;
    cout << sol.lengthOfLongestSubstring3(s2) << endl;
    cout << sol.lengthOfLongestSubstring3(s3) << endl;
    cout << sol.lengthOfLongestSubstring3(s4) << endl;
    cout << sol.lengthOfLongestSubstring3(s5) << endl;
    cout << sol.lengthOfLongestSubstring3(s6) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. O(N) Space & O(n^2) TC | Brute Force
    - in a nested for loop with i->n of outer loop, find all sub strings starting from i
        - inner loop will run from j = i+1 to n and find all sub-strings starting from i and ending at j
        - maintain hashset and if s[j] is not present in hashset
            - increment curr_len
            - also insert s[i] in hashset since it was not present currently and continue
        - else if s[i] present in hashset then break
        - in each inner loop, curr_len challanges max_len and if it is greater than max_len then update max_len


2. O(N) Space & O(2N) TC | Optimized
    - Maintain 2 pointers l,r = 0
    - while r < n
        - if s[r] is not found in hash_set
            - insert s[r] in hash_set and inrement r
        - else
            -erase s[l] and increment l
        - each time challange and increment max_sum if current_length of sub-array is greater than max_sum


3.  O(N) extra space & O(N) TC | OPTIMIZED
    - maintain a hash map of s[i],i where i demotes the index at which s[i] was last seen
    - this is used for jumping directly to appropriate l position rather than moving incrementally

    - Same as last code, take 2 ptrs left and right
    - while right < n
        - if s[right] is found in hash_map then 
            - update left ptr such that if left is at valid position then update it else leave left as it is
            - Valid: hash_map[s[right]] > left
        - Update hash_map entry of s[right] = right;
        - challange and increment max_sum if current_length of sub-array is greater than max_sum 
            - max_len = max(max_len, right - left + 1)
        - right++

*/

