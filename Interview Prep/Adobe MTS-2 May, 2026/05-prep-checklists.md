# Prep Checklists — R1 & R2

**Track progress at a glance.** Focus Tier 1 first.

---

## R1 — DSA (C++)

### Intro & behavioral

| ☐ | Item | Notes |
|---|------|-------|
| [ ] | 90-sec intro | Paytm, 98%, MCP, why Adobe |
| [ ] | Current project | Onboarding Engine, 20+ workflows, 1L+ hits/API |
| [ ] | Caching story (98%) | Kibana, Redis cache-aside, invalidation |
| [ ] | MCP story | DB + logs + docs, 92% coverage |
| [ ] | SQL vs NoSQL answer | See doc 06 — **asked in actual R1** |

### Tier 1 problems (11 = 70% coverage)

| ☐ | LC# | Problem | Pattern |
|---|-----|---------|---------|
| [ ] | 98 | Validate BST | Tree |
| [ ] | 236 | LCA in Binary Tree | Tree |
| [ ] | 102 | Level Order Traversal | BFS |
| [ ] | 33 | Search Rotated Sorted Array | Binary search |
| [ ] | 875 | Koko Eating Bananas | BS on answer |
| [ ] | 1 | Two Sum | HashMap |
| [ ] | 49 | Group Anagrams | HashMap |
| [ ] | 3 | Longest Substring Without Repeating | Sliding window |
| [ ] | 713 | Subarray Product Less Than K | Sliding window |
| [ ] | 20 | Valid Parentheses | Stack |
| [ ] | **1574** | **Ants on Plank** | **Greedy / collision** |
| [ ] | **853** | **Car Fleet** | **Sort + greedy** |

### Tier 2

| ☐ | LC# | Problem | Pattern |
|---|-----|---------|---------|
| [ ] | 141 | Detect Loop in LL | Floyd |
| [ ] | 973 | K Closest Points | Heap |
| [ ] | 215 | Kth Largest | Heap |
| [ ] | 295 | Median from Data Stream | Two heaps |
| [ ] | 200 | Number of Islands | DFS/BFS |
| [ ] | 207 | Course Schedule | Topo sort |
| [ ] | 15 | 3Sum | Two pointers |
| [ ] | 56 | Merge Intervals | Intervals |

### Golden flow & mocks

| ☐ | Item |
|---|------|
| [ ] | Clarify → brute → optimize → dry run → code → test |
| [ ] | 2-medium mock in 60 min (timed) |
| [ ] | C++ STL confident |

### R1 status

| Metric | Progress |
|--------|----------|
| Tier 1 | ___ / 12 |
| Tier 2 | ___ / 8 |
| Mock completed | Yes / No |

---

## R2 — Python + Design + Backend

### Python (must know)

| ☐ | Topic |
|---|-------|
| [ ] | GIL — I/O vs CPU bound |
| [ ] | threading vs multiprocessing vs asyncio |
| [ ] | Decorators + `@wraps` |
| [ ] | `[[]]*3` trap, mutable default args |
| [ ] | `@classmethod` vs `@staticmethod` |
| [ ] | `collections`: OrderedDict, deque, Counter |
| [ ] | `heapq` basics |

### LLD (code from memory)

| ☐ | Design |
|---|--------|
| [ ] | LRU Cache |
| [ ] | Rate Limiter |
| [ ] | Document Ingestion (async) |
| [ ] | MCP Tool Registry |

### Backend verbal

| ☐ | Topic |
|---|-------|
| [ ] | Cache-aside + invalidation + stampede |
| [ ] | SQL vs NoSQL (when/why) |
| [ ] | Idempotency, pagination, rate limit |
| [ ] | ACID, isolation levels, indexing |
| [ ] | MCP story + Adobe bridge |

### RAG/MCP

| ☐ | Topic |
|---|-------|
| [ ] | RAG pipeline end-to-end |
| [ ] | Chunking (512–1024, overlap) |
| [ ] | Hallucination mitigation |
| [ ] | Hybrid search vs pure vector |

### R2 status

| Metric | Progress |
|--------|----------|
| Python concepts | ___ / 7 |
| LLD coded from memory | ___ / 4 |
| Backend verbal | ___ / 5 |
| RAG/MCP | ___ / 4 |

---

## Practice log

| Date | Type | Topic | Time | Result |
|------|------|-------|------|--------|
| May 22 | Actual R1 | Ants + Car Fleet + SQL | 60 min | Rejected |
| | Mock | | | |
| | Mock | | | |
