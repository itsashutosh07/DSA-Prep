// Creation DATE: July 05, 2022
// Creation TIME: 15:56:56

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
 
void solve() {
    int n, m;
    cin >> n >> m;


    multiset<int> tickets;
    rep(i, 0, n) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    rep (i, 0, m) {
        int t;
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) cout << -1 << endl;
        else {
            --it;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    // O(n^2) approach
    // vi ticket(n), customer(m);
    // rep (i, 0, n) cin >> ticket[i];
    // rep (i, 0, m) cin >> customer[i];
    
    // sort(all(ticket));

    // rep (i, 0, m) { //for each customer
    //     flag = 0;
    //     repr(j, n-1, 0) { //we check if the curr ticket price is lower or equal to the max the customer can pay
    //         if (ticket[j] <= customer[i] && ticket[j] != -1) {
    //             cout << ticket[j] << endl;
    //             ticket[j] = -1;
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0) {
    //         cout << -1 << endl;
    //     }
    // }
    
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