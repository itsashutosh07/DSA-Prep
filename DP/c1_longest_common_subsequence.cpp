
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: April 24, 2025
// Creation TIME: 17:14:37

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/

/*
DESCRIPTION :
    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.
 

Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:
    - 1 <= text1.length, text2.length <= 1000
    - text1 and text2 consist of only lowercase English characters.

*/ 


class Solution {
    private:
    int lcsRecursive(string a, string b, int n, int m) {
        // Base case: If either string is empty, the LCS length is 0.
        if (n == 0 || m == 0)
            return 0;

        // Choice Diagram
        if (a[n - 1] == b[m - 1]) {
            // If they match, this character is part of the LCS.
            // Add 1 and find LCS of the remaining prefixes.
            return 1 + lcsRecursive(a, b, n-1, m-1);
        }
        else {   
            // If they don't match, the LCS is the longer of:
            // 1. LCS excluding the last char of 'a' (a[0...n-2], b[0...m-1])
            // 2. LCS excluding the last char of 'b' (a[0...n-1], b[0...m-2)
            return max(lcsRecursive(a, b, n-1, m), lcsRecursive(a, b, n, m-1));
        }
        return -1;
    }

    int lcsMemoized(string a, string b, int n, int m, vector<vector<int>>& t) {
        // Base case
        if (n == 0 || m == 0)
            return 0;

        if (t[n][m] != -1)
            return t[n][m];

        if (a[n-1] == b[m-1])
            return t[n][m] = (1 + lcsMemoized(a, b, n-1, m-1, t));
        else
            return t[n][m] = max(lcsMemoized(a, b, n-1, m, t), lcsMemoized(a, b, n, m-1, t));

        return -1;
    }

    int lcsTabulation(string a, string b, int n, int m, vector<vector<int>>& t) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) 
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i<= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }

        return t[n][m];
    }

    public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> t (a.size()+1, vector<int>(b.size()+1, -1));
        // return lcsRecursive(a, b, a.size(), b.size());
        // return lcsMemoized(a, b, a.size(), b.size(), t);
        return lcsTabulation(a, b, a.size(), b.size(), t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    string a = "abcdgh", b = "abedfhr";
    string text1 = "abcde", text2 = "ace";
    string text3 = "abc", text4 = "abc";
    string text5 = "abc", text6 = "def";
    string text7 = "cbazuxmhecthlegrpunkdmbppweqtgjoparmowzdqyoxytjbbhawdydcprjbxphoohpkwqyuhrqzhnbnfuvqnqqlrzjpxiogvliexdzuzosrkrusvojbrzmwzpowkjilefraamdigpnpuuhgxpqnjwjmwaxxmnsnhhlqqrzudltfzotcjtnzxuglsdsmzcnockvfajfrmxothowkbjzwucwljfrimpmyhchzriwkbarxbgfcbceyhjugixwtbvtrehbbcpxifbxvfbcgkcfqckcotzgkubmjrmbsztsshfroefwsjrxjhguzyupzwweiqurpixiqflduuveoowqcudhnefnjhaimuczfskuiduburiswtbrecuykabfcvkdzeztoidukuhjzefczzzbfkqdpqzikfobucdhthxdjgkjelrlpaxamceroswitdptpcclifkeljytihrcqaybnefxnxvgzedyyhngycdrudmphmeckotrwospofghfozqvlqfxwwkmfxdyygmdcaszsgovsodkjghcwmbmxrmhuyfyqgajqkcklznayxqkqoyzwmyubzazcpkhktkydzivcuypurfmbisgekyrgzvxdhpoamvafyrarxsvkhtqdihersigbhzjzujxmmyspnaraewkegjccvhhrjvbjtsqdjootgpknfpfycgfieowqrwwwpzsqmetogepspxnvjiupalyynmkmnuvklhsecdwracgfmzkgipdfodkjmjqwiqpuoqhimvfvuzwyvijgfullkj";
    string text8 = "duhsjafbtlkmfqrmyjfjnhhssqctydteamdcjbprhtnegyiwxgcjwlgrsmeaearwtvjsjbaoiojlwhypnvruihoswkifygtydhacwyhsgewzmtgonzltjhgauhnihreqgjfwkjsmtpjhaefqzaauldrchjccdyrfvvrivuyeegfivdrcygurqdredakubnfguproqylobcwqxkzmausjgmhcmhgdnmphnqkamhurktrffaclvgrzkkldacllteojomonxrqyjzginrnnzwacxxaedrwudxzrfusewjtboxvynfhkstcenaumnddxfdmvzcautdcckxaaydzsxttobbgqngvvpjgojoglmkxgbfcpypckqchbddzwrxbzmqrlxvobtwhxginfgfrcclmznmjugwwbsqfcihubsjollmsqsghmcphelsotflbgsfnpcuzsrupchynvzhcpqugriwniqxdfjpwpxfblkpnpeelfjmtkuqpzomwnlmbupmktlptndmpdsydsgvfpenemwborifsuqhceskmkhssmvnonwafxwhgbibabvqopqfoviussqfqwehtxdzujtlntxmrjxxwtlggkytbiolydnilqadojskkvfxahhjmbocljarintdwcldvdxropbyjzwyyojuothwmlvrglfzdzdbtubxuoffvncrswsaznmoijoivvgobqpnckwvnhkebmtdhvygkjisuxhatmuudqbhmknhfxaxqxkjlzzqtsjfaeedfuujkolxjoqkdvfepvlhvhrwtfdukxffjpsswyxlijjhevryxozbafpfmowgrgonuatdqlahyggyljddjhmltedzlodsrkeutgtnkntarjkpxinovgzdthunwooxvjjmpsvknhkwjopmmlebksucvzqlyqn";

    // Method Invocation & Result Visualization
    cout << sol.longestCommonSubsequence(a, b) << endl;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;
    cout << sol.longestCommonSubsequence(text3, text4) << endl;
    cout << sol.longestCommonSubsequence(text5, text6) << endl;
    cout << sol.longestCommonSubsequence(text7, text8) << endl;



    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^(n+m)) | SC: O(n+m) | Recursion
    Time Complexity:  O(2^(n+m)) — For each character in both strings, we branch into two possibilities (include or exclude), leading to exponential combinations.
    Space Complexity: O(n+m) — Due to recursion stack depth (maximum n+m calls).

# TC: O(n * m) | SC: O(n * m) | Memoization [Top-down]
    Time Complexity:  O(n * m) — Each state (n, m) is computed once, where n = length of first string, m = length of second string.
    Space Complexity: O(n * m) — For the memoization table, plus O(n+m) recursion stack.

# TC: O(n * m) | SC: O(n * m) | Tabulation [Bottom-up]
    Time Complexity:  O(n * m) — Filling a DP table of size (n+1) x (m+1).
    Space Complexity: O(n * m) — For the DP table.

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

