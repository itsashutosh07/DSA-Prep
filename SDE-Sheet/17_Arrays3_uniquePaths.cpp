
#include <bits/stdc++.h>
#include "../dgb.hpp"
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
    There is a robot on an (m x n) grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

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
        if (i == m-1 && j == n-1) return 1; // reached end of the grid
        if ((i >= m) || (j >= n)) return 0; // index out of bounds
        int moveDown = solve(m, n, i+1, j);
        int moveRight = solve(m, n, i, j+1);
        return moveDown + moveRight;
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
    }

    int uniquePaths3(int m, int n) {
        // Permutation n Combination
        // for m = 2 & n = 3
        // D R R        R = Right & D = Down
        // R D R
        // R R D
        // total R = (col-1) & total D = (row-1) 
        // ==>> N in NcR is = totalR + totalD = row + col - 2
        // Total Combinations = _ _ _ = NcR = 3c1 = 3c2
        long long res = 1, N = m+n-2, R = min(m-1, n-1);
        for (int i = 0; i < R; i++) {
            res = res * (N - i) / (i+1);
        }
        return res;
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

    auto start3 = high_resolution_clock::now(); // Start the timer
    cout << sol.uniquePaths3(m, n) << endl;
    auto end3 = high_resolution_clock::now();   // End the timer
    auto duration3 = duration_cast<microseconds>(end3 - start3).count(); // Calculate duration in microseconds
    double avgDurationSeconds3 = duration3 /1'000'000.0; // Convert microseconds to seconds
    cout << "Average Time Taken: " << duration3 << " µs (" << avgDurationSeconds3 << " seconds)" << endl << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: Exponential | SC: Exponential | Brute Force
    # Recursion
    - take i & j variables to iterate over the matrix
    - Base cases:
        - if index out of bounds then return 0 as no valid path possible
        - if i & j reach the end point index then return 1, denoting 1 valid path.
    - total no of ways from any given point in matrix would be summation of
        -  the no. of ways to move right  + no. of ways to move down.

2. TC: O(m*n) | SC: O(m*n) | Better
    # Dynamic Programming / Tabulation 
    - make matrix of the same size as the given matrix i.e. [row X col]
    - each element of the 'dp' matrix denotes the no of ways to reach that coordinate in matrix.
    - Base case:
        - if last-row(m-1) or last-col(n-1) is encountered there would be only 1 way to reach the destination
            - i.e. by travelling along the last-row/last-col's boundary.
    - iterate backwards from destination to 0,0 => i,j: (m-2,n-2) -> (0,0)
    - In each element sum up the following 2 values:
        - element present directly below the curr element, denoting the no. of ways to travel downwards from curr corrdinate.
        - & similarly the element present directly at the col to right of current coordinate.
    - return value at element at 0,0

3.  TC: O(n-1) or  O(m-1) | SC: O(1) | OPTIMIZED
    # Combinatorix Solution
    - Let no. of rows be m, no. of cols be n
    - Write down all possible paths that could be taken to reach destination for small exampleas and we nowill notice some similarities. 
    1. Each time we are taking an exactly ((rows-1)+(cols-1))=>(rows+cols-2) number of steps to reach the end.
        - From start to reach the end we need a certain number of rightward directions and downward directions. 
        - Thus we need to travel (cols-1) times rightward 
        - & (rows-1) no. of in times downward direction to reach the endpoint.
        - In total, (rows+cols-2) number of total step are required to reach the end.
    2. Hence the total no of ways to reach desination would be
        - the ways to choose m rows out of m+n-2 total steps
        - or choose n cols out of m+n-2 total steps
    - Formally, (rows+cols-2)C(cols-1) or (rows+cols-2)C(rows-1)} to get the total # of paths.
    - mathematically, nCr = (n!)/(r! * (n-r)!) => or simply, nCr = n * n-1 * n-2...(r-1) / 1*2*3...(r)

*/

