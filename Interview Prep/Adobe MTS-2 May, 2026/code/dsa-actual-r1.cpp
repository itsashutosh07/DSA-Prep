/**
 * Actual Adobe R1 problems (May 22, 2026)
 * Compile: g++ -std=c++17 -O2 dsa-actual-r1.cpp -o actual && ./actual
 */

#include <bits/stdc++.h>
using namespace std;

// LC 1574 — Last Moment Before All Ants Fall Out of a Plank
// Insight: collision = pass-through → max distance any ant travels
// TC O(n) SC O(1)
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (int p : left)  ans = max(ans, p);
    for (int p : right) ans = max(ans, n - p);
    return ans;
}

// LC 853 — Car Fleet
// Sort by position desc (closest to target first), greedy on time
// TC O(n log n) SC O(n)
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    for (int i = 0; i < (int)position.size(); i++)
        cars.push_back({position[i], speed[i]});
    sort(cars.rbegin(), cars.rend());

    int fleets = 0;
    double maxTime = 0;
    for (auto& [pos, spd] : cars) {
        double time = (double)(target - pos) / spd;
        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }
    return fleets;
}

int main() {
    // Ants: n=4, left=[4,3], right=[0,1] → 4
    vector<int> left = {4, 3}, right = {0, 1};
    cout << "Ants: " << getLastMoment(4, left, right) << " (expect 4)\n";

    // Car Fleet: target=12
    vector<int> pos = {10, 8, 0, 5, 3}, spd = {2, 4, 1, 1, 3};
    cout << "Car Fleet: " << carFleet(12, pos, spd) << " (expect 3)\n";
    return 0;
}
