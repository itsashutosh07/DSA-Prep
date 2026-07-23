
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2026
// Creation TIME: 15:52:21

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
    int findPeakElement(vector<int> &arr) {
        // Since both sides of the array is -INF, 
        // it is guarenteed that there is 1 or more peek element(s)
        int n = arr.size();

        // Edge cases : 
            // if array has only 1 element -> it is the peek element since both sides is -INF
            // OR if array has the 1st element greater than the 2nd element -> its peek element
        if (n == 1 || arr[0] > arr[1])
            return 0; // handles strictly decreasing graph

        // If array's last element is greater than the 2nd last element
        // -> it is the peek element since right of it is already -INF
        if (arr[n-1] > arr[n-2])
            return n-1; // handles strictly increasing graph

        // Apply binary search to find the peek elemnt on the array now 
        // since it is guarenteed as the graph is neither increasing nor decreasing
        // -> graph has a peek
        

        // Shrink the search space as the left most and the right most case is not the peek and also it is guarenteed that the rest of the array has a peek for sure
        int l = 1, h = n-2;

        while (l <= h) {
            int m = l + ((h - l) / 2);
            // cout << "m : " << m << endl;

            if (arr[m] > arr[m+1] && arr[m] > arr[m-1]) {
                // cout << "found peek : " << m << endl;
                return m; // peek element
            }

            if (arr[m] >= arr[m-1] && arr[m] <= arr[m+1]) {
                l = m+1;
            }
            else {
                h = m-1;
            }
        }

        return -1;
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

