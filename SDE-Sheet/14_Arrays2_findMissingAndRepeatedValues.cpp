
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2024
// Creation TIME: 21:15:38

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #2965. Find Missing and Repeated Values

/*
DESCRIPTION :
    You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

    Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.


Example 1:
    Input: grid = [[1,3],[2,2]]
    Output: [2,4]
    Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
Example 2:
    Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
    Output: [9,5]
    Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 

Constraints:

    - 2 <= n == grid.length == grid[i].length <= 50
    - 1 <= grid[i][j] <= n * n
    - For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
    - For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
    - For all x that 1 <= x <= n * n except two of them there is exatly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.

*/ 


class Solution {
    public:
    vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
        int n = grid.size(); // size of the array
        int repeating = -1, missing = -1;

        //Find the repeating and missing number
        for (int i = 1; i <= n*n; i++) {
            //Count the occurrences
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (grid[j][k] == i) cnt++;
                }
            }

            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            if (repeating != -1 && missing != -1)
                break;
        }
        return {repeating, missing};
    }

    vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
        vector<int> ans (2,0);

        long long s1=0, sn1=0, s2=0, sn2=0, n = grid.size(), nsq = grid.size() * grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s1 += grid[i][j];
                s2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }
        sn1 = (nsq * (nsq+1)) / 2;
        sn2 = (nsq * (nsq+1) * ((2*nsq) + 1)) / 6;

        long long val1 = s1 - sn1; //  x - y
        long long val2 = s2 - sn2; //x^2 - y^2

        long long val3 = val2/val1; //x + y

        long long duplicate, missing;

        duplicate = (val1 + val3) / 2;
        missing = (duplicate - val1);

        return {(int) duplicate, (int)missing};
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<vector<int>> grid1 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<vector<int>> grid2 = {{1, 3}, {2, 2}};

    // Method Invocation & Result Visualization
    printVector(sol.findMissingAndRepeatedValues2(grid1));
    printVector(sol.findMissingAndRepeatedValues2(grid2));

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^2) TC | Brute Force | n is the number of elements 1-to-n^2
    - initialise duplicate & missing as -1 => donotes that it has not been found till now
    -  for each num in range 1->n, check the occurance of it in the grid :
        - if occurance = 2 -> duplicate
        - if occurance = 0 -> missing
    - if both found break and return {duplicate, missing}


2. O(1) Space & O(n) TC | Optimized
    - Sn  = sum of all nums in the array
    - S2  = sum of squares of all nums in the array
    - Sn  = sum of 1st n positive integers = (N*(N+1))/2
    - Sn2 = sum of squares of 1st n positive integers = (N*(N+1)*(2N+1))/6

    - sn - s = x-y
    - sn2 - s2 = (x-y)(x+y)

    - 2 equations & 2 unknowns, use algebra to get values of each x & y
*/

