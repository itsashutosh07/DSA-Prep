// Creation DATE: June 14, 2024
// Creation TIME: 17:10:52

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

void selectionSort(int arr[], int n)
{
    // Brings minimums to start of array

    for (int i = 0; i < n-1; i++) {
        int min_num = arr[i];
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    // pushes maximums to the end of array by adjecent swappings

    // Iterative
    for (int k = 0; k < n; k++) {
        bool isSwapped = false;
        for (int i = 1; i < n-k; i++) {
            if (arr[i-1] > arr[i]) {
                swap(arr[i], arr[i-1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
    }

    // Recursive
    // if (n == 1) return;
        
    // bool isSwapped = false;
    // for (int i = 1; i < n; i++) {
    //     if (arr[i-1] > arr[i]) {
    //         swap(arr[i], arr[i-1]);
    //         isSwapped = true;
    //     }
    // }
    
    // if (!isSwapped) return;
    
    // bubbleSort(arr, n-1);
}

void insertionSort(int arr[], int n)
{
    //takes an element[i: 1->n-1] & moves the element backward in sorted part of the array till it's inserted @ correct position
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    // Recursive Insertion Sort
    // if (n <= 1) return;
    
    // insertionSort(arr, n-1);
    
    // int i = n-1;
    // while(i > 0 && arr[i] < arr[i-1]) {
    //     swap(arr[i], arr[i-1]);
    //     i--;
    // }
}

void merge(int arr[], int l, int m, int r) {
    int leftSize = m - l + 1;
    int rightSize = r - m;
    
    // Create temporary arrays
    int left[leftSize];
    int right[rightSize];
    
    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < leftSize; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < rightSize; j++)
        right[j] = arr[m + 1 + j];
    
    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = l; // Initial index of merged subarray
    
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of left[], if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of right[], if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Avoids overflow for large l and r
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int quickSortPartition (int arr[], int low, int high)
{
     // Choose a random pivot index between low and high
    int pivotIndex = low + rand() % (high - low + 1);

    // Swap the chosen pivot element with the first element
    swap(arr[pivotIndex], arr[low]);

    // Now continue with the partition logic as before
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while(arr[j] > pivot && j >= low + 1) {
            j--;
        }
        
        if (i < j)
            swap(arr[i], arr[j]);
   }
   swap(arr[low], arr[j]);
   return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pIndex = quickSortPartition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}


int main() {
    srand(time(0));  // Initialize random seed

    const int n = 10000;  // Size of the array

    int arr1[n];
    generate(arr1, arr1 + n, []() { return rand() % 10000; });
    measureSortTime(selectionSort, arr1, n, "Selection Sort");

    int arr2[n];
    generate(arr2, arr2 + n, []() { return rand() % 10000; });
    measureSortTime(bubbleSort, arr2, n, "Bubble Sort");

    int arr3[n];
    generate(arr3, arr3 + n, []() { return rand() % 10000; });
    measureSortTime(insertionSort, arr3, n, "Insertion Sort");

    int arr4[n];
    generate(arr4, arr4 + n, []() { return rand() % 10000; });
    measureSortTime(mergeSort, arr4, 0, n - 1, "Merge Sort");

    int arr5[n];
    generate(arr5, arr5 + n, []() { return rand() % 10000; });
    measureSortTime(quickSort, arr5, 0, n - 1, "Quick Sort");

    return 0;
}

/*

1. <:::::::::::: SELECTION SORT ::::::::::::> 
        Brings minimums to start of array

    - TC: O(N^2)
    - SC: O(1)
    - Stable: No
    - Inplace: Yes

    - Step1:
        - Selection: select minimum number 'arr[j]' in array for each index [i: 0 -> n-2] 
    - Step2: 
        - Bring minimum element arr[j] at index 'j' [j: i+1 -> n-1] to index i by swapping arr[i] & arr[j]

- Ex:
    step1:  [1 2 8 5 3 7 9 4 0]     |   []=>un-sorted part
             i j                    |   
                                    |
    step2:  [1 2 8 5 3 7 9 4 0]     |
             i               j      |   'j' is now at min element index
                                    |
    step3:   0[2 8 5 3 7 9 4 1]     |
               i j                  |   'j' will again search for min element index ahead of i & swap with i at end of iteration



2. <:::::::::::: BUBBLE SORT ::::::::::::> 
    Pushes maximums to the end of array by adjecent swappings

    - TC: O(N^2), for the best, worst, and average cases.
    - SC: O(1)
    - Stable: No
    - Inplace: Yes

    - Step1:
        - Each iteration should start from beganning and compare i-th index and its preceeding i-1th index
            - If element at i-1 is greater than element at i, then swap elements @ i<-->i-1
        - After each iteration we would have bubbled up the max element to last/sorted part of the array, so 

- Ex:
    step1:  [1    2 8 5 3 7 4 0]    |   []=>un-sorted part
             i-1  i                 |   
                                    |
    step2:  [1 2    8 5 3 7 4 0]    |   increase i in each iteration of inner loop
               i-1  i               | 
                                    |
    step2:  [1 2 8    5 3 7 4 0]    |   swap only if greater element is encountered at i-1 
                 i-1  i             |   
                                    |
    step3:  [1 2 5<->8 3 7 4 0]     |
                 i-1 i              |  
                                    |
    step3:  [1 2 5 8   3 7 4 0]     |
                   i-1 i            |  
                                    |
    step4:  [1 2 5 3<->8 7 4 0]     |
                   i-1 i            |   
                                    |
    stepX:  [1 2 5 3 7 4 0<->8]     |
                         i-1 i      | 
                                    |
    stepY:  [1 2 5 3 7 4 0] 8       |   8, the max in unsorted part has reached the sorted portion of array
                                    |
    stepZ:  [1 2 5 3 4 0] 7 8       |   7, the max in unsorted part has reached the sorted portion of array



2. <:::::::::::: INSERTION SORT ::::::::::::> 
    Pushes maximums to the end of array by adjecent swappings

    - TC: O(N^2), for the best, worst, and average cases.
    - SC: O(1)
    - Stable: No
    - Inplace: Yes

    - Step1:
        - Each iteration should start from beganning and compare i-th index and its preceeding i-1th index
            - If element at i-1 is greater than element at i, then swap elements @ i<-->i-1
        - After each iteration we would have bubbled up the max element to last/sorted part of the array, so 

- Ex:
    step1:  [1    2 8 5 3 7 4 0]    |   []=>un-sorted part
             i-1  i                 |   
                                    |
    step2:  [1 2    8 5 3 7 4 0]    |   increase i in each iteration of inner loop
               i-1  i               | 
                                    |
    step2:  [1 2 8    5 3 7 4 0]    |   swap only if greater element is encountered at i-1 
                 i-1  i             |   
                                    |
    step3:  [1 2 5<->8 3 7 4 0]     |
                 i-1 i              |  
                                    |
    step3:  [1 2 5 8   3 7 4 0]     |
                   i-1 i            |  
                                    |
    step4:  [1 2 5 3<->8 7 4 0]     |
                   i-1 i            |   
                                    |
    stepX:  [1 2 5 3 7 4 0<->8]     |
                         i-1 i      | 
                                    |
    stepY:  [1 2 5 3 7 4 0] 8       |   8, the max in unsorted part has reached the sorted portion of array
                                    |
    stepZ:  [1 2 5 3 4 0] 7 8       |   7, the max in unsorted part has reached the sorted portion of array

*/