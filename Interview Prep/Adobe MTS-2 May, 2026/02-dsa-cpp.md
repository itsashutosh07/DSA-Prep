# DSA — Patterns, Problems & C++ (R1)

**Prev:** [01-foundation-stories.md](./01-foundation-stories.md) · **Next:** [03-r2-python-lld-backend.md](./03-r2-python-lld-backend.md)  
**Code:** [`code/dsa-core.cpp`](./code/dsa-core.cpp) · [`code/dsa-ix-problems.cpp`](./code/dsa-ix-problems.cpp)

**Goal:** Pattern recall + **speed** (2 mediums in ~60 min). Not 200 problems.

---

## Golden flow (every problem)

| Step | Do | Time budget |
|------|-----|-------------|
| 1 Clarify | Size, sorted, duplicates, negatives, empty | 3–5 min |
| 2 Brute force | State naive solution + why bad | 2 min |
| 3 Optimize | Name pattern, TC/SC | 3 min |
| 4 Dry run | Out loud on example | 3 min |
| 5 Code | C++, narrate continuously | 15–20 min |
| 6 Test | Edge cases | 2 min |

**If stuck at 20 min:** State optimal approach + pseudocode → ask to move on or code skeleton.

---

## Time management (from your actual R1)

| Mistake | Fix |
|---------|-----|
| Q1 took ~50 min | Cap at 30 min; partial credit for approach + pseudocode |
| Q2 only 10–15 min left | Ask clarifying Qs fast; recognize pattern early |
| Over-engineered (sort when O(n) scan works) | Ask: "Do I need full sort or just min/max?" |

---

## Pattern priority (Adobe frequency data)

| P | Pattern | Must-know LC# |
|---|---------|---------------|
| P1 | Trees | 98 Validate BST · 236 LCA · 102 Level Order |
| P2 | Binary Search | 33 Search Rotated · 875 Koko Bananas |
| P3 | HashMap/Array | 1 Two Sum · 49 Group Anagrams · 66 Plus One |
| P4 | Sliding Window | 3 Longest Substring · 713 Subarray Product < K |
| P5 | Stack | 20 Valid Parentheses · Stock Span |
| P6 | Linked List | 141 Detect Cycle · Queue using LL |
| P7 | Heap | 973 K Closest · 215 Kth Largest · 295 Median Stream |
| P8 | Graph | 200 Number of Islands · 207 Course Schedule |
| P9 | Two Pointers | 15 3Sum · 825 Friends of Ages |
| P10 | Intervals | 56 Merge Intervals |
| P11 | Greedy/Stack | **853 Car Fleet** · **1574 Ants on Plank** |
| P12 | DP (R3) | 1143 LCS · 198 House Robber |

**Top 5 (LC 3, 98, 33, 1, 20) ≈ 70% of community R1 questions.**

---

## Tier 1 problems (practice first)

| LC# | Problem | Pattern | Key insight |
|-----|---------|---------|-------------|
| 3 | Longest Substring Without Repeating | Sliding window | Expand right, shrink left on duplicate |
| 98 | Validate BST | Tree | In-order or (min,max) bounds per node |
| 33 | Search Rotated Sorted Array | Binary search | One half always sorted |
| 1 | Two Sum | HashMap | Complement lookup O(n) |
| 20 | Valid Parentheses | Stack | Push open, pop on match |

---

## Tier 2 problems

| LC# | Problem | Pattern |
|-----|---------|---------|
| 141 | Detect Loop in LL | Floyd cycle |
| 66 | Plus One | Array carry |
| 973 | K Closest Points | Max-heap size k |
| 200 | Number of Islands | DFS/BFS |
| 236 | LCA in Binary Tree | Recursion |
| 713 | Subarray Product < K | Sliding window — count subarrays ending at right |
| 295 | Median from Data Stream | Two heaps |
| 207 | Course Schedule | Topological sort |

---

## Adobe-unique (non-standard LC)

| Problem | Pattern |
|---------|---------|
| Stock Span | Monotonic stack |
| Print ancestors of node | Tree path tracking |
| Connect nodes at same level | BFS level linking |
| Two elements in BST sum = K | Inorder + two pointers |
| Move negatives to end | Two pointers |
| Preorder without recursion | Stack |

---

## Actual R1 problems (your loop) — see [06-actual-interview-debrief.md](./06-actual-interview-debrief.md)

| LC# | Problem | Pattern | Your result |
|-----|---------|---------|-------------|
| 1574 | Last Moment Before All Ants Fall | Greedy / collision trick | ✅ Solved (slow) |
| 853 | Car Fleet | Sort + greedy on time | ⚠️ Approach only |

---

## C++ STL quick reference

```cpp
unordered_map<int,int> m; m.count(k); m[k]=v;
unordered_set<int> s; s.insert(x); s.count(x);
stack<int> st; queue<int> q;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
sort(v.begin(), v.end());
lower_bound(v.begin(), v.end(), x);  // first >= x
```

---

## Community IX problems (other Adobe loops)

| LC# | Problem | Pattern | Round |
|-----|---------|---------|-------|
| 713 | Subarray Product < K | Sliding window | R1 |
| 295 | Median from Data Stream | Two heaps | R1 |
| 825 | Friends of Appropriate Ages | Counting | R2 |
| 207 | Course Schedule | Topo sort | R3 |
| 1143 | LCS | DP | R3 |

---

## Mock protocol

**Weekly:** 2 mediums, 60 min, C++, narrate out loud, no IDE autocomplete.  
**Log:** Problem · Time · Pattern recognized? · Coded fully? · Notes

| Date | P1 | P2 | Time | Notes |
|------|----|----|------|-------|
| May 22 (actual) | Ants ✅ | Car Fleet partial | ~60 min | Rejected — speed |
