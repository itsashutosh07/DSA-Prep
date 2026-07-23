/**
 * Interview Experience IX — Additional DSA (C++)
 * Compile: g++ -std=c++17 -O2 17-cpp-interview-ix-problems.cpp -o ix && ./ix
 */

#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// 1. SUBARRAY PRODUCT LESS THAN K (LC #713) — IX-1 R1
// =============================================================================
/*
 * QUESTION:
 *   Count contiguous subarrays where product of all elements < k.
 *
 * CONSTRAINTS:
 *   1 <= nums.length <= 3*10^4, 1 <= nums[i] <= 1000, 0 <= k <= 10^6
 *
 * TC: O(n)   SC: O(1)
 *
 * DRY RUN: nums=[10,5,2,6], k=100
 *   Window [10] prod=10<100 → +1
 *   [10,5] prod=50 → +2, [5] → total building...
 *   Answer: 8
 */

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int left = 0, count = 0;
    long long product = 1;

    for (int right = 0; right < (int)nums.size(); right++) {
        product *= nums[right];
        while (product >= k) {
            product /= nums[left];
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

// =============================================================================
// 2. FIND MEDIAN FROM DATA STREAM (LC #295) — IX-2 R1
// =============================================================================
/*
 * QUESTION:
 *   addNum(num) adds to stream; findMedian() returns current median.
 *
 * CONSTRAINTS:
 *   Up to 10^5 calls; -10^5 <= num <= 10^5
 *
 * TC: addNum O(log n), findMedian O(1)   SC: O(n)
 *
 * DRY RUN: add 1,2,3,4
 *   maxHeap(lower) keeps max of lower half; minHeap(upper) keeps min of upper half
 *   After 1: [1] | []           → 1
 *   After 2: [1] | [2]          → 1.5
 *   After 3: [2,1] | [3]        → 2
 *   After 4: [2,1] | [3,4]      → 2.5
 */

class MedianFinder {
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half

    void balance() {
        if ((int)maxHeap.size() > (int)minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if ((int)minHeap.size() > (int)maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        balance();
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// =============================================================================
// 3. FRIENDS OF APPROPRIATE AGES (LC #825) — IX-2 R2
// =============================================================================
/*
 * QUESTION:
 *   Count friend requests: j accepts from i if
 *   age[j] > 0.5*age[i]+7 AND age[j] <= age[i] AND i != j
 *
 * CONSTRAINTS:
 *   1 <= ages.length <= 2*10^4, 1 <= ages[i] <= 120
 *
 * TC: O(120^2) ≈ O(1)   SC: O(120)
 *
 * DRY RUN: ages=[16,16] → 2 requests (each can friend the other)
 */

int numFriendRequests(vector<int>& ages) {
    int freq[121] = {0};
    for (int age : ages) freq[age]++;

    int requests = 0;
    for (int ageA = 1; ageA <= 120; ageA++) {
        if (!freq[ageA]) continue;
        for (int ageB = 1; ageB <= 120; ageB++) {
            if (!freq[ageB]) continue;
            if (ageB <= 0.5 * ageA + 7) continue;
            if (ageB > ageA) continue;
            int count = freq[ageA] * freq[ageB];
            if (ageA == ageB) count -= freq[ageA]; // can't friend self
            requests += count;
        }
    }
    return requests;
}

// =============================================================================
// 4. COURSE SCHEDULE / JOB SCHEDULING (LC #207) — IX-2 R3
// =============================================================================
/*
 * QUESTION:
 *   numCourses jobs, prerequisites [a,b] = must do b before a.
 *   Return true if all can finish (no cycle).
 *
 * CONSTRAINTS:
 *   1 <= numCourses <= 2000, 0 <= prerequisites.length <= 5000
 *
 * TC: O(V+E)   SC: O(V+E)
 *
 * DRY RUN: n=2, prereq=[[1,0]] → 0 before 1 → true
 *          n=2, prereq=[[1,0],[0,1]] → cycle → false
 */

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) q.push(i);

    int visited = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return visited == numCourses;
}

vector<int> topologicalOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return order.size() == numCourses ? order : vector<int>{};
}

// =============================================================================
// 5. LONGEST COMMON SUBSEQUENCE (LC #1143) — IX-3
// =============================================================================
/*
 * QUESTION:
 *   Length of longest subsequence common to text1 and text2 (not necessarily contiguous).
 *
 * CONSTRAINTS:
 *   1 <= text1.length, text2.length <= 1000
 *
 * TC: O(m*n)   SC: O(m*n) or O(min(m,n)) optimized
 *
 * DRY RUN: text1="abcde", text2="ace" → "ace" → 3
 */

int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// =============================================================================
// 6. BACKTRACKING TEMPLATE — Generate Parentheses (LC #22) — IX-2 R2 style
// =============================================================================
/*
 * QUESTION:
 *   Generate all combinations of n pairs of well-formed parentheses.
 *
 * CONSTRAINTS: 1 <= n <= 8
 * TC: O(4^n / sqrt(n)) Catalan   SC: O(n) recursion
 *
 * DRY RUN: n=2 → ["(())","()()"]
 */

void backtrackParen(int open, int close, int n, string& cur, vector<string>& result) {
    if ((int)cur.size() == 2 * n) {
        result.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        backtrackParen(open + 1, close, n, cur, result);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        backtrackParen(open, close + 1, n, cur, result);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string cur;
    backtrackParen(0, 0, n, cur, result);
    return result;
}

// =============================================================================
// main
// =============================================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Interview Experience IX — DSA Tests ===\n\n";

    // 1. Subarray Product Less Than K
    {
        vector<int> nums = {10, 5, 2, 6};
        cout << "1. Subarray Product < K [10,5,2,6], k=100: " << numSubarrayProductLessThanK(nums, 100) << "\n";
        vector<int> nums2 = {1, 2, 3};
        cout << "   Subarray Product < K [1,2,3], k=0: " << numSubarrayProductLessThanK(nums2, 0) << "\n";
    }

    // 2. Median Finder
    {
        MedianFinder mf;
        mf.addNum(1);
        cout << "2. Median after add 1: " << mf.findMedian() << "\n";
        mf.addNum(2);
        cout << "   Median after add 2: " << mf.findMedian() << "\n";
        mf.addNum(3);
        cout << "   Median after add 3: " << mf.findMedian() << "\n";
        mf.addNum(4);
        cout << "   Median after add 4: " << mf.findMedian() << "\n";
    }

    // 3. Friends of Appropriate Ages
    {
        vector<int> ages = {16, 16};
        cout << "3. Friends of Appropriate Ages [16,16]: " << numFriendRequests(ages) << "\n";
        vector<int> ages2 = {16, 17, 18};
        cout << "   Friends of Appropriate Ages [16,17,18]: " << numFriendRequests(ages2) << "\n";
    }

    // 4. Course Schedule
    {
        vector<vector<int>> prereq1 = {{1, 0}};
        cout << "4. Can finish 2 courses [[1,0]]: " << (canFinish(2, prereq1) ? "true" : "false") << "\n";
        vector<vector<int>> prereq2 = {{1, 0}, {0, 1}};
        cout << "   Can finish 2 courses cycle: " << (canFinish(2, prereq2) ? "true" : "false") << "\n";
        vector<vector<int>> prereq3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        vector<int> order = topologicalOrder(4, prereq3);
        cout << "   Topo order [1,0],[2,0],[3,1],[3,2]: [";
        for (int i = 0; i < (int)order.size(); i++) {
            cout << order[i];
            if (i + 1 < (int)order.size()) cout << ",";
        }
        cout << "]\n";
    }

    // 5. LCS
    {
        cout << "5. LCS \"abcde\" \"ace\": " << longestCommonSubsequence("abcde", "ace") << "\n";
    }

    // 6. Generate Parentheses
    {
        vector<string> parens = generateParenthesis(2);
        cout << "6. Generate Parentheses n=2: [";
        for (int i = 0; i < (int)parens.size(); i++) {
            cout << "\"" << parens[i] << "\"";
            if (i + 1 < (int)parens.size()) cout << ", ";
        }
        cout << "]\n";
    }

    cout << "\n=== All IX tests complete ===\n";
    return 0;
}
