
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

// LEETCODE #Question_Title

/*
DESCRIPTION :



*/ 


class Solution {
    public:
    int knapsack(vector<int> wt, vector<int> val, int W, int n) {
        // Base Condition
        if (n == 0 || W == 0)
            return 0;

        // Choice Diagram
        if (wt[n-1] <= W) 
            return max (val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
        else if (wt[n-1] > W) 
            return knapsack(wt, val, W, n-1);

        return -1;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> wt =  {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7, n = 4;


    // Method Invocation
    cout << sol.knapsack(wt, val, W, n) << endl;



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

