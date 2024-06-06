#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 05, 2024
// Creation TIME: 20:55:42

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #73. Set Matrix Zeroes
/*
DESCRIPTION :
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    You must do it in place.

Example 1:
    Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
    Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/ 

class Solution {
    public:
    void markRowZero(vector<vector<int>>& matrix, int i) {
        for (int col = 0; col < matrix[0].size(); col++) {
            if (matrix[i][col] != 0)
                matrix[i][col] = -1;
        }

    } 
    void markColZero(vector<vector<int>>& matrix, int j) {
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][j] != 0)
                matrix[row][j] = -1;
        }
    } 
    void setZeroes1(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    markRowZero(matrix, i);
                    markColZero(matrix, j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }

    }

    void setZeroes2(vector<vector<int>>& matrix) {
        // 2. traverse matrix and if matrix[i][j] == 0 then mark row[i] & col[j]
        // traverse again and check if row[i] || col[j] has marked element then set matrix[i][j] = 0;
        // TC : O(2* m*n) | SC : O(m+n)

        vector<int> row (matrix.size(), 0);
        vector<int> col (matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row[i]  == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroes3(vector<vector<int>>& matrix) {
        // 3. traverse matrix and 
        // if matrix[i][j] == 0 then mark 
        // row[i] -> matrix[..][0] & 
        // col[j] -> matrix[0][..]
        // traverse once again for i,j >= 1 and check if matrix[..][0] || matrix[0][..] has marked element(0) 
        // then set matrix[i][j] = 0;
            // Again 1st traverse 0th row and mark each element 0 if matrix[0][0] has 0
            // Again next traverse 0th col and mark each element 0 if col0 has 0
        // TC : O(2n) | SC : O(1)

        int col0 = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // row[i] = 1
                    if (j != 0)
                        matrix[0][j] = 0; // col[j] = 1
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) { // (row[i] || col[j]) == 1
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        if (col0 == 0) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> matrix1 = {{0,1,2,8},{3,4,5,2},{0,1,2,9},{3,4,5,2},{0,1,2,9}};
    vector<vector<int>> matrix2 = {{0,1,2,8},{3,4,5,2},{0,1,2,9},{3,4,5,2},{0,1,2,9}};
    vector<vector<int>> matrix3 = {{0,1,2,8},{3,4,5,2},{0,1,2,9},{3,4,5,2},{0,1,2,9}};

    // Method Invocation
    sol.setZeroes1(matrix1);
    sol.setZeroes2(matrix2);
    sol.setZeroes3(matrix3);

    // Result Visualization
    printMatrix(matrix1);
    printMatrix(matrix2);
    printMatrix(matrix3);

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC: Brute Force
traverse each element of matrix and for each element, 
    a. if element == 0, convert each corresponding element in that row & column from 1 -> -1 (exclude converting 0 -> -1).
    b. reiterate entire matrix  and now convert those -1 -> 0.

2. O(n+m) Space & O(n^2) TC: Optimized
have a zeroRow and zeroCol arrays of size n & m. Populate zeroRow[i] and zeroCol[j] of these arrays if matrix[i][j] == 0.  Set elements of orignal matrix as zero according to the two arrays.

3. O(1) extra space & O(n^2) TC: OPTIMIZED
Inplace store row/col to be set as zero by marking 0 in 0th row and 0th col.
    Keep extra variable for the overlapping matrix[0][0] element as Col0 and mark it initaially as 1.
    mark all inplace the zeros in 0th col and 0th row.
    traverse and mark row0 as zeros if matrix[0][0] == 0
    traverse and mark col0 as zeros if Col0 == 0.
    {row0 needs to be traversed 1st since if matrix[0][0] is changed 1st by use of Col0 then matrix[0][0]'s changed value will affect row0}

*/

