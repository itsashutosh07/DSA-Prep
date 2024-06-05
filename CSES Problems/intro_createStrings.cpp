// Creation DATE: May 31, 2022
// Creation TIME: 20:39:16

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

int fact(int n) {
    if (n == 0 || n == 1) return n;
    return n * fact(n-1);
}
set<string> st;
void permuteWithDuplicates(string a, int l, int r) {
    // base case
    if (l == r) {
        st.insert(a);
    }

    else {
        for (int i = l; i <= r; i++) {
            swap(a[i], a[l]);
            permuteWithDuplicates(a, l+1, r);
            swap(a[i], a[l]);
        }
    }
}

void permute(string s, string l) {
    if (s.length() < 1) cout << l+s << endl;
    unordered_set<char> uset;
    for (int i = 0; i < s.length(); i++) {
        if (uset.find(s[i]) != uset.end()) continue;
        else uset.insert(s[i]);

        string temp = "";

        if (i < s.length()-1) {
            temp = s.substr(0, i) + s.substr(i+1);
        }
        else {
            temp = s.substr(0, i);
        }
        permute(temp, l+s[i]);
    }
}
 
void solve() {
    string s;
    cin >> s;

    // vector<string> permutations;

    // sorting done because lexicographically smallest string need to come first according to thw question & alse for next_permutation function to work
    // sort(all(s));
    
    // do {
    //     permutations.pb(s);
    // } while (next_permutation(all(s)));

    // cout << permutations.size() << endl;
    
    // for (int i = 0; i < permutations.size(); i++) {
    //     cout << permutations[i] << endl;
    // }

    // ANOTHER APPROACH

    // int per = 0;

    // unordered_map<char, int> freq;
    // for (auto x : s) {
    //     freq[x]++;
    // }
    
    // // Total pemutations for "aabac" = (5!) / (3!*1!*1*)
    // per = fact(sz);
    // for (auto x: freq) {
    //     per /= fact(x.S);
    // }
    // cout << per << endl;

    int sz = s.length();
    sort(all(s));
    permuteWithDuplicates(s, 0, sz-1);
    cout << st.size() << endl;
    for (auto x: st) {
        cout << x << endl;
    }

    // return;
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