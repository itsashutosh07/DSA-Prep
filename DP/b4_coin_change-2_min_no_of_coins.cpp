
#include <bits/stdc++.h>
#include "../dgb.hpp"

#define INF INT_MAX-1

using namespace std;

// Creation DATE: April 20, 2025
// Creation TIME: 23:57:24

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Coin Change (Minimum Coins)
// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

/*
DESCRIPTION :
    Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.


Example-1:
    Input: coins[] = [25, 10, 5], sum = 30
    Output: 2
    Explanation: Minimum 2 coins needed, 25 and 5  

Example-2:
    Input: coins[] = [9, 6, 5, 1], sum = 19
    Output: 3
    Explanation: 19 = 9 + 9 + 1

Example-3:
    Input: coins[] = [5, 1], sum = 0
    Output: 0
    Explanation: For 0 sum, we do not need a coin

Example-4:
    Input: coins[] = [4, 6, 2], sum = 5
    Output: -1
    Explanation: Not possible to make the given sum.
    

Constraints:
    - 1 ≤ sum * coins.size() ≤ 10^6
    - 0 <= sum <= 10^4
    - 1 <= coins[i] <= 10^4
    - 1 <= coins.size() <= 10^3

*/ 


class Solution {
    private:
    int coinChange2Recursive(vector<int>& coins, int sum, int n) {
        // Base Case
        if (n == 0)
            return INF;
        else if (sum == 0)
            return 0;
        else if (n == 1)
            return (sum % coins[n-1]) == 0 ? sum/coins[n-1] : INF;
        
        // Choice Diagram
        if (coins[n-1] <= sum)
            return min(1 + coinChange2Recursive(coins, sum - coins[n-1], n), //Take
                coinChange2Recursive(coins, sum, n-1)); // Not Take
        else
            return coinChange2Recursive(coins, sum, n-1);

        return -1;
    }

    int coinChange2Memoized(vector<int>& coins, int sum, int n, vector<vector<int>>& t) {
        // Base Case
        if (n == 0)
            return INF;
        else if (sum == 0) 
            return 0;
        else if (n == 1)
            return (sum % coins[n-1]) == 0 ? sum/coins[n-1] : INF;
        
        // Cache
        if (t[n][sum] != INF)
            return t[n][sum];

        if (coins[n-1] <= sum)
            t[n][sum] = min(1 + coinChange2Memoized(coins, sum-coins[n-1], n, t), coinChange2Memoized(coins, sum, n-1, t));
        else
            t[n][sum] = coinChange2Memoized(coins, sum, n-1, t);

        return t[n][sum];
    }

    int coinChange2Tabulation(vector<int>& coins, int sum, int n, vector<vector<int>>& t) {
        // Initialisation
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) 
                    t[i][j] = INF;
                else if (j == 0)
                    t[i][j] = 0;
                else if (i == 1)
                    t[i][j] = (j % coins[i-1]) == 0 ? j/coins[i-1] : INF;
            }
        }
        
        // Coin change
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i-1] <= j) 
                    t[i][j] = min(1 + t[i][j - coins[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

    public:
    int numOfCoins(vector<int> coins, int sum) {
        int n = coins.size(), res;
        vector<vector<int>> t (n+1, vector<int> (sum+1, INF));
        
        // res = coinChange2Recursive(coins, sum, n);
        // res = coinChange2Memoized(coins, sum, n, t);
        res = coinChange2Tabulation(coins, sum, n, t);

        return (res == INF)? -1 : res;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> coins1 = {1,2,3};       int sum1 = 10;
    vector<int> coins2 = {25,10,5};     int sum2 = 30;
    vector<int> coins3 = {9,6,5,1};     int sum3 = 19;
    vector<int> coins4 = {5,1};         int sum4 = 0;
    vector<int> coins5 = {4,6,2};       int sum5 = 5;

    // Method Invocation & Result Visualization
    cout << sol.numOfCoins(coins1, sum1) << endl;
    cout << sol.numOfCoins(coins2, sum2) << endl;
    cout << sol.numOfCoins(coins3, sum3) << endl;
    cout << sol.numOfCoins(coins4, sum4) << endl;
    cout << sol.numOfCoins(coins5, sum5) << endl;

    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^n * sum) | SC: O(sum) | Recursion
    Time Complexity:  O(2^n * sum) — For each coin, at each sum, we can either include or exclude, leading to exponential combinations.
    Space Complexity: O(sum) — Due to recursion stack depth (maximum sum calls in the worst case).

# TC: O(n * sum) | SC: O(n * sum) | Memoization [Top-down]
    Time Complexity:  O(n * sum) — Each state (n, sum) is computed once.
    Space Complexity: O(n * sum) — For the memoization table, plus O(sum) recursion stack.

# TC: O(n * sum) | SC: O(n * sum) | Tabulation [Bottom-up]
    Time Complexity:  O(n * sum) — Filling a DP table of size (n+1) x (sum+1).
    Space Complexity: O(n * sum) — For the DP table.

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

