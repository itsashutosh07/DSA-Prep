#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;


// Creation DATE: July 26, 2026
// Creation TIME: 08:03:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's Graphs Playlist #AccountsMerge
// https://takeuforward.org/plus/dsa/problems/accounts-merge?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/accounts-merge/

/*
DESCRIPTION :
    Given accounts where each accounts[i] is [name, email1, ...], merge accounts that share any common email.
    Return merged accounts with name first then emails in sorted order.

Example 1:
    Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Example 2:
    Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co"],["Gabe","Gabe1@m.co","Gabe4@m.co"],["Gabe","Gabe0@m.co","Gabe4@m.co"]]
    Output: [["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co","Gabe4@m.co"]]

Constraints:
    1 <= accounts.length <= 1000
    2 <= accounts[i].length <= 10

*/ 


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<string>> a1 = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    // Method Invocation & Result Visualization
    printMatrix(sol.accountsMerge(a1));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N*K*alpha + N*K log(N*K)) | SC: O(N*K) | DSU
    # Union emails belonging to same account, group by parent
*/
