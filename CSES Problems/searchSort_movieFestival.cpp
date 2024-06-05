// Creation DATE: July 08, 2022
// Creation TIME: 04:11:01

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
#define intmax      INT_MAX
#define intmin      INT_MIN
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

bool sortByEndTime (pii &a, pii &b) {
    return a.S < b.S;
}
 
void solve() {
    int n, ans = 1, currEnd;
    cin >> n;
    vector<pii> time(n);
    rep (i, 0, n) {
        cin >> time[i].F;
        cin >> time[i].S;
    }
    sort(all(time), sortByEndTime);
    // for (auto x:time)cout << x.F << " " << x.S << " [] ";

    currEnd = time[0].S;
    rep (i, 0, n-1) {
        // cout << currEnd << " ";
        if (currEnd > time[i+1].F) continue;
        else {
            ans++;
            currEnd = time[i+1].S;
            // cout << endl;
        }
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