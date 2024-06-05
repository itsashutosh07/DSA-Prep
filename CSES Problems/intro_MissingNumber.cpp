
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, missing;
    cin >> n;

    vector<int> vect;
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        vect.push_back(a);
    }

    sort(vect.begin(), vect.end());

    vect.push_back(0);

    for (int exp = 1; exp <= n; exp++) {
        if (exp != vect[exp-1]) {
            missing = exp;
            break;
        }
    }

    cout << missing;
    
    return 0;
}