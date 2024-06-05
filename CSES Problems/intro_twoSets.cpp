#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long n, sumOfNos, halfSum, i;
    long long a1 = 0, a2 = 0;
    cin >> n;
    vector<long long> ans (n, 0);
    sumOfNos = (n * (n + 1)) / 2;

    if (sumOfNos % 2 == 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    halfSum = sumOfNos / 2;
    i = n;
    while (halfSum > 0 && i > 0) {
        if (halfSum - i >= 0) {
            halfSum -= i;
            ans[i-1] = 1;
            a1++;
        }
        i--;
    }

    cout << a1 << endl;
    for (long long i = 0; i < n; i++) {
        if (ans[i] == 1) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
    a2 = n - a1; 
    cout << a2 << endl;
    for (long long i = 0; i < n; i++) {
        if (ans[i] == 0) {
            cout << i+1 << " ";
        }
    }

    return 0;
}