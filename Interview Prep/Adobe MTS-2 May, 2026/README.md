# Adobe MTS-II Backend — Prep Archive

**Role:** MTS-2 · Document Cloud / GenAI / ML Ops · Noida  
**Outcome:** R1 completed May 22, 2026 — rejected after R1 (no R2)  
**Languages:** C++ for DSA · Python for R2 design/backend · Java in production

---

## Read in this order

| # | File | Content | When |
|---|------|---------|------|
| 1 | [01-foundation-stories.md](./01-foundation-stories.md) | Role, loop, intro, all STAR stories | First |
| 2 | [02-dsa-cpp.md](./02-dsa-cpp.md) | Golden flow, patterns, problem list, STL | R1 prep |
| 3 | [03-r2-python-lld-backend.md](./03-r2-python-lld-backend.md) | Python, LLD, backend fundamentals | R2 prep |
| 4 | [04-rag-mcp-genai.md](./04-rag-mcp-genai.md) | RAG, embeddings, MCP (role domain) | R2 + HM |
| 5 | [05-prep-checklists.md](./05-prep-checklists.md) | R1 + R2 trackable checklists | During prep |
| 6 | **[06-actual-interview-debrief.md](./06-actual-interview-debrief.md)** | **Real questions, answers, pitfalls, lessons** | **Most important** |

**Code:** [`code/dsa-core.cpp`](./code/dsa-core.cpp) · [`code/dsa-ix-problems.cpp`](./code/dsa-ix-problems.cpp) · [`code/dsa-actual-r1.cpp`](./code/dsa-actual-r1.cpp) ⭐ · [`code/r2-python.py`](./code/r2-python.py)

---

## What Adobe tests

| Signal | How you show it |
|--------|-----------------|
| Medium DSA + speed | 2 problems in ~1 hr, narrate, optimize |
| Production backend | Paytm stories — caching, scale, MCP |
| Clear trade-offs | Cache invalidation, SQL vs NoSQL, sync vs async |
| Python fluency (R2) | GIL, decorators, LRU, rate limiter |
| GenAI adjacency | RAG pipeline, MCP protocol |

**Your edge:** Real production wins (98% latency cut, MCP servers, 1L+ weekly API hits).  
**Your gap (from actual R1):** DSA speed — solved Q1 but used almost full hour; Q2 not coded.

---

## Prep priority (by weight)

| Priority | Area |
|----------|------|
| 1 | Medium DSA patterns + **speed under time** |
| 2 | Resume / project deep dive |
| 3 | Backend fundamentals (caching, DB, API) |
| 4 | Python + LLD |
| 5 | RAG / MCP basics |
| 6 | Hard DP | Skip |

---

## Key lessons from your loop

1. **Time-box:** ~25–30 min per medium. If stuck at 20 min, state optimal approach + pseudocode, then code.
2. **Pattern recall > problem count:** Greedy/stack (Car Fleet), collision insight (Ants) must be instant.
3. **Behavioral + SQL questions count** even in "DSA" rounds — prep them equally.
4. **R2 is conditional** on R1 feedback; strong partial ≠ pass if speed bar not met.

---

## DO / DON'T

| DO | DON'T |
|----|-------|
| 2 timed mocks/week (2 mediums, 60 min) | Grind 200 random problems |
| Rehearse stories out loud | Silent coding |
| Brute → optimize → dry run → code | Jump to code without clarifying |
| Sound like "I built it" | Overcomplicate to sound smart |

---

## External refs

[`Concept Revision/`](../../Concept%20Revision/) · Your C++ repo: `SDE-Sheet/`, `Sliding Window/`, `DP/`
