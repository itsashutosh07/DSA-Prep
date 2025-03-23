
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
    int knapsackRecursive(vector<int>& wt, vector<int>& val, int W, int n) {

        // Base Condition
        // Think of smallest possible values of the variables we can pass
        // Mininum array's size 'n' can be 0 || min capacity of the bag 'W' can be 0, not negative
        if (n == 0 || W == 0)
            return 0;

        // Choice Diagram
        // Write in terms of choices we have to take/not-take the item
        if (wt[n-1] <= W) {// if weight of current item is less than the total capacity of the bag 'W'
            // Consider the profit which is max of either taking the current item / not taking the item.
            return max(val[n-1] + knapsackRecursive(wt, val, W - wt[n-1], n-1), // Take current item thus add its value to answer
                knapsackRecursive(wt, val, W, n-1)); // Do not take current item, skip it.
        }
        else if (wt[n-1] > W) // if weight of current item is greater than total capacity of the bag 'W'
            return knapsackRecursive(wt, val, W, n-1);  // no choice here, skip current item as its heavier than bag's capacity 'W'

        return -1;
    }

    int knapsackMemoized(vector<int>& wt, vector<int>& val, int W, int n, vector<vector<int>>& t) {

        // Base Condition
        if (n == 0 || W == 0)
            return 0;
        
        //Return from memory if already calculated
        if (t[n][W] != -1) return t[n][W];

        if (wt[n-1] <= W) 
            t[n][W] = max(val[n-1] + knapsackMemoized(wt, val, W - wt[n-1], n-1, t), knapsackMemoized(wt, val, W, n-1, t));
        else if (wt[n-1] > W) 
            t[n][W] = knapsackMemoized(wt, val, W, n-1, t);

        return t[n][W];
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> wt =  {36,64,29,58,37,8,68,85,60,66,59,8,15,41,40,76,32,39,45,71,39,100,60,21,29,15,28,21,56};
    vector<int> val = {34,71,6,60,54,66,48,24,51,58,83,40,78,35,78,50,36,99,50,62,8,66,89,70,57,86,76,36,27};
    vector<vector<int>> t (1001, vector<int> (1001, -1));
    int W = 650, n = wt.size();

    // Method Invocation 
    cout << "Ans : " << sol.knapsackMemoized(wt, val, W, n, t) << endl;

    // Time Measurement
    int trials = 5;
    double totalDuration = 0.0;

    for (int i = 0; i < trials; i++) {
        vector<vector<int>> t (1001, vector<int> (1001, -1));

        auto start = high_resolution_clock::now(); // Start the timer
        sol.knapsackMemoized(wt, val, W, n, t);
        auto end = high_resolution_clock::now();   // End the timer

        auto duration = duration_cast<microseconds>(end - start).count(); // Calculate duration in microseconds
        totalDuration += duration;
    }

    double avgDurationMicroseconds = totalDuration / trials;
    double avgDurationSeconds = avgDurationMicroseconds / 1'000'000.0; // Convert microseconds to seconds

    cout << fixed << setprecision(4);
    cout << "Average Time Taken: " << avgDurationMicroseconds << " µs (" << avgDurationSeconds << " seconds)" << endl << endl;

    return 0;
}

/*
SOLUTIONS:-

# TC: O(2^N) | SC: O(N) | Recursion
    Time Complexity: O(2^N), Where N is size of the array. As there are 2 choices for each index.
    Space Complexity:O(N), As we are using a recursion stack space of N.

# TC: O(n*m) | SC: O(1) | Memoization
    Time Complexity: O(2^N), Where N is size of the array. As there are 2 choices for each index.
    Space Complexity:O(N), As we are using a recursion stack space of N.

*/

