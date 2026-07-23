#include <bits/stdc++.h>
using namespace std;

static bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

vector<pair<int, int>> groupIntervals(vector<pair<int, int>> inp) {

    if (inp.empty()) 
        return {};

    sort(inp.begin(), inp.end(), comp);

    int currMinStartTime = inp[0].first;
    int currMaxEndTime = inp[0].second;

    vector<pair<int, int>> ans;

    for (int i = 1; i < inp.size(); i++) {
        int currStartTime = inp[i].first, currEndTime = inp[i].second;

        // if curr interval is overlapping
        if (currMaxEndTime >= currStartTime) {
            currMaxEndTime = max(currMaxEndTime, currEndTime);
        }
        else { 
            // New interval found
            // Step-1: push the interval till now
            ans.push_back({currMinStartTime, currMaxEndTime});

            // Step-2: Start new interval
            currMinStartTime = currStartTime;
            currMaxEndTime = currEndTime;
        }
    }
    ans.push_back({currMinStartTime, currMaxEndTime});

    return ans;
}


int main () {
    vector<pair<int,int>> input = {
        {1,3}, {2,5}, {3,4}, {8,10}, {9,11}, {15,21}
    };

    auto ans = groupIntervals(input);

    for (auto x : ans) 
        cout << x.first << " " << x.second << endl;

    return 0;
}


