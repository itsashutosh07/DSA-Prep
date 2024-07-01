
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 30, 2024
// Creation TIME: 21:36:58

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #74. Search a 2D Matrix

/*
DESCRIPTION :
    You are given an m x n integer matrix matrix with the following two properties:
        - Each row is sorted in non-decreasing order.
        - The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.
 

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -10^4 <= matrix[i][j], target <= 10^4

*/ 


class Solution {
    public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        // BruteForce TC: O(n*m) + Optimized TC: O(m+n)
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][matrix[0].size()-1] < target)
                continue;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        // OPTIMIZED TC: O(log(m*n))
        int row = matrix.size(), col = matrix[0].size();
        int low = 0, high = (row*col) - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            int mid_row = mid/col, mid_col = mid%col;
            int middle = matrix[mid_row][mid_col];

            if (middle == target) {
                return true;
            }
            else if (middle > target) {
                high = mid-1;
            } 
            else {
                low = mid+1;
            }
        }
        return false;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};


    // Method Invocation & Result Visualization
    cout << sol.searchMatrix1(matrix2, 3) << endl;
    cout << sol.searchMatrix2(matrix1, 6) << endl;
    cout << sol.searchMatrix2(matrix2, 13) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    - Linear search
    - Use nested for loops to perform a Linear Search in matrix for finding the target element.

2. TC: O(m+n) | SC: O(1) | Optimized
    - Smart linear search
    - Use nested for loop but utilize the property of matrix stating that 
        - "first integer of each row is greater than the last integer of the previous row"
    - Using this, before entering inner loop, check if the target is smaller that the last element in current row.
        - if not then simply skip the row.

3. TC: O(log(m*n)) | SC: O(1) | OPTIMIZED
    - Flatten 2D Matrix
    - Instead of thinking this as 2D matrix, the constraints allow us to think this matrix as a 1D array.
    - Apply binary search in the flattend 1D array to locate target.
    - initialize, low = 0 & high = (row * col) - 1
    - in each iteration calculate low, high & mid by keeping the flattend 1D array in mind.
        - but after update flattened_mid and split it into mid_row & mid_col using the below foemula:
            - mid_row = flattened_mid / col;
            - mid_col = flattened_mid % col;
    - compare element at mid with target. if found then return, else update low, mid & high appropriately.

*/

