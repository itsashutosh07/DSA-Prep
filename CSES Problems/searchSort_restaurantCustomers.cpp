// Creation DATE: July 08, 2022
// Creation TIME: 01:49:20
 
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
#define pii         pair<ll,ll>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define MOD         10e9+7
#define intmax      INT_MAX
#define intmin      INT_MIN
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
 
using namespace std;
 
void solve() {
    ll n, ans = 0, curr = 0, arrival, departure;
    cin >> n;
    vector<pii> time;
    
    rep (i, 0, n) {
        cin >> arrival >> departure;
        time.pb({arrival, +1});
        time.pb({departure, -1});
    }
    sort(all(time));
    for (auto x: time) {
        curr += x.S;
        ans = max(ans, curr);
    }
 
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