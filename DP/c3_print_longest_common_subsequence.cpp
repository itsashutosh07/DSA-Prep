
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: June 16, 2025
// Creation TIME: 07:58:36

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Question_Title
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

/*
DESCRIPTION :



*/ 


class Solution {
    public:
    // Skipping recursive and memoized versions for brevity, as the iterative version is more efficient for this problem.
    
    /* Iterative function to print the Longest Common Subsequence (LCS) of two strings */
    /***
    This function:
      1. builds a DP table to find the length of the LCS 
      2. and then backtracks to construct the LCS string.
    */
    void printLcsIterative(string a, string b) {
        // Build DP table for LCS
        int m = a.size(), n = b.size();
        vector<vector<int>> t (m+1, vector<int> (n+1, -1));

        // Initialisation
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        // Choice Diagram
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else 
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }

        string lcs = "";

        while (m > 0 && n > 0) {
            if (a[m-1] == b[n-1]) {
                lcs = a[m-1] + lcs;
                m--;
                n--;
            }
            else {
                if (t[m-1][n] > t[m][n-1]){
                    m--;
                }
                else {
                    n--;
                }
            }
        }

        cout << lcs << endl;

    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    string a = "AGGTAB";
    string b = "GXTXAYB";
    
    string text1 = "abcde", text2 = "ace";
    string text3 = "abc", text4 = "abc";
    string text5 = "abc", text6 = "def";
    string text7 = "cbazuxmhecthlegrpunkdmbppweqtgjoparmowzdqyoxytjbbhawdydcprjbxphoohpkwqyuhrqzhnbnfuvqnqqlrzjpxiogvliexdzuzosrkrusvojbrzmwzpowkjilefraamdigpnpuuhgxpqnjwjmwaxxmnsnhhlqqrzudltfzotcjtnzxuglsdsmzcnockvfajfrmxothowkbjzwucwljfrimpmyhchzriwkbarxbgfcbceyhjugixwtbvtrehbbcpxifbxvfbcgkcfqckcotzgkubmjrmbsztsshfroefwsjrxjhguzyupzwweiqurpixiqflduuveoowqcudhnefnjhaimuczfskuiduburiswtbrecuykabfcvkdzeztoidukuhjzefczzzbfkqdpqzikfobucdhthxdjgkjelrlpaxamceroswitdptpcclifkeljytihrcqaybnefxnxvgzedyyhngycdrudmphmeckotrwospofghfozqvlqfxwwkmfxdyygmdcaszsgovsodkjghcwmbmxrmhuyfyqgajqkcklznayxqkqoyzwmyubzazcpkhktkydzivcuypurfmbisgekyrgzvxdhpoamvafyrarxsvkhtqdihersigbhzjzujxmmyspnaraewkegjccvhhrjvbjtsqdjootgpknfpfycgfieowqrwwwpzsqmetogepspxnvjiupalyynmkmnuvklhsecdwracgfmzkgipdfodkjmjqwiqpuoqhimvfvuzwyvijgfullkj";
    string text8 = "duhsjafbtlkmfqrmyjfjnhhssqctydteamdcjbprhtnegyiwxgcjwlgrsmeaearwtvjsjbaoiojlwhypnvruihoswkifygtydhacwyhsgewzmtgonzltjhgauhnihreqgjfwkjsmtpjhaefqzaauldrchjccdyrfvvrivuyeegfivdrcygurqdredakubnfguproqylobcwqxkzmausjgmhcmhgdnmphnqkamhurktrffaclvgrzkkldacllteojomonxrqyjzginrnnzwacxxaedrwudxzrfusewjtboxvynfhkstcenaumnddxfdmvzcautdcckxaaydzsxttobbgqngvvpjgojoglmkxgbfcpypckqchbddzwrxbzmqrlxvobtwhxginfgfrcclmznmjugwwbsqfcihubsjollmsqsghmcphelsotflbgsfnpcuzsrupchynvzhcpqugriwniqxdfjpwpxfblkpnpeelfjmtkuqpzomwnlmbupmktlptndmpdsydsgvfpenemwborifsuqhceskmkhssmvnonwafxwhgbibabvqopqfoviussqfqwehtxdzujtlntxmrjxxwtlggkytbiolydnilqadojskkvfxahhjmbocljarintdwcldvdxropbyjzwyyojuothwmlvrglfzdzdbtubxuoffvncrswsaznmoijoivvgobqpnckwvnhkebmtdhvygkjisuxhatmuudqbhmknhfxaxqxkjlzzqtsjfaeedfuujkolxjoqkdvfepvlhvhrwtfdukxffjpsswyxlijjhevryxozbafpfmowgrgonuatdqlahyggyljddjhmltedzlodsrkeutgtnkntarjkpxinovgzdthunwooxvjjmpsvknhkwjopmmlebksucvzqlyqn";
    string text9 = "jgjahiuagugajkvwhfhsjfvhxijyshv", text10 = "kjaboiuzhpiohsjlbndvjgcjgvcjh";

    // Method Invocation & Result Visualization
    sol.printLcsIterative(a, b);
    sol.printLcsIterative(text1, text2);
    sol.printLcsIterative(text3, text4);
    sol.printLcsIterative(text5, text6);
    sol.printLcsIterative(text7, text8);
    sol.printLcsIterative(text9, text10);

    return 0;
}


/*
SOLUTIONS:-

# TC: O(n * m) | SC: O(n * m) | Tabulation [Bottom-up]
    Time Complexity:  O(n * m) — For filling DP table O(n*m) + backtracking to print LCS O(n+m)
    Space Complexity: O(n * m) — For DP table + O(min(n,m)) for storing the LCS string

# TC: O(n * m) | SC: O(n) | Space-Optimized
    Time Complexity:  O(n * m) — Same as above (can't optimize time for printing)
    Space Complexity: O(n) — Using only previous row + O(min(n,m)) for LCS string

Note: Here n and m are lengths of input strings a and b respectively.

*/

