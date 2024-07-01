
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 30, 2024
// Creation TIME: 22:23:00

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #Question_Title

/*
DESCRIPTION :

    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000

Example 2:
    Input: x = 2.10000, n = 3
    Output: 9.26100

Example 3:
    Input: x = 2.00000, n = -2
    Output: 0.25000

Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:
    - -100.0 < x < 100.0
    - -2^31 <= n <= 2^31-1
    - n is an integer.
    - Either x is not zero or n > 0.
    - -10^4 <= x^n <= 10^4

*/ 


class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long nAbs = n;
        nAbs = abs(n);

        while (nAbs > 0) {
            if (nAbs & 1) { // Checks if n is odd
                result *= x;
                nAbs--;
            }
            else { // if n is even
                x = x * x; // x^(2n) = x^(n+n) = (x^2)^n
                nAbs >>= 1;
            }
        }

        return (n < 0)? (double)(1.0) / (double)(result) : result;
    }

};


int main() 
{
    Solution sol;

    // Input Initialization, Method Invocation & Result Visualization
    cout << sol.myPow(2, 10) << endl;
    cout << sol.myPow(2, -10) << endl;
    cout << sol.myPow(-69, 108) << endl;
    cout << sol.myPow(-3.14, 314) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n) | SC: O(1) | Brute Force
    - Looping from 1 to n and keeping a ans(double) variable. Now every time your loop runs, multiply x with ans. - At last, we will return the ans.
    - Now if n is negative we must check if n is negative, if it is negative divide 1 by the ans.

2.  TC: O(log(n)) | SC: O(1) | OPTIMIZED
    - Using Binary Exponentiation
    - Initialize ans = 1.0 & store an *absolute copy of n in another varible n_abs.
    - now while n_abs is greater than 0 start iterating and multiply x with itself till n_abs is valid.
    - there will be 2 cases:
        - if n_abs is odd:
            - multiply result with x once & decrement n_abs by one
            - this makes n_abs even now!
        - else n_abs is even => (n_abs = 2a):
            - multiply result with x * x and decrement n_abs by half. || x^(2n) = x^(n+n) = (x^2)^n
    - using this approach we steadily half our iterations each time.
    - at last, we check if n was orignally -ve, if yes the result should be 1/ans else return ans.

*/

