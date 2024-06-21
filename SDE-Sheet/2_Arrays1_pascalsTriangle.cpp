
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 06, 2024
// Creation TIME: 10:39:56

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #118. Pascal's Triangle

/*
DESCRIPTION :
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
    Input: numRows = 1
    Output: [[1]]
 

Constraints:
    1 <= numRows <= 30

*/ 


class Solution {
    public:
    vector<vector<int>> generate1(int numRows) {
        // create structure of pascal triangle using 1s everywhere
        vector<vector<int>> pascal;
        for (int i = 1; i <= numRows; i++) {
            pascal.push_back({});
            for (int j = 1; j <= i; j ++) {
                pascal[i-1].push_back(1);
            }
        }

        // increment current value by previous two values of last row & col
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        
        return pascal;
    }

    vector<int> generateRow(int row) {
        // each element of a row in pascal triangle represents an intermediate result of our optimized nCr formula.
        // at row=4:    1    1*(4-1)    3*(4-2)     3*(4-3)
        //                   -------    -------     -------     ===>    [ 1   3   3   1 ]
        //                      1          2           3
        vector<int> temp;
        temp.push_back(1);
        int t = 1;
        for (int i = 1; i < row; i++) {
            t = t * (row - i);
            t = t / i;
            temp.push_back(t);
        }
        return temp;
    }
    vector<vector<int>> generate2(int numRows) {
        // 1
        // 1 1
        // 1 2 1
        // 1 3 3 1
        // 1 4 6 4 1

        // TC : O(n^2)
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            res.push_back(generateRow(i+1));
        }

        return res;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization & Method Invocation
    vector<vector<int>> ans1 = sol.generate1(2);
    vector<vector<int>> ans2 = sol.generate1(7);
    vector<vector<int>> ans3 = sol.generate2(5);

    // Result Visualization
    printFormattedMatrix(ans1, " ", " ", "\t", "\n");
    printFormattedMatrix(ans2, " ", " ", "\t", "\n");
    printFormattedMatrix(ans3, " ", " ", "\t", "\n");


    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

