
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: March 23, 2025
// Creation TIME: 13:44:59

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// #0-1 Knapsack [Recursive]

/*
DESCRIPTION :
    Given two integer arrays, val and wt, each of size N, which represent the values and weights of N items respectively, and an integer W representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W.

    Each item can either be picked in its entirety or not picked at all (0-1 property). The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.


Example 1:
    Input: val = [60, 100, 120], wt = [10, 20, 30], W = 50
    Output: 220
    Explanation: Select items with weights 20 and 30 for a total value of 100 + 120 = 220.

Example 2:
    Input: val = [10, 40, 30, 50], wt = [5, 4, 6, 3], W = 10
    Output: 90
    Explanation: Select items with weights 4 and 3 for a total value of 40 + 50 = 90.


Constraints:
    - 1 ≤ N ≤ 500
    - 1 ≤ W ≤ 1000
    - 1 ≤ wt[i] ≤ 500
    - 1 ≤ val[i] ≤ 500

*/ 


class Solution {
    public:
    int knapsack(vector<int> wt, vector<int> val, int W, int n) {
        // Base Condition
        // Think of smallest possible values of the variables we can pass
        // Mininum array's size 'n' can be 0 || min capacity of the bag 'W' can be 0, not negative
        if (n == 0 || W == 0)
            return 0;

        // Choice Diagram
        // Write in terms of choices we have to take/not-take the item
        if (wt[n-1] <= W) {// if weight of current item is less than the total capacity of the bag 'W'
            // Consider the profit which is max of either taking the current item / not taking the item.
            return max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), // Take current item thus add its value to answer
                knapsack(wt, val, W, n-1)); // Do not take current item, skip it.
        }
        else if (wt[n-1] > W) // if weight of current item is greater than total capacity of the bag 'W'
            return knapsack(wt, val, W, n-1);  // no choice here, skip current item as its heavier than bag's capacity 'W'

        return -1;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> wt =  {1, 2, 3, 8, 7, 4};
    vector<int> val = {20, 5, 10, 40, 15, 25};
    int W = 10;

    // Method Invocation & Result Visualization
    cout << sol.knapsack(wt, val, W, wt.size()) << endl;

    return 0;
}

/*
SOLUTIONS:-

# TC: O(n*m) | SC: O(1) | Recursion
    Time Complexity: O(2^N), Where N is size of the array. As there are 2 choices for each index.
    Space Complexity:O(N), As we are using a recursion stack space of N.

*/

