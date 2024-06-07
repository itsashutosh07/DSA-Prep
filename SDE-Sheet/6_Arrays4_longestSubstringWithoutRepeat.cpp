
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
            seen.insert(s[i]);
            currLen = 1;
            for (int j = i+1; j < n; j++) {
                if (seen.find(s[j]) == seen.end()) {
                    seen.insert(s[j]);
                    currLen++;
                    if (currLen > maxLen) {
                        maxLen = currLen;
                    }
                    continue;
                }
                else {
                    if (currLen > maxLen) {
                        maxLen = currLen;
                    }
                    break;
                }
            }
            if (currLen > maxLen) {
                maxLen = currLen;
            }
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
    cout << sol.lengthOfLongestSubstring2(s1) << endl;
    cout << sol.lengthOfLongestSubstring2(s2) << endl;
    cout << sol.lengthOfLongestSubstring2(s3) << endl;
    cout << sol.lengthOfLongestSubstring2(s4) << endl;
    cout << sol.lengthOfLongestSubstring2(s5) << endl;
    cout << sol.lengthOfLongestSubstring2(s6) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. O(N) Space & O(n^2) TC | Brute Force


2. O(N) Space & O(2N) TC | Optimized


3.  O(N) extra space & O(N) TC | OPTIMIZED


*/

