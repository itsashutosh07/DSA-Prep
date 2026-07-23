# Actual Interview Debrief — Adobe MTS-II R1 (May 22, 2026)

**Outcome:** Rejected after R1 (R2 not scheduled)  
**Format:** ~1 hour · C++ · 2 DSA problems (sequential — Q2 only after Q1 done/admitted defeat)  
**Also asked:** About me · SQL vs NoSQL (before/during DSA)

This is the **highest-value doc** in the folder — real questions, best answers, pitfalls.

---

## Round structure (what actually happened)

1. About me / project discussion
2. SQL vs NoSQL deep dive
3. **DSA Q1** — Ants on Plank (~50 min, solved with code)
4. **DSA Q2** — Car Fleet (~10–15 min left, approach only, no code)
5. Feedback → rejection (no R2)

**Lesson:** Adobe R1 is not "pure DSA." Behavioral + DB questions matter. **Speed on 2 mediums** is the bar.

---

## Q0: About Me

**Best answer:** Use 90-sec intro from [01-foundation-stories.md](./01-foundation-stories.md).

**Pitfalls:**
- Don't ramble beyond 2 min
- Lead with **impact numbers** (98%, 1L+ hits, MCP, 20+ workflows)
- End with why Adobe / Document Cloud / GenAI

---

## Q1: SQL vs NoSQL (ASKED IN YOUR R1)

### Questions asked
- Why SQL only in your project?
- Have you used NoSQL?
- When would you prefer MySQL over NoSQL?
- Why didn't you use NoSQL at Paytm?

### Best answer

> "At Paytm Onboarding Engine we used **MySQL** because our domain is inherently **relational**:
>
> 1. **ACID transactions** — multi-step onboarding workflows need all-or-nothing state transitions.
> 2. **Complex joins** — merchant, workflow, audit, and config tables are queried together.
> 3. **Schema enforcement** — foreign keys prevent bad data (invalid merchant_id, orphan workflow steps).
>
> **When I'd choose NoSQL:**
> - High write throughput logs/events → Cassandra, MongoDB
> - Flexible schema / nested documents → MongoDB
> - Key-value session/cache → Redis, DynamoDB
> - Horizontal scale on simple access patterns → DynamoDB, Cassandra
>
> **Why not NoSQL at Paytm:**
> Workflow data is relational. NoSQL would mean app-level joins, weaker consistency guarantees, and no FK enforcement. We **did** use **Redis** for caching (my 98% latency story) — right tool for that job.
>
> **Wyse internship:** I used **MongoDB** with Django for a product with flexible document-shaped data — so I've used both."

### Pitfalls to avoid
- ❌ "SQL is always better" — shows no nuance
- ❌ "I never used NoSQL" — you have MongoDB at Wyse
- ❌ Can't name a single NoSQL use case
- ✅ Always tie back to **your Paytm domain** + mention Redis as complementary

---

## Q2: Ants on a Plank (LC 1574)

### Problem
Plank length `n`. Ants at positions in `left` (moving left) and `right` (moving right), speed 1 unit/sec. On collision, ants **swap direction** instantly. When an ant reaches an end, it falls. Return time when **last ant falls**.

### Key insight (collision trick)
When two ants collide and swap direction, it's equivalent to them **passing through each other** (identical ants). So answer = **max time for any ant to reach an edge**.

- Ant moving **left** at position `p`: falls at time `p`
- Ant moving **right** at position `p`: falls at time `n - p`
- Answer: `max(all those times)`

### Optimal solution — O(n)

```cpp
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (int p : left)  ans = max(ans, p);
    for (int p : right) ans = max(ans, n - p);
    return ans;
}
```

**TC:** O(n) · **SC:** O(1)

### Your approach (also correct)
You sorted both arrays and took:
- `right[0]` (leftmost right-moving) → time `n - right[0]`
- `left.back()` (rightmost left-moving) → time `left.back()`

**This works** but sorting is unnecessary — single pass gives same answer in O(n).

### Dry run
`n=4, left=[4,3], right=[0,1]`
- Left ant at 4 → 4 sec; at 3 → 3 sec
- Right ant at 0 → 4 sec; at 1 → 3 sec
- **Answer: 4**

### Pitfalls
- ❌ Simulating collisions one-by-one — overcomplicated, slow
- ❌ Forgetting ants moving right use `n - position`
- ❌ Sorting when only min(right) and max(left) needed
- ✅ State collision = pass-through insight **early** (saves 20+ min)

### Why it hurt you
You **solved it correctly** but spent ~50 min. That left almost no time for Q2.

---

## Q3: Car Fleet (LC 853)

### Problem
`n` cars at `position[i]` with `speed[i]`. Cars can't pass — faster cars catch slower and travel at slower speed (form fleet). Fleet speed = min speed in fleet. Return **number of fleets** reaching `target`.

### Key insight
Process cars **closest to target first** (sort by position descending). Each car's time to target = `(target - position) / speed`. If current car's time **≤** previous fleet's time, it merges (same fleet). If **>**, new fleet.

### Optimal solution — O(n log n)

```cpp
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> cars;
    for (int i = 0; i < position.size(); i++)
        cars.push_back({position[i], speed[i]});
    sort(cars.rbegin(), cars.rend()); // closest to target first

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
```

**TC:** O(n log n) · **SC:** O(n)

### Your approach
- Sort by position ✓
- Compare each car's time with cars ahead — correct direction
- Said O(n log n) + O(n²) — the **n² is unnecessary**; one pass after sort is O(n)

### Dry run
`target=12, position=[10,8,0,5,3], speed=[2,4,1,1,3]`

| pos | speed | time to 12 |
|-----|-------|------------|
| 10 | 2 | 1.0 → fleet 1 |
| 8 | 4 | 1.0 → merges (≤ 1.0) |
| 5 | 1 | 7.0 → fleet 2 |
| 3 | 3 | 3.0 → merges into fleet 2 (≤ 7.0) |
| 0 | 1 | 12.0 → fleet 3 |

**Answer: 3**

### Pitfalls
- ❌ O(n²) pairwise comparison after sort — overkill
- ❌ Sort ascending instead of descending (process from target side)
- ❌ Not recognizing as **monotonic stack / greedy** pattern
- ❌ Running out of time before coding — **state approach + pseudocode in 5 min** if no time left

### What you should say with 5 min left
> "Sort cars by position descending. Track max time seen. For each car, compute time = (target - pos) / speed. If time > maxTime, new fleet; else merges. O(n log n) sort + O(n) scan."

---

## Rejection analysis (honest)

| Factor | Assessment |
|--------|------------|
| Q1 solved | ✅ Strong |
| Q1 speed | ❌ Too slow (~50 min) |
| Q2 coded | ❌ No |
| Q2 approach | ⚠️ Partial (sort correct, complexity overstated) |
| SQL/behavioral | ✅ Likely fine |
| **Net signal** | Can solve medium, but **not fast enough for 2-problem bar** |

---

## Pitfalls to avoid (summary)

| Pitfall | Fix |
|---------|-----|
| Q1 eats entire hour | Hard cap 30 min; then pseudocode + move on |
| Over-engineering (sort when scan works) | Ask "do I need full sort?" |
| Silent coding | Narrate continuously |
| No SQL prep in "DSA round" | Treat behavioral/DB as first-class |
| Q2 with no code | Always leave 5 min for approach + complexity even if no code |
| Assuming R2 same day | R2 conditional; R1 must stand alone |

---

## Patterns to drill (from your actual loop)

| LC# | Pattern | Must recognize in < 2 min |
|-----|---------|---------------------------|
| 1574 | Collision = pass-through / max distance | Greedy |
| 853 | Sort by position + greedy on time | Stack/greedy |
| — | SQL vs NoSQL for your domain | Verbal |

**Add to rotation:** 2 more greedy/stack mediums timed at 25 min each.

---

## Follow-up email (optional)

> Hi Sanchitha, thank you for the opportunity. If possible, I'd appreciate brief feedback on my R1 performance to improve for future opportunities. Best, Ashutosh

---

## Questions for future Adobe loops

**R1:** "Is the expectation to fully code both problems or is strong approach on second acceptable?"  
**R2:** "Is MCP work internal platform or customer-facing?"  
**General:** "Biggest retrieval-quality vs latency trade-off on the team?"

---

## Mock replay plan (for next company)

| Week | Activity |
|------|----------|
| 1 | Ants + Car Fleet — code each in < 25 min from scratch |
| 2 | 2 random mediums, 60 min, no hints |
| 3 | Add SQL/behavioral 10 min before each mock |
| Ongoing | 1 timed mock/week |

Reference solutions: [`code/dsa-core.cpp`](./code/dsa-core.cpp) · add Ants + Car Fleet there if practicing.
