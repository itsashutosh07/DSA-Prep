# 🌐 SYSTEM DESIGN BASICS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 💾 CACHING

**Store frequently accessed data in fast storage (Redis) to reduce DB load and latency**

### Key Points
- **Purpose**: Reduce latency (ms → μs), reduce DB load, improve throughput
- **Eviction**: LRU (most common), LFU, FIFO, TTL
- **Cache-Aside**: App manages cache (most common)
- **Write-Through**: Update cache + DB synchronously (consistency)
- **Write-Behind**: Update cache, async DB write (performance)
- **Cache Stampede**: Many requests hit DB when cache expires (use locking)

### Cache-Aside Pattern (Most Common)
```java
User user = cache.get(id);
if (user == null) {
    user = db.get(id);
    cache.set(id, user, TTL);
}
return user;
```

### Cache Stampede Solution
**Problem: Cache expires, 1000 requests hit DB simultaneously**

```java
synchronized (key.intern()) {
    user = cache.get(id); // Double-check
    if (user == null) {
        user = db.get(id);
        cache.set(id, user);
    }
}
```

---

## 🔄 REPLICATION

**Copy data across multiple servers for scalability and availability**

### Primary-Replica (Most Common)
**One primary (writes), multiple replicas (reads)**

### Key Points
- **Purpose**: Scale reads, high availability, disaster recovery
- **Primary**: Handles all writes
- **Replicas**: Handle reads (3-5 replicas typical)
- **Replication Lag**: Replicas may be seconds behind (eventual consistency)
- **Failover**: If primary fails, promote replica to primary
- **Use for**: Read-heavy workloads (90% reads)

```
Primary (Write)
    ↓
Replica 1, 2, 3 (Read)
```

---

## 🗂️ SHARDING

**Horizontal partitioning: split data across multiple databases for massive scale**

### Key Points
- **Purpose**: Scale writes, handle massive data (TB+)
- **Shard Key**: Determines which shard stores data (critical choice)
- **Trade-offs**: Complexity, cross-shard queries hard, rebalancing difficult
- **When**: Single DB can't handle load (>10M rows, >1000 writes/sec)

### Strategies

**Hash-Based (Most Common)**
```java
int shard = hash(userId) % numShards;
```
- ✅ Even distribution
- ❌ Range queries hard, rebalancing requires rehashing

**Range-Based**
```
Shard 1: Users 1-1M
Shard 2: Users 1M-2M
```
- ✅ Range queries easy
- ❌ Hotspots (new users always on last shard)

**Geographic**
```
Shard 1: US users
Shard 2: EU users
```
- ✅ Low latency (data near users)
- ❌ Uneven distribution

---

## 🎯 CONSISTENT HASHING

**Distribute data across nodes such that adding/removing nodes affects minimal keys**

### Key Points
- **Problem**: Normal hashing (hash % N) requires rehashing all keys when N changes
- **Solution**: Hash ring (0 to 2³²-1), only neighboring keys affected
- **Virtual nodes**: Each physical node gets multiple positions (better distribution)
- **Used in**: Cassandra, DynamoDB, Memcached, CDN
- **Benefit**: Minimal data movement when scaling

---

## ⚖️ CAP THEOREM

**Distributed systems can guarantee only 2 of 3: Consistency, Availability, Partition Tolerance**

### Key Points
- **Consistency**: All nodes see same data at same time
- **Availability**: Every request gets response (success/failure)
- **Partition Tolerance**: System works despite network failures
- **Reality**: P is mandatory (network failures inevitable), so choose **CP or AP**
- **CP**: Sacrifice availability for consistency (banking, inventory)
- **AP**: Sacrifice consistency for availability (social media, analytics)
- **BASE**: Alternative to ACID for AP systems (Basically Available, Soft state, Eventual consistency)

```
CP Systems: MongoDB, HBase, Redis (consistency critical)
AP Systems: Cassandra, DynamoDB, Couchbase (availability critical)
```

---

## ⚖️ LOAD BALANCING

**Distribute incoming traffic across multiple servers for scalability and availability**

### Key Points
- **Purpose**: Prevent single server overload, high availability, horizontal scaling
- **Health checks**: Remove unhealthy servers automatically
- **Layer 4 (TCP)**: Fast, simple, IP-based routing
- **Layer 7 (HTTP)**: Slower, can route by URL/headers/cookies
- **Tools**: Nginx, HAProxy, AWS ELB, Kubernetes Service

### Algorithms
- **Round Robin**: Rotate through servers (simple, fair)
- **Least Connections**: Send to server with fewest active connections
- **IP Hash**: Same client → same server (session affinity)
- **Weighted**: Based on server capacity (2x CPU → 2x weight)

---

## 🔌 RATE LIMITING

**Restrict number of requests per user/IP to prevent abuse and ensure fair usage**

### Key Points
- **Purpose**: Prevent DDoS, API abuse, ensure fair usage, protect backend
- **Where**: API Gateway, application layer, load balancer
- **Common limits**: 100 req/min per user, 1000 req/hour per IP
- **Response**: 429 Too Many Requests

### Algorithms

**Token Bucket (Most Common)**
**Bucket holds tokens, refills at constant rate, request consumes token**
- Allows bursts (bucket can fill up)
- Used by: AWS, Stripe

```
Capacity: 100 tokens
Refill: 10 tokens/second
Request: Consumes 1 token
```

**Sliding Window (Redis)**
**Count requests in rolling time window**

```java
// Allow 100 requests per minute
long count = redis.zcount(key, now - 60000, now);
if (count < 100) {
    redis.zadd(key, now, requestId);
    return true;
}
return false; // 429 Too Many Requests
```

---

## 🔥 CIRCUIT BREAKER

**Prevent cascade failures by stopping calls to failing service (fail fast)**

### Key Points
- **Purpose**: Prevent cascade failures, fail fast, give service time to recover
- **States**: CLOSED (normal) → OPEN (failing) → HALF_OPEN (testing) → CLOSED
- **Threshold**: Open after N consecutive failures (e.g., 5)
- **Timeout**: Try again after T seconds (e.g., 30s)
- **Fallback**: Return default/cached response when open
- **Tools**: Resilience4j, Hystrix (deprecated)

### State Machine
```
CLOSED (normal operation)
  ↓ (failures exceed threshold)
OPEN (stop calling, return fallback)
  ↓ (after timeout)
HALF_OPEN (try limited requests)
  ↓ (success)          ↓ (failure)
CLOSED              OPEN
```

### Implementation
```java
@CircuitBreaker(name = "paymentService", fallbackMethod = "fallback")
public Payment process(Order order) {
    return paymentService.process(order);
}

public Payment fallback(Order order, Exception e) {
    return new Payment("PENDING"); // Fallback response
}
```

---

## 🌐 REST API

**Representational State Transfer: stateless, resource-based API design**

### Key Points
- **Stateless**: Each request independent (no session on server)
- **Resource-based**: URLs represent resources (nouns, not verbs)
- **HTTP methods**: GET (read), POST (create), PUT (update), DELETE (remove)
- **Idempotent**: Same request multiple times = same result (GET, PUT, DELETE)
- **Status codes**: 2xx (success), 4xx (client error), 5xx (server error)

| Method | Purpose | Idempotent |
|--------|---------|------------|
| GET | Retrieve | ✅ |
| POST | Create | ❌ |
| PUT | Update (full) | ✅ |
| PATCH | Update (partial) | ❌ |
| DELETE | Remove | ✅ |

### Status Codes
```
2xx: Success (200 OK, 201 Created, 204 No Content)
4xx: Client Error (400 Bad Request, 401 Unauthorized, 404 Not Found, 429 Rate Limited)
5xx: Server Error (500 Internal, 503 Service Unavailable)
```

### API Design Best Practices
```
GET    /users          - List users
GET    /users/123      - Get user
POST   /users          - Create user
PUT    /users/123      - Update user (full)
PATCH  /users/123      - Update user (partial)
DELETE /users/123      - Delete user
```

---

## 🎯 SYSTEM DESIGN INTERVIEW FRAMEWORK

**Structured approach to tackle system design questions in 45 minutes**

### Key Points
- **Don't jump to solution**: Clarify requirements first
- **Think aloud**: Explain your reasoning
- **Discuss trade-offs**: No perfect solution, show you understand pros/cons
- **Start simple**: Basic design → identify bottlenecks → optimize
- **Ask questions**: Clarify scale, constraints, priorities

### 6-Step Framework

**Step 1: Requirements (5 min)**
- Functional: What features? (post, like, comment)
- Non-functional: Scale? Latency? Availability? Consistency?

**Step 2: Capacity Estimation (5 min)**
```
Users: 100M total, 10M DAU
Writes: 1M/day = 12 writes/sec (peak: 36 writes/sec)
Reads: 10M/day = 120 reads/sec (peak: 360 reads/sec)
Storage: 100GB/year
Bandwidth: 40MB/s
```

**Step 3: API Design (5 min)**
```
POST /api/posts
GET  /api/posts/{id}
POST /api/posts/{id}/like
```

**Step 4: Database Schema (5 min)**
```sql
CREATE TABLE posts (id, user_id, content, created_at);
CREATE INDEX idx_user_id ON posts(user_id);
```

**Step 5: High-Level Design (15 min)**
```
Client → CDN → Load Balancer → App Servers → Cache → Database
                                            → Message Queue
```

**Step 6: Deep Dive (15 min)**
- Caching strategy (what to cache, eviction)
- Database (replication, sharding)
- Scalability (bottlenecks, solutions)
- Trade-offs (consistency vs availability)

---

## 🎯 INTERVIEW QUESTIONS

**Q: How to handle high traffic?**
1. Load balancing
2. Caching (Redis)
3. Database replication
4. Horizontal scaling
5. CDN for static assets
6. Async processing (queues)

**Q: How to ensure high availability?**
1. Multiple instances
2. Load balancer with health checks
3. Database replication
4. Auto-healing (Kubernetes)
5. Multi-region deployment

**Q: What is cache stampede?**
- Cache expires, many requests hit DB
- Solution: Locking, probabilistic early expiration

**Q: Primary-Replica vs Primary-Primary?**
- Primary-Replica: One writer, many readers
- Primary-Primary: Multiple writers (conflict resolution needed)

**Q: When to use sharding?**
- Single DB can't handle load
- Data too large for one server
- Geographic distribution

**Q: CAP theorem in practice?**
- CP: Banking (consistency critical)
- AP: Social media (availability critical)

---

## ⚠️ COMMON MISTAKES

```
❌ Not asking about scale
❌ Jumping to solution without requirements
❌ Ignoring trade-offs
❌ Over-engineering for small scale
❌ Under-engineering for large scale
❌ Not discussing failure scenarios
```

---

## 💡 QUICK WINS

**Always mention:**
- Caching (Redis) for hot data
- Load balancing for distribution
- Replication for scalability
- Sharding for massive scale
- CAP theorem trade-offs

**Impress interviewer:**
- Discuss numbers (RPS, storage, latency percentiles)
- Mention p95/p99 instead of average latency
- Know consistent hashing
- Understand replication lag
- Discuss failure scenarios

---

## 🏗️ COMMON ARCHITECTURES

**Scale architecture based on user count and traffic**

### Key Points
- **Simple**: Single server, single DB (< 10K users)
- **Medium**: Load balancer, multiple servers, cache, DB replicas (< 1M users)
- **Large**: CDN, sharding, microservices, message queues (> 1M users)
- **Evolution**: Start simple, scale incrementally based on bottlenecks

### Simple App (< 10K users)
```
Client → Server → Database
```

### Medium App (< 1M users)
```
Client → LB → Servers (3+) → Cache → DB (Primary + Replicas)
```

### Large App (> 1M users)
```
Client → CDN → LB → Servers → Cache Cluster → DB (Sharded + Replicated)
                            → Message Queue
                            → Microservices
```

---

[← Previous: Database](./07_DATABASE.md) | [Back](./README.md) | [Next: Spring Boot →](./09_SPRING_BOOT.md)
