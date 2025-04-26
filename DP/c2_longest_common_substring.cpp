
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
    int lcSubstrRecursive(string a, string b, int n, int m, int& currCount) {
        // Base case
        if (n == 0 || m == 0)
            return currCount;

        // Choice Diagram
        if (a[n-1] == b[m-1]){
            currCount += 1;
            return 1 + lcSubstrRecursive(a, b, n-1, m-1, currCount);
        }
        else {
            currCount = 0;
        }
        return max({currCount,
            lcSubstrRecursive(a, b, n, m-1, currCount),
            lcSubstrRecursive(a, b, n-1, m, currCount)});
    }

    int lcSubstrMemoized(string a, string b, int n, int m, int currCount, vector<vector<int>>& t) {
        // Base case
        if (n == 0 || m == 0)
            return 0;

        if (t[n][m] != -1)
            return t[n][m];

        // Choice Diagram
        if (a[n-1] == b[m-1]){
            currCount += 1;
            return lcSubstrMemoized(a, b, n-1, m-1, currCount, t);
        }
        return max({currCount,
            lcSubstrMemoized(a, b, n-1, m, 0, t),
            lcSubstrMemoized(a, b, n, m-1, 0, t)});
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
        int currCount = 0;
        lcSubstrRecursive(a, b, a.size(), b.size(), currCount);
        return currCount;
        
        // vector<vector<int>> t (a.size()+1, vector<int>(b.size()+1, -1));
        // return lcSubstrMemoized(a, b, a.size(), b.size(), 0, t);
        // return lcSubstrTabulation(a, b, a.size(), b.size(), t);
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
    string text9 = "cdytcthgcgcnbcctxfmzkgipdfodkjmjqwiqpuoqhimvfvuzwyvijg";
    string text10 = "duhathgcgymzkgipdfodkjmjqwiqpuoqhimvfvuzwyvijg";


    // Method Invocation & Result Visualization
    cout << sol.longestCommonSubstring(text1, text2) << endl; // 4
    cout << sol.longestCommonSubstring(text3, text4) << endl; // 1
    cout << sol.longestCommonSubstring(text5, text6) << endl; // 0
    cout << sol.longestCommonSubstring(text7, text8) << endl; // 5
    cout << sol.longestCommonSubstring(text9, text10) << endl; // 9


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

