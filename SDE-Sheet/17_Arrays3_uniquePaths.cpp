
#include <bits/stdc++.h>
#include "dgb.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

struct ListNode;
struct TreeNode;

// Creation DATE: June 17, 2024
// Creation TIME: 23:11:14

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #62. Unique Paths

/*
DESCRIPTION :
    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.


Example 1:
    Input: m = 3, n = 7
    Output: 28

Example 2:
    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
        1. Right -> Down -> Down
        2. Down -> Down -> Right
        3. Down -> Right -> Down
 

Constraints:
    1 <= m, n <= 100

*/ 


class Solution {
    public:
    int solve(int m, int n, int i, int j) {
        if ((i >= m && j < n) || (i < m && j >= n)) return 0;
        if (i == m-1 && j == n-1) return 1;
        int l = solve(m, n, i+1, j);
        int r = solve(m, n, i, j+1);
        return l+r;
    }
    int uniquePaths1(int m, int n) {
        return solve(m, n, 0, 0);
    }
    int uniquePaths2(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) 
            dp[i][n-1] = 1;
        for (int j = 0; j < n; j++) 
            dp[m-1][j] = 1;
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
        // return solve(m, n, 0, 0);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    int m = 23, n = 12;

    // Method Invocation & Result Visualization
    auto start1 = high_resolution_clock::now(); // Start the timer
    cout << sol.uniquePaths1(m, n) << endl;
    auto end1 = high_resolution_clock::now();   // End the timer
    auto duration1 = duration_cast<microseconds>(end1 - start1).count(); // Calculate duration in microseconds
    double avgDurationSeconds1 = duration1 / 1'000'000.0; // Convert microseconds to seconds
    cout << fixed << setprecision(4);
    cout << "Average Time Taken: " << duration1 << " µs (" << avgDurationSeconds1 << " seconds)" << endl << endl;

    auto start2 = high_resolution_clock::now(); // Start the timer
    cout << sol.uniquePaths2(m, n) << endl;
    auto end2 = high_resolution_clock::now();   // End the timer
    auto duration2 = duration_cast<microseconds>(end2 - start2).count(); // Calculate duration in microseconds
    double avgDurationSeconds2 = duration2 /1'000'000.0; // Convert microseconds to seconds
    cout << "Average Time Taken: " << duration2 << " µs (" << avgDurationSeconds2 << " seconds)" << endl << endl;


    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

