
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 01:16:27

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #48. Rotate Image

/*
DESCRIPTION :




Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]
*/ 


class Solution {
    public:
    vector<vector<int>> rotate1(vector<vector<int>> & matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // formula ovtained through observation of indices before and after the rotation
                // i -> j
                // j -> n - 1 - i
                rotated[j][n - i - 1] = matrix[i][j]; 
            }
        }
        return rotated;
    }

    void rotate2(vector < vector < int >> & matrix) {
        int n = matrix.size();
        //transposing the matrix
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void rotate3(vector<vector<int>>& matrix) {
        int n = matrix.size(), left = 0, right = n-1, top = 0, bottom = n-1;

        while (left < right) {
            for (int i = 0; i < (right-left); i++) {
                int temp = matrix[top][left+i];
                
                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = temp;
            }
            top++; bottom--;
            left++; right--;
        }
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    // Method Invocation
    sol.rotate1(matrix1);
    sol.rotate1(matrix2);

    // Result Visualization
    printMatrix(matrix1);
    printMatrix(matrix2);


    return 0;
}

/*
SOLUTIONS:-

1. O(n^2) Space & O(n^2) TC | Brute Force || Strivers https://www.youtube.com/watch?v=Z0R2u6gd3GU
    - Take another dummy matrix of n*n,
        - first row of the matrix and put it in the last column of the dummy matrix, 
        - take the second row of the matrix, and put it in the second last column of the matrix and so.
    - formula obtained through observation of indices before and after the rotation
        i -> j
        j -> n - 1 - i
    - rotated[j][n - i - 1] = matrix[i][j]; 
    - return rotated[][]

2. O(1) Space & O(n^2) TC | Optimized  || Strivers https://www.youtube.com/watch?v=Z0R2u6gd3GU
    - By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, 
    - so that’s why we transpose the matrix 
    - and then reverse each row

    - Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
    - Step 2: Reverse each row of the matrix
    
    - and since we are making changes in the matrix itself space complexity gets reduced to O(1).

3.  O(1) extra space & O(n^2) TC | OPTIMIZED || NeetCode https://www.youtube.com/watch?v=fMSJSS7eO1w
    - start by changing the corner points of the matrix to the rotated corner positions
        - instead starting from clockwise assigning variables, use anti-clockwise assigning of indices to reduce the no of variables required to rotate corner points
        - this would look something like:
            int temp = matrix[top][left+i];

            matrix[top][left] = matrix[bottom][left];
            matrix[bottom][left] = matrix[bottom][right];
            matrix[bottom][right] = matrix[top][right];
            matrix[top][right] = temp;
    - after rotation of corner points, rotate the points adjecent to corner points in the last row too
        - this is done by keeping a for loop from i: 0->(right-left)-1 in the above rotation equations and hence completeing the entire outer rows & collumns
    - once corner rows and collumns are completed with rotation, move inwards till left > right && top > bottom

*/

