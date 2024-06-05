// Creation DATE: April 02, 2022
// Creation TIME: 05:08:28

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
#define repr(i,a,b) for(int i=a;i>b;i--)

using namespace std;
 
void solve() {
    int flag = 0;
    string s, ans, half;
    char oddChar = '$';
    unordered_map<char, int> freq;
    cin >> s;

    for (auto x : s) {
        freq[x]++;
    }
    for (auto x : freq) {
        if (x.S % 2 == 1) {
            flag++;
            oddChar = x.F;
        }
        if (flag > 1) {
            cout << "NO SOLUTION";
            return;
        }
        // cout << x.F << " " << x.S << endl;
    }
    for (auto x: freq) {
        if (x.F != oddChar) {
            rep(i, 0, x.S/2) {
                ans += x.F;
            }
        }
    }
    half = ans;
    // cout << half << endl;
    if (oddChar != '$') {
        rep (i,0,freq[oddChar]){
            ans += oddChar;
        }
    }
    for (int i = half.size() - 1; i >= 0; i--) {
        ans += half[i];
    }

    cout << ans;
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