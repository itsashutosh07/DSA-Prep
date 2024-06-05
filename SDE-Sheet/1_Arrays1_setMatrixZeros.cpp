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
    static void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros;
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    zeros.push_back({row, col});
                }
            }
        }
        
        for (int i = 0; i < zeros.size(); i++) {
            for (int row = 0; row < matrix.size(); row++) {
                for (int col = 0; col < matrix[0].size(); col++) {
                    if (row == zeros[i].first || col == zeros[i].second) {
                        matrix[row][col] = 0;
                    }
                }
            }
        }
    }
};


int main() 
{
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution::setZeroes(matrix1);
    Solution::setZeroes(matrix2);

    printMatrix(matrix1);
    printMatrix(matrix2);

    return 0;
}

/*
Solution Explaination Here:

Solutions:-

1. O(1) Space & O(n^3) TC: 
traverse each element of matrix and for each element, 
    a. if element == 0, convert each corresponding element in that row & column from 1 -> -1 (exclude converting 0 -> -1).
    b. reiterate entire matrix  and now convert those -1 -> 0.

2. O(n+m) Space & O(n^2) TC: 
have a zeroRow and zeroCol arrays of size n & m. Populate zeroRow[i] and zeroCol[j] of these arrays if matrix[i][j] == 0.  Set elements of orignal matrix as zero according to the two arrays.

3. O(1) extra space & 2O(n^2) TC:
Inplace store row/col to be set as zero by marking 0 in 0th row and 0th col.
    Keep extra variable for the overlapping matrix[0][0] element as Col0 and mark it initaially as 1.
    mark all inplace the zeros in 0th col and 0th row.
    traverse and mark row0 as zeros if matrix[0][0] == 0
    traverse and mark col0 as zeros if Col0 == 0.
    {row0 needs to be traversed 1st since if matrix[0][0] is changed 1st by use of Col0 then matrix[0][0]'s changed value will affect row0}

*/

