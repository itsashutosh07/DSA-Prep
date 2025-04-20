
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: April 20, 2025
// Creation TIME: 17:08:19

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Rod Cutting
// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

/*
DESCRIPTION :
    Given a rod of length n inches and an array price[]. price[i] denotes the value of a piece of length i. The task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

    Note: price[] is 1-indexed array.


Example 1: 
    Input: price[] =  [1, 5, 8, 9, 10, 17, 17, 20]
    Output: 22
    Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

Example 2: 
    Input : price[] =  [3, 5, 8, 9, 10, 17, 17, 20]
    Output : 24
    Explanation : The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.

Example 3: 
    Input : price[] =  [3]
    Output : 3
    Explanation: There is only 1 way to pick a piece of length 1.


Constraints:
    - 1 ≤ price.size() ≤ 10^3
    - 1 ≤ price[i] ≤ 10^6

*/ 


class Solution {
private:
    int maxProfitRecursive(vector<int>& prices, int n, int l) {
        // Base case
        if (l == 0 || n == 0)
            return 0;

        // Choice Diagram
        if (n <= l) 
            return max(prices[n-1] + maxProfitRecursive(prices, n, l-n),
                        maxProfitRecursive(prices, n-1, l));
        else 
            return maxProfitRecursive(prices, n-1, l);

        return 0;
    }

    int maxProfitMemoization(vector<int>& prices, int n, int l, vector<vector<int>>& t) {
        // Base case
        if (l == 0 || n == 0)
            return 0;

        // Cache
        if (t[n][l] != -1)
            return t[n][l];

        // Choice Diagram
        if (n <= l) 
            t[n][l] = max(prices[n-1] + maxProfitMemoization(prices, n, l-n, t), maxProfitMemoization(prices, n-1, l, t));
        else 
            t[n][l] = maxProfitMemoization(prices, n-1, l, t);

        return t[n][l];
    }

    int maxProfitBottomUp(vector<int>& prices, int n, int l, vector<vector<int>>& t) {
        // Initialization
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= l; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= l; j++) {
                if (i <= j) {
                    t[i][j] = max(prices[i-1] + t[i][j-i], t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][l];
    }

public:
    int cutRod(vector<int>& prices) {
        int l = prices.size(), n = prices.size();
        vector<vector<int>> t (n+1, vector<int> (n+1, -1));

        // return maxProfitRecursive(prices, n, l);
        // return maxProfitMemoization(prices, n, l, t);
        return maxProfitBottomUp(prices, n, l, t);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> rod1 = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> rod2 = {3, 5, 8, 9, 10, 17, 17, 20};
    vector<int> rod3 = {1, 10, 3, 1, 3, 1, 5, 9};

    // Method Invocation & Result Visualization
    cout << sol.cutRod(rod1) << endl;
    cout << sol.cutRod(rod2) << endl;
    cout << sol.cutRod(rod3) << endl;

    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^n) | SC: O(n) | Recursion
    Time Complexity:  O(2^n) — For each length, we can either cut or not cut, leading to exponential combinations.
    Space Complexity: O(n) — Due to recursion stack depth (maximum n calls).

# TC: O(n * l) | SC: O(n * l) | Memoization [Top-down]
    Time Complexity:  O(n * l) — Each state (n, l) is computed once, where n = number of possible cuts, l = rod length.
    Space Complexity: O(n * l) — For the memoization table, plus O(n) recursion stack.

# TC: O(n * l) | SC: O(n * l) | Tabulation [Bottom-up]
    Time Complexity:  O(n * l) — Filling a DP table of size (n+1) x (l+1).
    Space Complexity: O(n * l) — For the DP table.
    
# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

