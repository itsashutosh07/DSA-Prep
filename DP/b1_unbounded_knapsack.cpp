
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: April 15, 2025
// Creation TIME: 23:52:49

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Unbounded Knapsack (Repetition of items allowed)
// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

/*
DESCRIPTION :
    Given a knapsack weight, say capacity and a set of n items with certain value vali and weight wti, The task is to fill the knapsack in such a way that we can get the maximum profit. This is different from the classical Knapsack problem, here we are allowed to use an unlimited number of instances of an item.


Example 1: 
    Input: capacity = 100, val[]  = [1, 30], wt[] = [1, 50]
    Output: 100 
    Explanation: There are many ways to fill knapsack. 
        1) 2 instances of 50 unit weight item. 
        2) 100 instances of 1 unit weight item. 
        3) 1 instance of 50 unit weight item and 50 instances of 1 unit weight items. 
        We get maximum value with option 2.  

Example 2: 
    Input: capacity = 8, val[] = [10, 40, 50, 70], wt[]  = [1, 3, 4, 5]        
    Output : 110
    Explanation: We get maximum value with one unit of weight 5 and one unit of weight 3.


Constraints:
    - 1 <= val.size() = wt.size() <= 1000
    - 1 <= capacity <= 1000
    - 1 <= val[i], wt[i] <= 100

*/ 


class Solution {
    public:
    int unboundedKnapsackRecursive(vector<int>& wt, vector<int>& val, int W, int n) {
        // Base Condition
        if (n == 0 || W == 0)
            return 0;

        // Choice diagram
        if (wt[n-1] <= W) {
            return max(val[n-1] + unboundedKnapsackRecursive(wt, val, W - wt[n-1], n), 
                unboundedKnapsackRecursive(wt, val, W, n-1));
        }
        else {
            return unboundedKnapsackRecursive(wt, val, W, n-1);
        }

        return 0;
    }

    int unboundedKnapsackMemoized(vector<int>& wt, vector<int>& val, int W, int n, vector<vector<int>>& t) {
        // Base Condition
        if (n == 0 || W == 0)
            return 0;

        if (t[n][W] != -1) return t[n][W];

        // Choice diagram
        if (wt[n-1] <= W) {
            return t[n][W] = max(val[n-1] + unboundedKnapsackMemoized(wt, val, W - wt[n-1], n, t), 
                unboundedKnapsackMemoized(wt, val, W, n-1, t));
        }
        else {
            return t[n][W] = unboundedKnapsackMemoized(wt, val, W, n-1, t);
        }

        return 0;
    }

    int unboundedKnapsackTabulation(vector<int>& wt, vector<int>& val, int W, int n, vector<vector<int>>& t) {
        // Initializsation
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0) 
                    t[i][j] = 0;
            }
        }

        // Choice Diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (wt[i-1] <= j) {
                    t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][W];
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> wt =  {36,64,29,58,37,8,68,85,60,66,59,8,15,41,40,76,32,39,45,71,39,100,60,21,29,15,28,21,56};
    vector<int> val = {34,71,6,60,54,66,48,24,51,58,83,40,78,35,78,50,36,99,50,62,8,66,89,70,57,86,76,36,27};
    int W = 66, n = wt.size();
    vector<vector<int>> t (n+1, vector<int> (W+1, -1));
    vector<vector<int>> dp (n+1, vector<int> (W+1, -1));

    vector<int> wt2 =  {3,6,2};
    vector<int> val2 = {34,71,6};
    int W2 = 650, n2 = wt2.size();
    vector<vector<int>> t2 (n2+1, vector<int> (W2+1, -1));
    vector<vector<int>> dp2 (n2+1, vector<int> (W2+1, -1));

    // Method Invocation & Result Visualization
    // cout << "Unbounded Knapsack Recursive: " << sol.unboundedKnapsackRecursive(wt, val, W, n) << endl; 
        // For your input, W = 650 and the smallest weight in wt is 8. That gives an exponent of about 650⁄8 ≈ 81. Therefore, in the worst-case, you’d have roughly 2^81 recursive calls => This roughly translates to 76 mil years to execute assuming each recursive call took 1 nanosecond.
    cout << "Unbounded Knapsack Memoized: " << sol.unboundedKnapsackMemoized(wt, val, W, n, t) << endl;
    cout << "Unbounded Knapsack Bottom-up: " << sol.unboundedKnapsackTabulation(wt, val, W, n, dp) << endl << endl;
    
    cout << "Unbounded Knapsack Recursive: " << sol.unboundedKnapsackRecursive(wt2, val2, W2, n2) << endl;
    cout << "Unbounded Knapsack Memoized: " << sol.unboundedKnapsackMemoized(wt2, val2, W2, n2, t2) << endl;
    cout << "Unbounded Knapsack Bottom-up: " << sol.unboundedKnapsackTabulation(wt2, val2, W2, n2, dp2) << endl;


    return 0;
}


/*
SOLUTIONS:-

# TC: O(2^(W/min(wt))) | SC: O(W) | Recursion
    Time Complexity:  O(2^(W/min(wt))) - Exponential — In the worst-case (when the smallest weight is 1), the recursion explores an exponential number of possibilities.
    Space Complexity: O(W) — Recursion stack depth can be proportional to the knapsack capacity.

# TC: O(n * W) | SC: O(n * W) | Memoization [Top-down]
    Time Complexity:  O(n * W) — Each state (n, W) is computed only once.
    Space Complexity: O(n * W) — For the memoization table, along with O(n) recursion stack space.

# TC: O(n * W) | SC: O(n * W) | Tabulation [Bottom-up]
    Time Complexity:  O(n * W) — Filling a DP table of size (n+1) x (W+1) using nested loops.
    Space Complexity: O(n * W) — For the DP table storage.

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

