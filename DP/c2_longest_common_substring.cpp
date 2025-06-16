
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: April 24, 2025
// Creation TIME: 19:33:51

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Longest Common Substring
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

/*
DESCRIPTION :
    You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.


Example-1:
    Input: s1 = "ABCDGH", s2 = "ACDGHR"
    Output: 4
    Explanation: The longest common substring is "CDGH" with a length of 4.
    
Example-2:
    Input: s1 = "abc", s2 = "acb"
    Output: 1
    Explanation: The longest common substrings are "a", "b", "c" all having length 1.
    
Example-3:
    Input: s1 = "YZ", s2 = "yz"
    Output: 0


Constraints:
    - 1 <= s1.size(), s2.size() <= 10^3
    - Both strings may contain upper and lower case alphabets.

*/ 


class Solution {
private:
    /**
     * @brief Recursive helper function for Longest Common Substring.
     * @param a The first string.
     * @param b The second string.
     * @param n Current remaining length of string a (indices 0 to n-1).
     * @param m Current remaining length of string b (indices 0 to m-1).
     * @param count The length of the common substring *ending* exactly at a[n-1], b[m-1].
     * @return The maximum length of any common substring found within the
     *         computation subtree rooted at this call.
     */
    int lcSubstrRecursive(string a, string b, int n, int m, int currCount) {
        // Base case: If either string is exhausted, we can't extend the current
        // substring further. Return the length accumulated for this specific path.
        if (n == 0 || m == 0)
            return currCount;

        // Choice Diagram
        int res = currCount;
        if (a[n-1] == b[m-1])
            res = lcSubstrRecursive(a, b, n-1, m-1, currCount+1);

        return max({res,
            lcSubstrRecursive(a, b, n, m-1, 0),
            lcSubstrRecursive(a, b, n-1, m, 0)});
        
        /*** 
            Directly skip to tabulation for this problem, as memoization dp vector would use 3D vector (since currCount would also need to be cached) which is not space-efficient for this problem.
        */
    }

    int lcSubstrMemoized(string& a, string& b, int n, int m, int currCount, vector<vector<vector<int>>>& dp) {
        /*
            To memoize your current recursive method for Longest Common Substring correctly, you need to memoize all three parameters: n, m, and currCount. This is because the result depends not just on the positions in the strings, but also on the current length of the matching substring (currCount). If you memoize only on (n, m), you may get incorrect results for some edge cases, since the same (n, m) can be reached with different currCount values.
            Thus, the memoization table should be a 3D vector: dp[n+1][m+1][currCount+1].
            
            - dp[n][m][currCount] will store the maximum length of the common substring found for the first n characters of a and the first m characters of b, with the current matching substring length being currCount.
        */
        if (n == 0 || m == 0)
            return currCount;
    
        if (dp[n][m][currCount] != -1)
            return dp[n][m][currCount];
    
        int res = currCount;
        if (a[n-1] == b[m-1])
            res = lcSubstrMemoized(a, b, n-1, m-1, currCount+1, dp);
    
        res = max({res,
                   lcSubstrMemoized(a, b, n, m-1, 0, dp),
                   lcSubstrMemoized(a, b, n-1, m, 0, dp)});
    
        return dp[n][m][currCount] = res;
    }

    int lcSubstrTabulation(string a, string b, int n, int m, vector<vector<int>>& t) {
        // Base case
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        int ans = 0;

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    ans = max(ans, t[i][j]);
                }
                else
                    t[i][j] = 0;
            }
        }

        return ans;
    }

    public:
    int longestCommonSubstring(string a, string b) {
        /* Recursive approach */
        // return lcSubstrRecursive(a, b, a.size(), b.size(), 0);
        
        /* Memoization approach */
        // int n = a.size(), m = b.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(min(n, m)+1, -1)));
        // return lcSubstrMemoized(a, b, n, m, 0, dp);

        /* Tabulation approach */
        vector<vector<int>> t(a.size()+1, vector<int>(b.size()+1, 0));
        return lcSubstrTabulation(a, b, a.size(), b.size(), t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    string text1 = "ABCDGH", text2 = "ACDGHR";
    string text3 = "abc", text4 = "acb";
    string text5 = "YZ", text6 = "yz";
    string text7 = "ababcde", text8 = "abcde";
    string text9 = "cdmzkgmzkgytfmzkgmzkg", text10 = "dumzkgmzkghatmzkgmzkg";
    string text11 = "abcd", text12 = "abc";


    // Method Invocation & Result Visualization
    cout << sol.longestCommonSubstring(text1, text2) << endl; // 4
    cout << sol.longestCommonSubstring(text3, text4) << endl; // 1
    cout << sol.longestCommonSubstring(text5, text6) << endl; // 0
    cout << sol.longestCommonSubstring(text7, text8) << endl; // 5
    cout << sol.longestCommonSubstring(text9, text10) << endl; // 8
    cout << sol.longestCommonSubstring(text11, text12) << endl; // 3


    return 0;
}


/*
SOLUTIONS:-

# TC: O() | SC: O() | Recursion
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Memoization [Top-down]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Tabulation [Bottom-up]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

