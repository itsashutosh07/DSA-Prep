
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

// Creation DATE: March 30, 2025
// Creation TIME: 16:39:52

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// # Count of Subsets with given Difference
// https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/

/*
DESCRIPTION :

    Given an array arr[] of size N and a given difference diff, the task is to count the number of partitions that we can perform such that the difference between the sum of the two subsets is equal to the given difference.

    Note: A partition in the array means dividing an array into two parts say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only of the subsets.

Examples:
        Input: N = 4, arr[] = [5, 2, 6, 4], diff = 3
        Output: 1
        Explanation: We can only have a single partition which is shown below:
        {5, 2} and {6, 4} such that S1 = 7 and S2 = 10 and thus the difference is 3


    Input: N = 5, arr[] = [1, 2, 3, 1, 2], diff = 1
    Output: 5
    Explanation: We can have five partitions which is shown below
    {1, 3, 1} and {2, 2} – S1 = 5, S2 = 4
    {1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
    {3, 2} and {1, 1, 2} – S1 = 5, S2 = 4
    {1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
    {3, 2} and {1, 1, 2} – S1 = 5, S2 = 4

*/ 


class Solution {
    public:
    PASTE_METHOD_DECLARATION_HERE

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> param1 = {1,2,3};

    // Method Invocation & Result Visualization
    cout << sol.method_name(param1) << endl;



    return 0;
}


/*
SOLUTIONS:-

# TC: O() | SC: O() | Recursion
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Memoization [Top-down]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Tabulation [Bottom-up]
    Time Complexity:  O()
    Space Complexity: O()

# TC: O() | SC: O() | Space-Optimized
    Time Complexity:  O()
    Space Complexity: O()

*/

