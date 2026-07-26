#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 07:40:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Greedy Playlist #Valid Parenthesis Checker
// https://takeuforward.org/plus/dsa/problems/valid-parenthesis-checker?source=strivers-a2z-dsa-track
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea

/*
DESCRIPTION :
    Find the validity of an input string s that only contains the letters '(', ')' and '*'.

    A string entered is legitimate if:
        - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
        - Any right parenthesis ')' must have a corresponding left parenthesis '('.
        - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
        - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
    Input : s = "(*))"
    Output : true
    Explanation :
        The * can be replaced by an opening '(' bracket.
        The string after replacing the * mark is "(())" and is a valid string.

Example 2:
    Input : s = "*(()"
    Output : false
    Explanation :
        The * replaced with any bracket does not form a valid string.

Constraints:
    1 <= s.length <= 10^4
    s consist of only '(', ')', '*'.

*/ 


class Solution {
public:
    bool isValid1(string s) {
        //your code goes here
    }

    bool isValid2(string s) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    string s1 = "(*))";
    string s2 = "*(()";


    // Method Invocation & Result Visualization
    cout << boolalpha << sol.isValid1(s1) << endl;
    cout << sol.isValid1(s2) << endl;

    cout << sol.isValid2(s1) << endl;
    cout << sol.isValid2(s2) << endl;


    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N^2) | SC: O(N^2) | Brute Force (Recursion + DP)
    # Memoized recursion treating each '*' as '(', ')' or empty

2. TC: O(N) | SC: O(1) | OPTIMIZED
    # Track minOpen / maxOpen range of possible open parentheses

*/
