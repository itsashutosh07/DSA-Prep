#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
    }
    else {
        for (long long i = 2; i <= n; i+=2) {
            cout << i << " ";
        }
        for (long long j = 1; j <= n; j+=2) {
            cout << j << " ";
        }
    }
    // for (long long i = 0; i < n; i++) {
    //     arr[i] = i+1;
    // }
    // for (long long j = 0; j < n; j++) {
    //     while (arr.size() != 0) {
    //         if (arr[j] != ans[k] - 1 || arr[j] != ans[k] + 1) {
    //             ans[j] = arr[k];
    //         }
    //         k++;
    //     }
    // }
        

    return 0;
}