
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 17, 2024
// Creation TIME: 21:57:43

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// #GfG: Count Inversions
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

/*
DESCRIPTION :

    Given an array of integers. Find the Inversion Count in the array. 

    Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
    If an array is sorted in the reverse order then the inversion count is the maximum. 
    
    Formally, two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.


Examples:

    Input: n = 5, arr[] = {2, 4, 1, 3, 5}  Output: 3
    Explanation: The sequence 2, 4, 1, 3, 5 
    has three inversions (2, 1), (4, 1), (4, 3).

    Input: n = 5, arr[] = {2, 3, 4, 5, 6}  Output: 0
    Explanation: As the sequence is already 
    sorted so there is no inversion count.

    Input: n = 3, arr[] = {10, 10, 10}  Output: 0
    Explanation: As all the elements of array 
    are same, so there is no inversion count.


Expected Time Complexity: O(nLogn).
Expected Auxiliary Space: O(n).
*/ 


class Solution {
    public:
    long long int inversion = 0;
    void merge(long long arr[], long long int low, long long int mid, long long int high) {
        vector<long long> temp;
        
        long long int l1 = low, r1 = mid;
        long long int l2 = mid+1, r2 = high;
        
        while (l1 <= r1 && l2 <= r2) {
            if (arr[l1] <= arr[l2]) {
                temp.push_back(arr[l1]);
                l1++;
            } 
            else {
                temp.push_back(arr[l2]);
                l2++;
                inversion += (r1 - l1 + 1);
            }
        }
        while (l1 <= r1) {
            temp.push_back(arr[l1]);
            l1++;
        }
        while (l2 <= r2) {
            temp.push_back(arr[l2]);
            l2++;
        }
        for (int i = 0; i <= (high-low); i++) {
            arr[low+i] = temp[i];
        }
    }
    void mergeSort(long long arr[], long long int low, long long int high) {
        if (low >= high) return;
        
        long long int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    long long int inversionCount(int N, long long arr[]) {

        mergeSort(arr, 0, N-1);

        return inversion;
    }
};


int main() 
{
    Solution sol;

    // Input Initialization
    int long long n = 5;
    int long long arr[] = {2, 4, 1, 3, 5};

    // Method Invocation & Result Visualization
    cout << sol.inversionCount(n, arr) << endl;

    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n^2) TC | Brute Force
    - keep a counter varible for returning ans
    - make a nested for loop with [i: 0->n-2] & [j: i+1->n-1]
    - for each element arr[i] check if it is larger than arr[j]
        - if arr[i] > arr[j] then increase counter 
    - after complete execution of nested for loops return 'counter'.

2. O(n) Space & O(NlogN) TC | OPTIMIZED
    - implement whole merge sort code
    - in MERGE part of the code,  where we check if arr[l1] > arr[l2],
        - where l1 is the start index of 1st array to be merged and l2 is the start pointer of 2nd array in merging process
    - in case when (arr[l1] > arr[l2]) simply increase the counter by the number of elements present currently to the right of: [l1 till r1, both inclusive]
        - this is done since if element at l1 is greater than element at l2 
        => every element to the right of l1 in 1st array would also be greater than the current element at l2.
    - inversion += (r1 - l1 + 1);
    - return inversion count

    - Note: either use globle counter variable *[NOT RECCOMENDED]*
    or 
    - make the return types of merge sort to be integer 
        - and then return the counter by adding after each merge & merge sort cycle.
*/

