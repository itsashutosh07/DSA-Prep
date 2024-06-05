#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, size, ans = 0, temp, prev;
    vector<long long> arr;
    
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    prev = arr[0];
    for (long long j = 1; j < n; j++) {
        if (prev > arr[j]) {
            ans += (prev-arr[j]);
            // arr[j] = prev;
        }
        prev = arr[j];
    }
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }    
    cout << endl << ans;

    return 0;
}