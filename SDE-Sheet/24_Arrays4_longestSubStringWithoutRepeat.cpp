
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 05, 2024
// Creation TIME: 14:17:46

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

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:
    - 0 <= s.length <= 5 * 10^4
    - s consists of English letters, digits, symbols and spaces.


*/ 


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
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
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";


    // Method Invocation & Result Visualization
    cout << sol.lengthOfLongestSubstring(s1) << endl;
    cout << sol.lengthOfLongestSubstring(s2) << endl;
    cout << sol.lengthOfLongestSubstring(s3) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

