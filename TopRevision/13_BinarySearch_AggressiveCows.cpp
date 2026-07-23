
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 13, 2026
// Creation TIME: 18:58:18

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
private: 
    int cowsPlaceable(vector<int>& stallPos, long long allowedCowSeperation) {
        long long cowsPlaced = 1, lastPlacedCow = stallPos[0];

        for (int i = 1; i < stallPos.size(); i++) {
            long long currStallPos = stallPos[i];
            long long currCowSeperation = currStallPos - lastPlacedCow;

            if (currCowSeperation >= allowedCowSeperation) {
                cowsPlaced++;
                lastPlacedCow = stallPos[i];
            }
        }

        return cowsPlaced;
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        // Start Time : 6:11 PM
        // End Time : 6:45 PM

        sort(nums.begin(), nums.end());
        
        long long n = nums.size(), minStallPos = nums[0], maxStallPos = nums[n-1];

        long long minStallDist = 1, maxStallDist = maxStallPos - minStallPos;

        long long l = minStallDist, h = maxStallDist;

        while (l <= h) {
            long long m = l + ((h - l) / 2);

            long long cowsPlaced = cowsPlaceable(nums, m);
            if (cowsPlaced >= k) {
                // dist is too small -> increase dist
                l = m + 1;
            }
            else {
                // dist is too big -> decrease dist
                h = m - 1;
            }
        }
        // returning 'h' since, 'h' moves to a polarity of possible side
        // initially 'l' was at possible-polarity end and 'h' was at impossible-polarity end
        // iterations end when they cross and move to opposite ends, hence now 'h' points to possible polarity
        return h;
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

