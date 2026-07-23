
#include <bits/stdc++.h>

using namespace std;

class DataStructure {
    vector<int> arr;
    unordered_map<int, int> mp;

    bool search(int val) {
        return (mp.find() != mp.end());
    }

    void insert(int x) {
        // Value 'x' is already present
        if (mp.find(x) != mp.end())
            return;

        arr.push_back(x);
        int idx = arr.size()-1;

        mp[x] = idx;        
    }

    void delete(int x) {
        // If value of 'x' is not present already
        if (mp.find(x) == mp.end())
            return;

        int n = arr.size();
        swap(arr[mp[x]], arr[n-1]);

        mp.erase(x);
        arr.delete(n-1);

    }

    void getRandom() {
        
    }
}

int main()
{
    //Code

    return 0;
}