
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: April 20, 2025
// Creation TIME: 18:16:44

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Coin Change - I (Count Ways)
// https://www.geeksforgeeks.org/coin-change-dp-7/


/*
DESCRIPTION :
    Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
    
    Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
    Answers are guaranteed to fit into a 32-bit integer. 

Example-1:
    Input: coins[] = [1, 2, 3], sum = 4
    Output: 4
    Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].

Example-2:
    Input: coins[] = [2, 5, 3, 6], sum = 10
    Output: 5
    Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].

Examples-3:
    Input: coins[] = [5, 10], sum = 3
    Output: 0
    Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.


Constraints:
    - 1 <= sum <= 10^3
    - 1 <= coins[i] <= 10^4
    - 1 <= coins.size() <= 10^3

*/ 


class Solution {
    private:
    int coinChange1Recursive(vector<int>& coins, int sum, int n) {
        // Base Case
        if (n == 0)
            return (sum == 0);

        // Choice Diagram
        if (coins[n-1] <= sum)
            return coinChange1Recursive(coins, sum - coins[n-1], n) + coinChange1Recursive(coins, sum, n-1);
        else
            return coinChange1Recursive(coins, sum, n-1);

        return -1;
    }

    int coinChange1Memoised(vector<int>& coins, int sum, int n, vector<vector<int>>& t) {
        // Base Case
        if (n == 0)
            return (sum == 0);

        if (t[n][sum] != -1)
            return t[n][sum];

        // Choice Diagram
        if (coins[n-1] <= sum)
            t[n][sum] = coinChange1Memoised(coins, sum - coins[n-1], n, t) + coinChange1Memoised(coins, sum, n-1, t);
        else
            t[n][sum] = coinChange1Memoised(coins, sum, n-1, t);

        return t[n][sum];
    }

    int coinChange1Tabulation(vector<int>& coins, int sum, int n, vector<vector<int>>& t) {
        // Initialization
        for (int j = 0; j <= sum; j++) {
            t[0][j] = (j == 0);
        }

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (coins[i-1] <= j)
                    t[i][j] = t[i][j - coins[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

    int coinChange1SpaceOptimised(vector<int>& coins, int sum) {
        int n = coins.size();

        // Create a 1D DP array where t[j] will store the number of ways to make sum 'j'
        // Initialize all values to 0
        vector<int> t(sum+1, 0);

        // Base case: There is exactly 1 way to make sum 0 (by choosing no coins)
        t[0] = 1;

        // Iterate over each coin 
        for (int i = 0; i < n; i++) {
            // For the current coin, update the number of ways to make every sum from coins[i] up to 'sum'
            // We start from coins[i] because we can't make sums less than the coin's value using this coin
            for (int j = coins[i]; j <= sum; j++) {
                // For each sum j, add the number of ways to make (j - coins[i])
                // This represents including the current coin at least once
                // The value t[j - coins[i]] already contains all ways to make (j - coins[i]) using coins up to i (including unlimited uses)
                t[j] += t[j - coins[i]];
            }
        }

        // The answer is the number of ways to make 'sum' using all coins
        return t[sum];
    }

    public:
    int countWays(vector<int>& coins, int sum) {
        int n = coins.size();
        // return coinChange1Recursive(coins, sum, n);

        vector<vector<int>> t (n+1, vector<int>(sum+1, -1));
        // return coinChange1Memoised(coins, sum, n, t);
        return coinChange1Tabulation(coins, sum, n, t);
        return coinChange1SpaceOptimised(coins, sum);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> coins1 = {1, 2, 3};     int sum1 = 4;
    vector<int> coins2 = {2, 5, 3, 6};  int sum2 = 10;
    vector<int> coins3 = {5, 10};       int sum3 = 3;

    // Method Invocation & Result Visualization
    cout << sol.countWays(coins1, sum1) << endl;
    cout << sol.countWays(coins2, sum2) << endl;
    cout << sol.countWays(coins3, sum3) << endl;


    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^n*sum) | SC: O(sum) | Recursion
    Time Complexity:  O(2^n * sum) — For each coin, at each sum, we can either include or exclude, leading to exponential combinations.
    Space Complexity: O(sum) — Due to recursion stack depth (maximum sum calls in the worst case).

# TC: O(n * sum) | SC: O(n * sum) | Memoization [Top-down]
    Time Complexity:  O(n * sum) — Each state (n, sum) is computed once.
    Space Complexity: O(n * sum) — For the memoization table, plus O(sum) recursion stack.

# TC: O(n * sum) | SC: O(n * sum) | Tabulation [Bottom-up]
    Time Complexity:  O(n * sum) — Filling a DP table of size (n+1) x (sum+1).
    Space Complexity: O(n * sum) — For the DP table.

# TC: O(n * sum) | SC: O(sum) | Space-Optimized
    Time Complexity:  O(n * sum)
    Space Complexity: O(sum) — By using a 1D DP array instead of a 2D table.

*/

