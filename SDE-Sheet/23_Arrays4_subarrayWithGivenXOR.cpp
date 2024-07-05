
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: July 05, 2024
// Creation TIME: 02:01:13

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// InterviewBit #Subarray with given XOR

/*
DESCRIPTION :
    Given an array of integers A and an integer B.

    Find the total number of subarrays having bitwise XOR of all elements equals to B.


Problem Constraints :
    - 1 <= length of the array <= 10^5
    - 1 <= A[i], B <= 10^9


Example 1:
    Input:
        A = [4, 2, 2, 6, 4]
        B = 6
    Output : 4
    Explanation:
        The subarrays having XOR of their elements as 6 are:
        [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Example 2:
    Input 2:
        A = [5, 6, 7, 8, 9]
        B = 5
    Output : 2
    Explanation:
        The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

*/ 


class Solution {
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int, int> seen; // [xor : count]
    int curr = 0, n = A.size(), res = 0;
    
    for (int i = 0; i < n; i++) {
        curr ^= A[i];
        if (curr == B) res += 1;
        int req = B ^ curr;
        if (seen.find(req) != seen.end()) {
            res += seen[req];
        }
        seen[curr]++;
    }
    return res;
    
}


};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> arr1 = {4, 2, 2, 6, 4};
    vector<int> arr2 = {5, 6, 7, 8, 9};

    // Method Invocation & Result Visualization
    cout << sol.solve(arr1, 6) << endl;
    cout << sol.solve(arr2, 5) << endl;


    return 0;
}

/*
SOLUTIONS:-

1. TC: O(n^2) | SC: O(1) | Brute Force
    # Use nested for loops and increase cnt if running xor in inner loop reaches k
    - initialize cnt = 0 to keep track of no. of subarrays found with xor as k
    - Run a for loop from i : [0->n-1] and inner for loop from j : [i->n-1]
    - before starting inner for loop initialize curr_xor = 0 as running xor at each element in inner loop
    - inside inner loop, update curr_xor with element at index j
    - increase cnt if curr_xor if found to be k
    - return cnt after both loops are exhausted

2. TC: O(n) | SC: O(n) | OPTIMIZED
    # hash map to store running XORs [prefixXor : count] and increase 'result' by count of previously encountered required xor
    - initialize unordered_map[xor : cnt] for remembering the xor encountered so far & the no. of times it was seen
    - iterate over the array using for loop
    - calculate required xor for each iteration by required_xor = curr_xor ^ k
            *  *  *  *  *  *  *  *  *  *
            <-----curr_xor--->i
            <---x-->|<---k--->i             => k = target_xor => x = required_xor
        -  x ^ k      = curr_xor
        - (x ^ k) ^ k = curr_xor ^ k        => xor by k on both sides
        -           x = curr_xor ^ k        => k xor k is zero => x xor 0 is x

    - if curr_xor itself becomes k then simply increment the result by 1
    - check if required_xor was also encountered previously in the map
        - if required_xor was seen previously some 'n' times then increment the result by 'n'
    - increment the curr_xor's count in the map by 1
    - return result

*/

