// Creation DATE: April 04, 2022
// Creation TIME: 10:29:59

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define MOD        10e9+7
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
static int steps = 0;

using namespace std;
void toh(int n, int src, int aux, int dest) {
    if (n == 0) {
        return;
    }
    toh(n - 1, src, dest, aux);
    steps++;
    cout << src << " " << dest << endl;
    toh(n - 1, aux, src, dest);
}
 
void solve() {
    int n, ans = 1, i;
    cin >> n;
    i = n;
    while (i--) {
        ans *= 2;
    }
    // if ( n != 1) ans = (n * n) - 1;
    cout << ans-1 << endl;
    toh(n, 1, 2, 3);
    // cout << endl << steps << endl;

    // cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    while(t--) {
        solve();
    }

    return 0;
}