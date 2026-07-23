# R2 — Python, LLD & Backend

**Prev:** [02-dsa-cpp.md](./02-dsa-cpp.md) · **Next:** [04-rag-mcp-genai.md](./04-rag-mcp-genai.md)  
**Code:** [`code/r2-python.py`](./code/r2-python.py)

R2 = Python concepts + basic design + backend verbal. **Make-or-break if you reach it.**

---

## Python essentials

| Topic | Key point |
|-------|-----------|
| list vs tuple | mutable vs immutable |
| dict / set | O(1) avg; keys must be hashable |
| `[[]]*3` trap | Three refs to same list |
| default mutable args | Never `def f(x=[])` |
| `is` vs `==` | identity vs equality |
| `*args` / `**kwargs` | variadic functions |
| generators | `yield` — lazy, memory-efficient |
| decorators | Always `@functools.wraps(fn)` |
| `@classmethod` vs `@staticmethod` | class-bound vs independent |
| context managers | `with` / `__enter__`/`__exit__` |

---

## GIL, threading, multiprocessing, async

| Term | Meaning |
|------|---------|
| **I/O bound** | Waiting on network/disk/DB — CPU idle |
| **CPU bound** | Heavy computation — CPU is bottleneck |

| Work type | Use | Why |
|-----------|-----|-----|
| I/O bound | `threading` or `asyncio` | Threads release GIL while waiting |
| CPU bound | `multiprocessing` | Bypass GIL with separate processes |
| Many HTTP/DB calls | `async/await` FastAPI | Efficient concurrent I/O |

**One-liner:** GIL = one thread runs Python bytecode at a time. Threads help I/O, not CPU-heavy Python loops.

---

## Java → Python (your stack)

| Java | Python |
|------|--------|
| HashMap | dict |
| ArrayList | list |
| PriorityQueue | heapq |
| synchronized | threading.Lock |
| Spring @Service | module/class + DI |
| Redis (Jedis) | redis-py |

---

## LLD framework

1. Functional + non-functional requirements (QPS, latency)
2. Entities (nouns)
3. APIs (verbs)
4. 3–5 components
5. Python code sketch (hot path)
6. Trade-offs (cache, failure, scale)

---

## Tier 1 designs (code from memory)

### LRU Cache ⭐

```python
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
```

**Tie to Story 1:** Same eviction thinking as Redis LRU at Paytm.

### Rate Limiter ⭐

Sliding window (`deque` of timestamps) or token bucket. Distributed: Redis INCR + EXPIRE.

### Document Ingestion ⭐ (role-aligned)

Upload → queue → parse → chunk → embed → vector store. Return `job_id`, 202 Accepted. Async workers.

### MCP Tool Registry ⭐

Decorator registers tools; schema for discovery; invoke by name. Tie to Story 3.

---

## Tier 2 designs (verbal OK)

URL Shortener · Notification System · File Upload · Notes API · Workflow Engine

---

## Backend fundamentals

### Caching ⭐ (they drill your 98% story)

| Pattern | One-liner |
|---------|-----------|
| Cache-aside | Read cache → miss → DB → populate |
| Write-through | Write cache + DB together |
| Write-back | Write cache, async flush to DB |
| TTL | Auto-expire stale entries |
| Eviction | LRU, LFU when full |
| Stampede | Lock / coalesce on cache miss rebuild |
| Invalidation | Event-driven purge + TTL fallback |

### Database

| Topic | Know |
|-------|------|
| Indexing | B-tree; leftmost prefix; write cost |
| Normalization | 3NF; denormalize for read-heavy |
| ACID | Atomicity, Consistency, Isolation, Durability |
| Isolation | RU → RC → RR → Serializable |
| Locking | Optimistic (version col) vs pessimistic (SELECT FOR UPDATE) |
| SQL vs NoSQL | See [06-actual-interview-debrief.md](./06-actual-interview-debrief.md) — **asked in your R1** |

### API design

| Topic | Answer |
|-------|--------|
| Pagination | Cursor > offset at scale |
| Rate limit | Token bucket; 429 + Retry-After |
| Idempotency | Idempotency-Key header; store hash + result |
| Retries | Exponential backoff + jitter; 5xx/timeout only |
| Auth | OAuth2 bearer / JWT |
| Status codes | 200, 201, 400, 401, 403, 404, 409, 429, 500 |

### Scalability

Load balancer · horizontal scaling · stateless services · message queues · async workers · observability (Kibana/Grafana)

### Concurrency

Race conditions · deadlocks · `threading.Lock` · I/O → async, CPU → multiprocessing

---

## Live coding prompts (R2)

LRU Cache · Rate limiter · `@retry` decorator · Thread-safe counter · MCP tool registry

Full implementations: [`code/r2-python.py`](./code/r2-python.py)

---

## Verbal Q&A (practice out loud)

**Caching:** "100k+ weekly hits, Kibana traced hot paths, cache-aside Redis, event invalidation + TTL, 98% p95 cut."

**Idempotency:** "Idempotency-Key in header, hash request, store result, retry returns cached."

**MCP:** "DB schema, log search, docs RAG via MCP protocol. Read-only SSO. Internal dev tools vs Adobe product MCP at scale."

**GIL:** "I/O-bound API server → asyncio. CPU-bound parsing → multiprocessing."

---

## Self-test

1. GIL — when do threads help?
2. Code LRU Cache from memory
3. Cache-aside vs write-through?
4. Why `[[]]*3` breaks?
5. Cursor vs offset pagination?
