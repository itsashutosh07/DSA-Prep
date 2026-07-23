/**
 * Adobe MTS-2 — Round 1 DSA (C++)
 * Each problem: Question · Constraints · TC/SC · Dry Run · Solution
 * Compile: g++ -std=c++17 -O2 11-cpp-dsa-implementations.cpp -o dsa && ./dsa
 */

#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// Shared structures
// =============================================================================

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// =============================================================================
// 1. TWO SUM (LC #1) — HashMap
// =============================================================================
/*
 * QUESTION:
 *   Given nums[] and target, return indices [i, j] such that nums[i] + nums[j] == target.
 *   Exactly one solution exists; cannot use same element twice.
 *
 * CONSTRAINTS:
 *   2 <= n <= 10^4
 *   -10^9 <= nums[i], target <= 10^9
 *
 * TC: O(n)   — single pass
 * SC: O(n)   — hash map stores up to n entries
 *
 * DRY RUN: nums = [2,7,11,15], target = 9
 *   i=0: num=2, complement=7, seen={}           → store seen[2]=0
 *   i=1: num=7, complement=2, seen={2:0}      → found! return [0,1]
 */

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement))
            return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

// =============================================================================
// 2. VALID PARENTHESES (LC #20) — Stack
// =============================================================================
/*
 * QUESTION:
 *   Given string s of '(', ')', '{', '}', '[', ']', determine if brackets are valid.
 *
 * CONSTRAINTS:
 *   1 <= s.length <= 10^4
 *   s consists of parentheses only
 *
 * TC: O(n)
 * SC: O(n)   — stack in worst case
 *
 * DRY RUN: s = "{[()]}"
 *   '{' → push '{'
 *   '[' → push '['
 *   '(' → push '('
 *   ')' → top='(' matches → pop
 *   ']' → top='[' matches → pop
 *   '}' → top='{' matches → pop
 *   stack empty → true
 */

bool isValidParentheses(const string& s) {
    stack<char> st;
    unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) return false;
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

// =============================================================================
// 3. BINARY TREE LEVEL ORDER TRAVERSAL (LC #102) — BFS
// =============================================================================
/*
 * QUESTION:
 *   Return level-order traversal (left to right, level by level).
 *
 * CONSTRAINTS:
 *   0 <= nodes <= 2000
 *   -1000 <= node.val <= 1000
 *
 * TC: O(n)
 * SC: O(n)   — queue + result
 *
 * DRY RUN:       3
 *              /   \
 *             9    20
 *                 /  \
 *                15   7
 *   q=[3]     → level [3]
 *   q=[9,20]  → level [9,20]
 *   q=[15,7]  → level [15,7]
 *   Output: [[3],[9,20],[15,7]]
 */

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

// =============================================================================
// 4. VALIDATE BST (LC #98) — Tree recursion
// =============================================================================
/*
 * QUESTION:
 *   Check if binary tree is a valid BST (left < root < right, recursively).
 *
 * CONSTRAINTS:
 *   0 <= nodes <= 10^4
 *   -2^31 <= val <= 2^31 - 1
 *
 * TC: O(n)
 * SC: O(h)  — recursion stack; h = height
 *
 * DRY RUN:       5
 *              /   \
 *             1     8
 *                  / \
 *                 6   9
 *   5 in (-inf, inf) ✓
 *   1 in (-inf, 5)   ✓
 *   8 in (5, inf)    ✓
 *   6 in (5, 8)      ✓
 *   9 in (8, inf)    ✓ → true
 */

bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

// =============================================================================
// 5. NUMBER OF ISLANDS (LC #200) — DFS
// =============================================================================
/*
 * QUESTION:
 *   Grid of '1' (land) and '0' (water). Count islands (connected '1's, 4-directional).
 *
 * CONSTRAINTS:
 *   m == grid.length, n == grid[i].length
 *   1 <= m, n <= 300
 *
 * TC: O(m * n)
 * SC: O(m * n) worst-case recursion depth
 *
 * DRY RUN:
 *   1 1 0       Start (0,0): DFS marks (0,0),(0,1),(1,0) → count=1
 *   1 0 0       Hit (2,2): '1' → DFS marks (2,2)         → count=2
 *   0 0 1       Answer: 2
 */

void dfsIsland(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size() || grid[r][c] != '1')
        return;
    grid[r][c] = '0';
    dfsIsland(grid, r + 1, c);
    dfsIsland(grid, r - 1, c);
    dfsIsland(grid, r, c + 1);
    dfsIsland(grid, r, c - 1);
}

int numIslands(vector<vector<char>> grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int r = 0; r < (int)grid.size(); r++)
        for (int c = 0; c < (int)grid[0].size(); c++)
            if (grid[r][c] == '1') {
                dfsIsland(grid, r, c);
                count++;
            }
    return count;
}

// =============================================================================
// 6. SEARCH IN ROTATED SORTED ARRAY (LC #33) — Binary Search (Adobe P2)
// =============================================================================
/*
 * QUESTION:
 *   Sorted array rotated at unknown pivot. Search target, return index or -1.
 *
 * CONSTRAINTS:
 *   1 <= n <= 5000
 *   All values distinct
 *   -10^4 <= nums[i], target <= 10^4
 *
 * TC: O(log n)
 * SC: O(1)
 *
 * DRY RUN: nums = [4,5,6,7,0,1,2], target = 0
 *   lo=0, hi=6, mid=3, nums[3]=7
 *   Left [4,5,6,7] sorted; 0 not in [4,7) → lo=4
 *   lo=4, hi=6, mid=5, nums[5]=1
 *   Left [0,1] sorted; 0 in [0,1) → hi=4
 *   lo=4, hi=4, mid=4, nums[4]=0 → return 4
 */

int searchRotated(vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;

        if (nums[lo] <= nums[mid]) {
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

// =============================================================================
// 7. LONGEST SUBSTRING WITHOUT REPEATING (LC #3) — Sliding Window (Adobe Tier 1)
// =============================================================================
/*
 * QUESTION:
 *   Find length of longest substring without repeating characters.
 *
 * CONSTRAINTS:
 *   0 <= s.length <= 5 * 10^4
 *   s consists of English letters, digits, symbols, spaces
 *
 * TC: O(n)
 * SC: O(min(n, alphabet)) — lastSeen map
 *
 * DRY RUN: s = "abcabcbb"
 *   i=0 'a': window "a"           len=1
 *   i=1 'b': window "ab"          len=2
 *   i=2 'c': window "abc"         len=3
 *   i=3 'a': duplicate → start=1, window "bca"  len=3
 *   i=4 'b': duplicate → start=2, window "cab"  len=3
 *   ... maxLen = 3
 */

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0, start = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (lastSeen.count(s[i]) && lastSeen[s[i]] >= start)
            start = lastSeen[s[i]] + 1;
        lastSeen[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

// =============================================================================
// 8. LINKED LIST CYCLE (LC #141) — Floyd (Adobe classic)
// =============================================================================
/*
 * QUESTION:
 *   Detect if linked list has a cycle.
 *
 * CONSTRAINTS:
 *   0 <= nodes <= 10^4
 *   -10^5 <= val <= 10^5
 *
 * TC: O(n)
 * SC: O(1)
 *
 * DRY RUN: 3 → 2 → 0 → -4 ↩ (points back to 2)
 *   slow=3, fast=3
 *   slow=2, fast=0
 *   slow=0, fast=2
 *   slow=-4, fast=-4 → equal → cycle detected
 */

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// =============================================================================
// 9. KTH LARGEST ELEMENT IN ARRAY (LC #215) — Min Heap
// =============================================================================
/*
 * QUESTION:
 *   Return the k-th largest element (not k-th distinct).
 *
 * CONSTRAINTS:
 *   1 <= k <= n <= 10^5
 *   -10^4 <= nums[i] <= 10^4
 *
 * TC: O(n log k)
 * SC: O(k)   — min-heap of size k
 *
 * DRY RUN: nums = [3,2,1,5,6,4], k = 2
 *   push 3 → heap [3]
 *   push 2 → heap [2,3]
 *   push 1 → heap [1,3,2] size=3 > k → pop 1 → [2,3]
 *   push 5 → heap [2,3,5] → pop 2 → [3,5]
 *   push 6 → heap [3,5,6] → pop 3 → [5,6]
 *   push 4 → heap [4,5,6] → pop 4 → [5,6]
 *   top = 5 (2nd largest)
 */

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// =============================================================================
// 10. MERGE INTERVALS (LC #56)
// =============================================================================
/*
 * QUESTION:
 *   Merge all overlapping intervals.
 *
 * CONSTRAINTS:
 *   1 <= intervals.length <= 10^4
 *   intervals[i].length == 2
 *   0 <= start <= end <= 10^4
 *
 * TC: O(n log n) — sort dominates
 * SC: O(n)       — output
 *
 * DRY RUN: [[1,3],[2,6],[8,10],[15,18]]
 *   sort unchanged
 *   result = [[1,3]]
 *   [2,6] overlaps 3 → merge → [[1,6]]
 *   [8,10] no overlap → [[1,6],[8,10]]
 *   [15,18] no overlap → [[1,6],[8,10],[15,18]]
 */

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1])
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        else
            result.push_back(intervals[i]);
    }
    return result;
}

// =============================================================================
// Test helpers
// =============================================================================

void printVec(const vector<int>& v, const string& label) {
    cout << label << " [";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]\n";
}

void print2D(const vector<vector<int>>& v, const string& label) {
    cout << label << " [";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "[";
        for (int j = 0; j < (int)v[i].size(); j++) {
            cout << v[i][j];
            if (j + 1 < (int)v[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]\n";
}

TreeNode* buildTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)vals.size()) {
        TreeNode* cur = q.front();
        q.pop();
        if (i < (int)vals.size() && vals[i] != -1) {
            cur->left = new TreeNode(vals[i]);
            q.push(cur->left);
        }
        i++;
        if (i < (int)vals.size() && vals[i] != -1) {
            cur->right = new TreeNode(vals[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

ListNode* buildCycleList(const vector<int>& vals, int pos) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;

    for (int i = 1; i < (int)vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
        if (i == pos) cycleNode = tail;
    }
    if (pos >= 0) tail->next = cycleNode;
    return head;
}

// =============================================================================
// main — runs all test cases
// =============================================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Adobe MTS-2 R1 DSA Tests (C++) ===\n\n";

    // 1. Two Sum
    {
        vector<int> nums = {2, 7, 11, 15};
        printVec(twoSum(nums, 9), "1. Two Sum [2,7,11,15] target=9:");
        vector<int> nums2 = {3, 3};
        printVec(twoSum(nums2, 6), "   Two Sum [3,3] target=6:");
    }

    // 2. Valid Parentheses
    {
        cout << "2. Valid Parentheses \"()[]{}\"  : " << (isValidParentheses("()[]{}") ? "true" : "false") << "\n";
        cout << "   Valid Parentheses \"([)]\"     : " << (isValidParentheses("([)]") ? "true" : "false") << "\n";
        cout << "   Valid Parentheses \"{[()]}\"   : " << (isValidParentheses("{[()]}") ? "true" : "false") << "\n";
    }

    // 3. Level Order
    {
        TreeNode* root = buildTree({3, 9, 20, -1, -1, 15, 7});
        print2D(levelOrder(root), "3. Level Order [3,9,20,null,null,15,7]:");
    }

    // 4. Validate BST
    {
        TreeNode* valid = buildTree({5, 1, 8, -1, -1, 6, 9});
        TreeNode* invalid = buildTree({5, 1, 8, -1, -1, 4, 9});
        cout << "4. Validate BST (5,1,8,6,9)       : " << (isValidBST(valid) ? "true" : "false") << "\n";
        cout << "   Validate BST (5,1,8,4,9)       : " << (isValidBST(invalid) ? "true" : "false") << "\n";
    }

    // 5. Number of Islands
    {
        vector<vector<char>> grid = {
            {'1','1','0'},
            {'1','0','0'},
            {'0','0','1'}
        };
        cout << "5. Number of Islands              : " << numIslands(grid) << "\n";
    }

    // 6. Search Rotated
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        cout << "6. Search Rotated target=0        : index " << searchRotated(nums, 0) << "\n";
        cout << "   Search Rotated target=3        : index " << searchRotated(nums, 3) << "\n";
    }

    // 7. Longest Substring
    {
        cout << "7. Longest Substring \"abcabcbb\"  : " << lengthOfLongestSubstring("abcabcbb") << "\n";
        cout << "   Longest Substring \"bbbbb\"     : " << lengthOfLongestSubstring("bbbbb") << "\n";
    }

    // 8. Linked List Cycle
    {
        ListNode* withCycle = buildCycleList({3, 2, 0, -4}, 1);
        ListNode* noCycle = buildCycleList({1, 2, 3}, -1);
        cout << "8. Has Cycle (3,2,0,-4 cycle@1)   : " << (hasCycle(withCycle) ? "true" : "false") << "\n";
        cout << "   Has Cycle (1,2,3 no cycle)     : " << (hasCycle(noCycle) ? "true" : "false") << "\n";
    }

    // 9. Kth Largest
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        cout << "9. Kth Largest k=2 [3,2,1,5,6,4] : " << findKthLargest(nums, 2) << "\n";
    }

    // 10. Merge Intervals
    {
        vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
        print2D(merge(intervals), "10. Merge Intervals:");
    }

    cout << "\n=== All tests complete ===\n";
    return 0;
}
