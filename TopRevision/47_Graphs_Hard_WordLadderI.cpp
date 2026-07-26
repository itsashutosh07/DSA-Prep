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

// Striver's Graphs Playlist #WordLadderI
// https://takeuforward.org/plus/dsa/problems/word-ladder-i?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/word-ladder/

/*
DESCRIPTION :
    A transformation sequence from beginWord to endWord uses words from wordList where each adjacent pair differs by one letter.
    Return the number of words in the shortest transformation sequence, or 0 if none exists.

Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5

Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: 0

Constraints:
    1 <= beginWord.length <= 10
    1 <= wordList.length <= 5000

*/ 


class Solution{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({startWord, 1});
        
        while (!q.empty()) {
            string curr = q.front().first;
            int level = q.front().second;
            q.pop();

            if (curr == targetWord)
                return level;

            int len = curr.size();
            for (int i = 0; i < len; i++) {
                string temp = curr; 
                for (int alpha = 'a'; alpha <= 'z'; alpha++) {
                    temp[i] = alpha;
                    if (words.find(temp) != words.end()) {
                        words.erase(temp);
                        q.push({temp, level+1});
                    }
                }
            }
        }

        return 0;
    }
};

int main() 
{
    Solution sol;

    // Input Initialization
    vector<string> wl1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> wl2 = {"hot", "dot", "dog", "lot", "log"};
    vector<string> wl3 = {"des","der","dfr","dgt","dfs"};

    // Method Invocation & Result Visualization
    cout << sol.wordLadderLength("hit", "cog", wl1) << endl;
    cout << sol.wordLadderLength("hit", "cog", wl2) << endl;
    cout << sol.wordLadderLength("dfs", "der", wl3) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N * L^2 * 26) | SC: O(N*L) | BFS
    # Each word is a graph node; edges to 1-letter variants
*/
