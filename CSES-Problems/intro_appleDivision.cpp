// Creation DATE: July 01, 2022
// Creation TIME: 21:42:01

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
#define MOD         10e9+7
#define intmax        INT_MAX
#define intmin        INT_MIN
#define endl        '\n'
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
 
void solve() {
    ll n, ans = INT_MAX, bkt1 = 0, bkt2 = 0, total = 0;
    cin >> n;
    vi apples (n);
    rep (i, 0, n) {
        cin >> apples[i];
        total += apples[i];
    }
    // sort(all(apples));
    
    // 2^n ---> (1<<n)
    rep (i, 1, (1<<n)) {
        bkt1 = 0;
        rep (j, 0, n) {
            if (i & (1 << j)) {
                bkt1 += apples[j];
            }
        }
        bkt2 = total - bkt1;
        ans = min(ans, abs(bkt1-bkt2));
    }

    // Wrong methord
    // repr(i, n-1, 0) {
    //     if (bkt1 <= bkt2) bkt1 += apples[i];
    //     else bkt2 += apples[i];
    // }
    // ans = abs(bkt1-bkt2);

    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }

    return 0;
}