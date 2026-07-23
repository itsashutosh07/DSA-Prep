# Foundation — Role, Intro & Stories

**Next:** [02-dsa-cpp.md](./02-dsa-cpp.md)

**Rule:** Sound like **"I built it"** — not "I was around when it happened."

---

## Snapshot

| | |
|---|---|
| **Current** | Software Engineer @ Paytm — Onboarding Engine |
| **Stack** | Java, Spring Boot, MySQL, Redis, AWS |
| **Also** | Python, MCP servers, Cursor/Copilot |
| **Education** | B.Tech CSE, NSUT (2019–2023) |

---

## Interview loop (recruiter-confirmed)

| Round | Focus | Language |
|-------|-------|----------|
| **R1** | DSA Easy→Medium + resume/SQL | **C++** |
| **R2** | Python + LLD + backend (conditional on R1) | Python |
| **R3** | Medium DSA + projects | C++ |
| **R4** | Easier DSA + behavioural | — |

R1 may include **non-DSA questions** (About me, SQL vs NoSQL) before/alongside coding.

---

## 90-second intro

> "I'm Ashutosh, backend engineer at Paytm on the Onboarding Engine team. We own enterprise merchant onboarding — I've built and maintained 20-plus production workflows in Java, Spring Boot, and AWS.
>
> My strongest win: high-traffic APIs with over a lakh weekly hits each. I used Kibana and Grafana to trace bottlenecks and applied intelligent Redis caching that cut response time by over 98 percent.
>
> Recently I built MCP servers connecting our databases, log stores, and internal docs to AI tooling — pushing test coverage past 90 percent and reducing defects across the SDLC.
>
> I'm excited about Adobe Document Cloud because it's high-scale backend work at the intersection of GenAI, document retrieval, and MCP — exactly where I want to grow."

---

## Story 1: 98% API optimization ⭐⭐

| STAR | Content |
|------|---------|
| **S** | APIs with 1L+ weekly hits; slow responses hurting merchant funnel |
| **T** | Find bottleneck, reduce latency without breaking correctness |
| **A** | Kibana/Grafana → hot paths → Redis cache-aside → event invalidation + TTL → load test → gradual rollout |
| **R** | **98%+ p95 latency reduction** |

**Follow-ups — know cold:**
- Bottleneck: repeated DB reads for stable onboarding config (N+1 / hot read paths)
- Pattern: **cache-aside** (check cache → miss → DB → populate)
- Invalidation: merchant update events + TTL fallback
- Cache down: degraded perf, not failure (requests hit DB)
- Stampede: lock on rebuild / request coalescing
- Measured: p95 before/after in Grafana

**Adobe bridge:** Same pattern for embedding caches or RAG retrieval result caches.

---

## Story 2: 20+ onboarding workflows ⭐

| STAR | Content |
|------|---------|
| **S** | Enterprise merchants need multi-step onboarding/modification |
| **T** | Design, build, maintain with product, frontend, QA |
| **A** | Spring Boot microservices, modular handlers, cross-functional delivery |
| **R** | 20+ production workflows, high ownership |

**Patterns:** Strategy, Factory, Repository, Template Method  
**Deep-dive:** idempotency on retries, workflow state persistence, API/event triggers

---

## Story 3: MCP servers ⭐⭐ (Adobe JD match)

### Problem
AI tools (Cursor, Copilot) generated code with **zero context** about our DB schema, logs, or internal docs. Devs spent 5–10 min on schema lookups, 15+ min on Kibana searches.

### What you built
**3 MCP tools** (Python FastAPI, read-only, SSO auth, < 2s latency):

| Tool | Does | Optimization |
|------|------|--------------|
| **DB Schema** | Table structure, indexes, FKs via read replica | Redis cache, 6hr TTL |
| **Log Search** | Recent errors from Kibana/ES | Filtered query, truncate for LLM context |
| **Docs Search** | RAG over Confluence | 512-token chunks, 10% overlap, FAISS |

### Architecture
```
Cursor/Copilot → MCP Protocol → FastAPI server → MySQL replica / Kibana / FAISS
                                      ↓
                                   Redis cache
```

### Results (memorize)

| Metric | Before | After |
|--------|--------|-------|
| Schema lookup | 5–10 min | < 100ms |
| Log search | 15 min | < 2s |
| Test coverage | 85% | 92% |
| Code review/PR | 45 min | 28 min |
| Daily tool calls | 0 | 200+ |

### Drill-down answers

**Why MCP not custom API?** Standard protocol — any LLM host discovers tools via schema. Custom API = per-tool integration.

**Latency?** Redis cache for schema; 5s timeout on logs; truncate results for LLM context window.

**Security?** SSO tokens, read-only, PII tables deny-listed, scoped per team.

**RAG chunking?** 512 tokens, 10% overlap, nightly re-index.

**Paytm → Adobe bridge:** Internal dev MCP (you) vs product Acrobat MCP (PDF tools for agents). Same protocol — tool schema, auth, latency — Adobe adds compliance, sandboxing, global scale.

---

## Story 4: Notification service migration ⭐

Legacy service → new internal + third-party APIs. Feature flags, dual-write, mapped use cases, clean deprecation.

**Use for:** distributed systems, rollback, reliability.

---

## Story 5–8 (short)

| # | Story | Use for |
|---|-------|---------|
| 5 | Third-party API integrations — retries, timeouts, idempotency | Integration design |
| 6 | Cross-functional delivery with product/FE/QA | Conflict, ambiguity |
| 7 | Wyse internship — Python/Django/MongoDB/Firebase | Python backend cred |
| 8 | Failure story — edge cases / migration hiccup | Honest failure + learning |

---

## Behavioural quick hits

| Question | Story |
|----------|-------|
| Biggest challenge | Story 1 (98%) |
| Innovation | Story 3 (MCP) |
| Conflict | Story 6 |
| Failure | Story 8 |
| Strength | Production ownership + measurable impact |
| Weakness | Java depth > Python — closing gap |

---

## Why Adobe / Why leave Paytm

**Adobe:** Document intelligence at scale · GenAI + backend infra · RAG/MCP product work · quality engineering  
**Leave:** Growth into user-facing GenAI backend — not negative about Paytm

---

## Design patterns from your work (R2)

| Pattern | Paytm example |
|---------|---------------|
| Strategy | Workflow handler per type |
| Factory | Executor by merchant category |
| Repository | Spring Data / MySQL |
| Observer | Events on workflow state change |

---

## Gap framing

| Gap | Answer |
|-----|--------|
| Python vs Java | Django shipped; same OOP thinking; interview fluency improving |
| No prod RAG | Built MCP + docs RAG internally; eager to go deep at Adobe |
| ML Ops title | Backend/platform for ML services — caching, APIs, ingestion, reliability |
