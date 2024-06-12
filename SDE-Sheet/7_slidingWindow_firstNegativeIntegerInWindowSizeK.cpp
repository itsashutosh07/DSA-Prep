
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 10, 2024
// Creation TIME: 16:16:48

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// GFG #First negative integer in every window of size k


/*
DESCRIPTION :
    Given an array A[] of size N and a positive integer K, 
    find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:
    Input : 
    N = 5
    A[] = {-8, 2, 3, -6, 10}
    K = 2
    Output : 
    -8 0 -6 -6

Explanation :
    First negative integer for each window of size k
    {-8, 2} = -8
    {2, 3} = 0 (does not contain a negative integer)
    {3, -6} = -6
    {-6, 10} = -6

*/ 


class Solution {
    public:
    vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
        queue<long long> negatives; // storing idx, A[idx]
        vector<long long> ans;
        long long i = 0, j = 0, windowSize;
        
        while (j < N) {
            if (A[j] < 0) negatives.push(j);
            
            windowSize = j - i + 1; 
            
            if (windowSize < K) {
                j++;
            }
            else if (windowSize == K) {
                if (!negatives.empty() && negatives.front() >= i) 
                    ans.push_back(A[negatives.front()]);
                else
                    ans.push_back(0);
                
                i++; j++;
                if (!negatives.empty() && negatives.front() < i) negatives.pop();
            }
        }
        return ans;
    }

    vector<long long> printLastNegativeInteger(long long int A[], long long int N, long long int K) {
        stack<long long> negatives; // storing idx, A[idx]
        vector<long long> ans;
        long long i = 0, j = 0, windowSize;
        
        while (j < N) {
            if (A[j] < 0) negatives.push(j);
            
            windowSize = j - i + 1; 
            
            if (windowSize < K) {
                j++;
            }
            else if (windowSize == K) {
                if (!negatives.empty() && negatives.top() >= i) 
                    ans.push_back(A[negatives.top()]);
                else
                    ans.push_back(0);
                
                i++; j++;
                if (!negatives.empty() && negatives.top() < i) negatives.pop();
            }
        }
        return ans;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    long long int A[8] = {12, -1, -7, 8, -15, 30, 16, 28};

    // Method Invocation & Result Visualization
    printVector(sol.printFirstNegativeInteger(A, 8, 3));
    printVector(sol.printLastNegativeInteger(A, 8, 3));


    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^3) TC | Brute Force
traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

