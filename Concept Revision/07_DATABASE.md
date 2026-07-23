# 🗄️ DATABASE ESSENTIALS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 📇 INDEXING

**Data structure that improves query speed (trade-off: faster SELECT, slower INSERT/UPDATE)**

### Key Points
- **Purpose**: Speed up WHERE, JOIN, ORDER BY queries
- **Structure**: B+ Tree (O(log N) search)
- **Trade-off**: Faster reads, slower writes (index must be updated)
- **Composite**: Multi-column index, left-most prefix rule
- **Cardinality**: High cardinality (unique values) = good for indexing

### When to Use
```
✅ Frequent WHERE, JOIN, ORDER BY
✅ High cardinality (email, username)
✅ Large tables (millions of rows)

❌ Small tables (<1000 rows)
❌ Frequent INSERT/UPDATE/DELETE
❌ Low cardinality (gender, boolean)
```

### Types
```sql
CREATE INDEX idx_email ON users(email);                    -- Single
CREATE INDEX idx_name ON users(last_name, first_name);     -- Composite
CREATE UNIQUE INDEX idx_username ON users(username);       -- Unique
```

### Composite Index Rule (Left-Most Prefix)
```sql
-- Index: (last_name, first_name, age)

-- ✅ Uses index
WHERE last_name = 'Smith'
WHERE last_name = 'Smith' AND first_name = 'John'

-- ❌ Doesn't use index (skips left-most)
WHERE first_name = 'John'
WHERE age = 25
```

---

## 🌳 B+ TREE

**Self-balancing tree structure optimized for disk-based storage (used by all major databases)**

### Key Points
- **Search**: O(log N) - very fast even for millions of rows
- **Range queries**: Efficient (leaf nodes linked as linked list)
- **High fanout**: Each node has many children (~100-200), reduces height
- **Disk-friendly**: Minimizes disk I/O (3-4 reads for millions of rows)
- **All data in leaves**: Internal nodes only store keys for navigation

```
Example: 1 million rows, fanout 100
Height = log₁₀₀(1,000,000) ≈ 3 disk reads
```

---

## 🔄 TRANSACTIONS (ACID)

**Group of operations that execute as single unit (all succeed or all fail)**

### Key Points
- **Atomicity**: All or nothing (rollback on failure)
- **Consistency**: DB remains in valid state (constraints enforced)
- **Isolation**: Concurrent transactions don't interfere
- **Durability**: Committed changes persist (even after crash)
- **Use for**: Money transfers, inventory updates, multi-step operations

### Example
```sql
BEGIN TRANSACTION;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;
COMMIT; -- Both succeed or both fail (atomicity)
```

---

## 🔒 ISOLATION LEVELS

**Control how concurrent transactions interact (trade-off: consistency vs performance)**

### Key Points
- **Read Uncommitted**: Fastest, allows all anomalies (rarely used)
- **Read Committed**: Default (PostgreSQL), prevents dirty reads
- **Repeatable Read**: MySQL default, prevents non-repeatable reads
- **Serializable**: Slowest, full isolation (locks)
- **Higher isolation = Lower performance**

| Level | Dirty Read | Non-Repeatable | Phantom |
|-------|-----------|----------------|---------|
| Read Uncommitted | ✅ | ✅ | ✅ |
| Read Committed | ❌ | ✅ | ✅ |
| Repeatable Read | ❌ | ❌ | ✅ |
| Serializable | ❌ | ❌ | ❌ |

### Concurrency Problems
- **Dirty Read**: Reading uncommitted data (T1 reads, T2 rollbacks)
- **Non-Repeatable Read**: Same query returns different result (T1 reads twice, T2 updates in between)
- **Phantom Read**: New rows appear (T1 reads twice, T2 inserts in between)

---

## 🔐 LOCKING

**Prevent concurrent access conflicts**

### Pessimistic Locking
**Lock immediately, assume conflicts will happen**
- Use for: High contention, critical operations (money transfer)
- Pros: Guaranteed consistency
- Cons: Reduced concurrency, potential deadlock

```sql
SELECT * FROM accounts WHERE id = 1 FOR UPDATE; -- Lock row
```

### Optimistic Locking
**Don't lock, check version before commit**
- Use for: Low contention, read-heavy workloads
- Pros: Better concurrency
- Cons: Retry logic needed

```sql
UPDATE accounts SET balance = 50, version = version + 1
WHERE id = 1 AND version = 5; -- Fails if version changed
```

---

## 📊 SQL VS NOSQL

**Two database paradigms with different trade-offs**

### Key Points
- **SQL**: Relational, structured, ACID, vertical scaling, complex queries
- **NoSQL**: Non-relational, flexible schema, BASE, horizontal scaling, high throughput
- **Use SQL**: Financial, complex relationships, strong consistency
- **Use NoSQL**: Rapid development, massive scale, flexible schema

| Feature | SQL | NoSQL |
|---------|-----|-------|
| Schema | Fixed | Flexible |
| Scaling | Vertical | Horizontal |
| Transactions | ACID | BASE |
| Joins | ✅ | ❌ |
| Use Case | Complex queries | High throughput |

---

## 🍃 NOSQL TYPES

**Four main NoSQL database types for different use cases**

### Key Points
- **Document (MongoDB)**: JSON-like, flexible schema, nested data
- **Key-Value (Redis)**: Fastest, simple get/set, caching
- **Column-Family (Cassandra)**: Wide-column, time-series, analytics
- **Graph (Neo4j)**: Relationships, social networks, recommendations

| Type | Example | Use Case |
|------|---------|----------|
| **Document** | MongoDB | Flexible schema, JSON |
| **Key-Value** | Redis | Caching, sessions |
| **Column** | Cassandra | Time-series, analytics |
| **Graph** | Neo4j | Social networks |

### MongoDB
**Document store with JSON-like documents**

```javascript
db.users.insertOne({ name: "Ashu", age: 25 });
db.users.find({ age: { $gt: 20 } });
db.users.updateOne({ name: "Ashu" }, { $set: { age: 26 } });
db.users.createIndex({ email: 1 });
```

### Redis
**In-memory key-value store (sub-millisecond latency)**

```bash
SET key "value"
GET key
SETEX session:123 3600 "data"  # Expires in 1 hour
HSET user:1 name "Ashu"        # Hash
ZADD leaderboard 100 "player1" # Sorted set (score-based)
```

---

## 🎯 INTERVIEW QUESTIONS

**Q: When to create index?**
- Frequent WHERE/JOIN/ORDER BY
- High cardinality
- Large tables

**Q: Why B+ tree for databases?**
- Fast search O(log N)
- Range queries (linked leaves)
- High fanout (fewer disk reads)

**Q: Explain ACID**
- Atomicity, Consistency, Isolation, Durability

**Q: What is dirty read?**
- Reading uncommitted data
- Prevented by Read Committed level

**Q: Pessimistic vs Optimistic locking?**
- Pessimistic: Lock immediately (high contention)
- Optimistic: Version check (low contention)

**Q: When MongoDB vs MySQL?**
- MongoDB: Flexible schema, rapid development
- MySQL: Complex queries, relationships, ACID

**Q: Redis use cases?**
- Caching, sessions, rate limiting, leaderboards

---

## ⚠️ COMMON MISTAKES

```sql
-- ❌ Function on indexed column
WHERE YEAR(created_at) = 2024

-- ✅ Range query
WHERE created_at >= '2024-01-01' AND created_at < '2025-01-01'

-- ❌ SELECT *
SELECT * FROM users

-- ✅ Select needed columns
SELECT id, name, email FROM users

-- ❌ N+1 in JPA
List<User> users = repo.findAll();
for (User u : users) u.getOrders(); // N queries

-- ✅ JOIN FETCH
@Query("SELECT u FROM User u LEFT JOIN FETCH u.orders")
```

---

## 💡 QUICK WINS

**Always mention:**
- Index trade-off: Faster SELECT, slower INSERT
- B+ tree for databases
- ACID for SQL, BASE for NoSQL
- Isolation levels (4 types)

**Impress interviewer:**
- Know composite index left-most rule
- Explain N+1 problem and solutions
- Discuss replication lag
- Mention consistent hashing

---

[← Previous: Memory & GC](./05_MEMORY_GC.md) | [Back](./README.md) | [Next: System Design →](./08_SYSTEM_DESIGN.md)
