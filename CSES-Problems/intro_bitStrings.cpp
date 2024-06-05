#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i = 1, ans = 1;
    cin >> n;

    while (i <= n)
    {
        ans = (ans * 2) % 1000000007;
        i++;
    }

    cout << ans;

    return 0;
}