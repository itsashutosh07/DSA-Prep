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

// Striver's Graphs Playlist #WordLadderII
// https://takeuforward.org/plus/dsa/problems/word-ladder-ii?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/word-ladder-ii/

/*
DESCRIPTION :
    Find all shortest transformation sequences from beginWord to endWord where each adjacent pair differs by one letter
    and each intermediate word is in wordList. Return all such sequences.

Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]

Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: []

Constraints:
    1 <= beginWord.length <= 5
    1 <= wordList.length <= 500

*/ 


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //your code goes here
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<string> wl1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> wl2 = {"hot", "dot", "dog", "lot", "log"};

    // Method Invocation & Result Visualization
    printMatrix(sol.findLadders("hit", "cog", wl1));
    printMatrix(sol.findLadders("hit", "cog", wl2));

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N * L^2 * 26 + paths) | SC: O(N*L + paths) | BFS + DFS/Backtrack
    # BFS for shortest levels, then backtrack all paths
*/
