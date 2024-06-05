// https : // www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186

/************************************************************************************************************************

Problem Statement
    You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

Note:
    1. The length of each array is greater than zero.
    2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.
    3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.

Input Format:
    The first line of the input contains an integer T, denoting the number of test cases.
    The first line of each test case contains two space-separated integers 'N' and 'M', denoting the size of the two arrays.
    The second line of each test case contains 'N' space-separated integers denoting the elements of the first array.
    The third line of each test case contains 'M' space-separated integers denoting the elements of the second array.
Output Format:
    The only line of output of each test case contains space-separated digits which correspond to the sum of the two numbers 'A' and 'B'.

Note :
    You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
    1 <= T <= 10^2
    1 <= N, M <= 10^4
    0 <= A[i], B[i] <= 9

    Time Limit: 1 sec

Sample Input 1:
    2
    4 1
    1 2 3 4
    6
    3 2
    1 2 3
    9 9
Sample Output 1:
    1 2 4 0
    2 2 2
Explanation For Sample Input 1:
    For the first test case, the integer represented by the first array is 1234 and the second array is 6, so the sum is 1234 + 6 =  1240.
    For the second test case, the integer represented by the first array is 123 and the second array is 99, so the sum is 123 + 99 = 222.

************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

namespace std
{
    template <typename T>
    T *begin(std::pair<T *, T *> const &p) {
        return p.first;
    }
    template <typename T>
    T *end(std::pair<T *, T *> const &p) {
        return p.second;
    }
}

int main()
{
    int a[3] = {1, 8, 7};
    int b[4] = {1, 1, 8, 9};

    int n = 3, m = 4, n1 = a[0], n2 = b[0], temp = 0, ansNum = 0, digits = 0;
    for (int i = 1; i < n; i++)
    {
        n1 = n1 * 10 + a[i];
        // 		tens *= 10;
    }

    for (int i = 1; i < m; i++)
    {
        n2 = n2 * 10 + b[i];
        // 		tens *= 10;
    }
    cout << n1 << " " << n2 << " "  << n1+n2 << endl;

    ansNum = n1 + n2;
    digits = max(n, m) + 1;
    vector<int> res(digits, 0);
    int i = 0;
    while (ansNum != 0)
    {
        temp = ansNum % 10;
        res[digits - 1 - i] = temp;
        ansNum /= 10;
        i++;
    }

    // int big = max(n, m), res = n1+n2, temp = 0;
    // int* ans = new int[big+1];
    // for (int i = 0; i < big+1; i++) {
    //     ans[i] = 0;
    // }
    // int j = big;
    // while (res) {
    //     temp = res % 10;
    //     ans[j] = temp;
    //     res /= 10;
    //     j--;
    // }
    cout << endl;
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;

}