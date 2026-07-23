# RAG, Embeddings & MCP — Role Domain

**Prev:** [03-r2-python-lld-backend.md](./03-r2-python-lld-backend.md) · **Next:** [05-prep-checklists.md](./05-prep-checklists.md)

Engineering intuition only — not research ML. Pairs with Story 3 (MCP).

---

## RAG pipeline

```
Document → Parse → Chunk → Embed → Vector Store
                                      ↓
Query → Embed → Top-k retrieve → (Rerank) → Prompt + Context → LLM → Response
```

---

## Key terms

| Term | One-liner |
|------|-----------|
| Embedding | Dense vector; similar meaning → nearby |
| Chunking | 512–1024 tokens; 10–20% overlap |
| Top-k | k nearest chunks by cosine similarity |
| Hybrid search | BM25 (keyword) + vector (semantic) |
| Reranker | Cross-encoder rescores pairs — slower, sharper |
| Grounding | Answer only from retrieved context |
| Context window | Max tokens LLM accepts |
| MCP | LLM host ↔ tool server protocol (stdio/HTTP) |

---

## Hallucination reduction

| Technique | How |
|-----------|-----|
| Retrieval grounding | Constrain to retrieved chunks |
| Citations | Return page/section refs |
| Prompt constraints | "If not in context, say you don't know" |
| Lower temperature | Factual Q&A |
| Reranking | Better chunks → less fabrication |

---

## MCP — Paytm → Adobe

| | You (Paytm) | Adobe |
|---|-------------|-------|
| Purpose | Dev productivity | Product — PDF tools for agents |
| Tools | DB schema, logs, docs | `read_page`, `search_document`, `summarize` |
| Security | Internal SSO, read-only | OAuth, sandboxing, compliance, global scale |
| Scale | 200 calls/day | 100K+ calls/day |

**Say:** "I've built MCP servers internally. Acrobat MCP is that pattern at product scale."

---

## Design sketches

**Chat with PDF:** S3 → queue → extract → chunk → embed → vector DB. Query: embed → top-k → rerank → stream + citations.

**Acrobat MCP:** Tools: `read_page`, `search_document`, `summarize_range`, `extract_tables`. Auth: OAuth scoped to user files. Audit log.

**Your strengths to mention:** Cache by content hash · async workers · rate limits · Grafana metrics · 98% latency story applies to retrieval caching.

---

## Trade-offs

| Choice | Pros | Cons |
|--------|------|------|
| Small chunks | Precise retrieval | Loses context |
| Large chunks | More context | Noisy embeddings |
| Async ingest | Scalable | Stale until indexed |
| Reranker | Better precision | +100–300ms latency |

---

## Gap framing

> "I haven't shipped production vector search at Paytm scale, but I built MCP tooling and docs RAG internally, and I've optimized high-traffic retrieval with caching. The ingestion → index → query pipeline is where I want to go deep — that's Document Cloud."
