
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2026
// Creation TIME: 14:20:09

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Striver's 79 #Find row with maximum 1's


/*
DESCRIPTION :
    Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
    If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.


Example 1:
    Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
    Output: 0
    Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
    Input: mat = [ [0, 0], [0, 0] ]
    Output: -1
    Explanation: The matrix does not contain any 1. So, -1 is the answer.


Constraints
    - n == mat.length 
    - m == mat[i].length 
    - 1 <= n, m <= 100 
    - mat[i][j] is either 0 or 1.
*/ 


class Solution {
    private:
    int binarySearch1stOne(vector<int>& row) {
        int l = 0, h = row.size()-1;
        while (l <= h) {
            int mid = l + ((h - l) / 2);
            if (row[mid] == 0) {
                // discard left half
                l = mid + 1;
            }
            else {
                // discard right half
                h = mid - 1;
            }
        }
        return l;
    }
    public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
        int m = mat.size(), n = mat[0].size(), maxOneRowIdx = -1, maxOnesInRow = INT_MIN;
        
        for (int i = 0; i < m; i++) {
            // if 1st element of row is 1 -> all are ones
            int currOnesInRow = 0;
            if (mat[i][0] == 1) {
                return i;
            }
            // if last element of the row is 0 -> all are 0s
            if (mat[i][n-1] == 0) {
                continue;
            }
            
            int idxOf1stOne = binarySearch1stOne(mat[i]);
            currOnesInRow = n - idxOf1stOne + 1;

            if (currOnesInRow > maxOnesInRow) {
                maxOnesInRow = currOnesInRow;
                maxOneRowIdx = i;
            }
        }
        return maxOneRowIdx;
    }
};

int main() 
{
    Solution sol;

    // Input Initialization


    // Method Invocation
    cout << sol.method_name(param1) << endl;



    // Result Visualization



    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n*m) | SC: O(1) | Brute Force
    # Linear search

2. TC: O(m+n) | SC: O(1) | Better


3.  TC: O(log(m*n)) | SC: O(1) | OPTIMIZED


*/

