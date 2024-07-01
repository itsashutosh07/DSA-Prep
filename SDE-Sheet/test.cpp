#include <bits/stdc++.h>

using namespace std;

// Function to check if it is possible to allocate paintings such that no painter takes more than 'maxTime'
bool isFeasible(const vector<long long>& lengths, int painters, long long maxTime) {
    int requiredPainters = 1;
    long long currentTime = 0;

    for (int i = 0; i < lengths.size(); i++) {
        if (lengths[i] > maxTime) {
            return false; // If a single painting is larger than maxTime, it's not feasible
        }

        if (currentTime + lengths[i] > maxTime) {
            // If adding this painting exceeds maxTime, allocate a new painter
            requiredPainters++;
            currentTime = lengths[i];

            if (requiredPainters > painters) {
                return false;
            }
        } else {
            currentTime += lengths[i];
        }
    }

    return true;
}

long long findMinimumTime(int n, const vector<long long>& lengths, int painters) {
    long long low = *max_element(lengths.begin(), lengths.end()); // Minimum possible time
    long long high = accumulate(lengths.begin(), lengths.end(), 0LL); // Maximum possible time
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isFeasible(lengths, painters, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<long long> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }
    int painters;
    cin >> painters;

    cout << findMinimumTime(n, lengths, painters) << endl;

    return 0;
}