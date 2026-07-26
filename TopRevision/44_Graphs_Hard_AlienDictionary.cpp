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

// Striver's Graphs Playlist #AlienDictionary
// https://takeuforward.org/plus/dsa/problems/alien-dictionary?subject=dsa&tab=editorial
// https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://leetcode.com/problems/alien-dictionary/
// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

/*
DESCRIPTION :
    Given a sorted dictionary (array of words) of an alien language, find the order of characters in the alien language.
    Return a string of unique letters in a valid order. If invalid, return an empty string.

Example 1:
    Input: words = ["baa","abcd","abca","cab","cad"]
    Output: "bdac"  (any valid order)

Example 2:
    Input: words = ["caa","aaa","aab"]
    Output: "cab"

Constraints:
    1 <= words.length <= 500
    1 <= words[i].length <= 100
    words[i] consists of lowercase English letters

*/ 


class Solution {
public:
	string findOrder(vector<string>& dict, int N, int K) {
		string order = "";
        vector<vector<int>> adj(K, vector<int> ());

        // create adj matrix
        for (int i = 1; i < N; i++) {
            string prevWord = dict[i-1];
            string currWord = dict[i];
            int prevWordLen = prevWord.size(), currWordLen = currWord.size();
            int minWordLen = min(prevWordLen, currWordLen);
            // cout << "Comparing : " << prevWord << " [v/s] " << currWord << endl;

            for (int j = 0; j < minWordLen; j++) {
                char prevChar = prevWord[j], currChar = currWord[j];
                // cout << "\tFor : " << prevChar << " [v/s] " << currChar << endl;
                if (prevWord[j] != currWord[j]) {
                    // cout << "\t\tDiff found: " << prevChar << "->" << currChar << endl;
                    adj[prevChar - 'a'].push_back(currChar - 'a');
                    break;
                }
            }
        }

        // create indegree vector
        vector<int> inDegree(K, 0);
        for(int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                // i -> it
                inDegree[it]++;
            }
        }

        // if inDegree == 0 push into Q and start topo sort
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                order += 'a' + i;
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int node : adj[curr]) {
                inDegree[node]--;
                if (inDegree[node] == 0) {
                    q.push(node);
                    order += 'a' + node;
                }
            }
        }
        // cout << order << endl;
        // if inDegreeZeroNodes aka: order.size() == N -> all nodes processed and we have a valid dict
        if (order.size() == K)
            return order;
        
        return "";
	}
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<string> w1 = {"baa", "abcd", "abca", "cab", "cad"};
    vector<string> w2 = {"caa", "aaa", "aab"};

    // Method Invocation & Result Visualization
    cout << sol.findOrder(w1, 5, 4) << endl;
    cout << sol.findOrder(w2, 3, 3) << endl;

    return 0;
}


/*
SOLUTIONS:-

1. TC: O(N*K + V+E) | SC: O(V+E) | Graph + Kahn's/DFS
    # Build char precedence graph from adjacent words, topo sort
*/
