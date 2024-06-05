// Creation DATE: April 10, 2022
// Creation TIME: 20:28:52

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

using namespace std;
 
void solve() {
    int n, m, k, i = 0, j = 0, ans = 0;
    cin >> n >> m >> k;
    vi applicant(n, 0);
    vi houseSize(m, 0);
    
    rep(i, 0, n) cin >> applicant[i];
    rep(i, 0, m) cin >> houseSize[i];
    sort(all(houseSize));
    sort(all(applicant));

    while (i < n &&  j < m) {
        if (abs(applicant[i] - houseSize[j]) <= k) {
            ans++;
            i++; j++;
        }
        else if (applicant[i]-k > houseSize[j]) j++; //curr applicant's lowest need is > than curr left apartment : house small
        else if (applicant[i]+k < houseSize[j]) i++; // currently left house > applicant's upper limit : inadequate applicant
    }

    cout << ans;

    // for(long long h = 0; h < m; h++) {
    //     if (applicant[n-1] < 0 || houseSize[m-1] < 0) break;
    //     for (long long a = 0; a < n; a++) {
    //         if (applicant[a] < 0 || houseSize[h] < 0) continue;
    //         if (houseSize[h] < applicant[0]-k) break;
    //         if (houseSize[h] >= applicant[a]-k && houseSize[h] <= applicant[a]+k) {
    //             ans--;
    //             applicant[a] = ans;
    //             houseSize[h] = ans;
    //             break;
    //         }
    //     }
    // }
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