# 🚀 CHEAT SHEET - Last Minute Revision

[← Back](./README.md) | **⏱️ 10 minutes**

---

## 🧠 MNEMONICS (Memorize These!)

| Topic | Mnemonic | Meaning |
|-------|----------|---------|
| **OOPS** | **A-PIE** | Abstraction, Polymorphism, Inheritance, Encapsulation |
| **SOLID** | **S-O-L-I-D** | Single Responsibility, Open/Closed, Liskov, Interface Segregation, Dependency Inversion |
| **ACID** | **A-C-I-D** | Atomicity, Consistency, Isolation, Durability |
| **CAP** | **C-A-P** | Consistency, Availability, Partition Tolerance (Pick 2) |
| **Memory** | **H-S-M-P-N** | Heap, Stack, Metaspace, PC Register, Native Stack |
| **Access** | **Pub-Pro-Pack-Pri** | Public, Protected, Package-private, Private |
| **Init Order** | **S-I-C** | Static → Instance → Constructor |
| **Generics** | **PECS** | Producer Extends, Consumer Super |

---

## ⚡ QUICK COMPARISONS

### String Types
```
String: Immutable, Thread-safe, Slow
StringBuilder: Mutable, Not thread-safe, Fast ✅
StringBuffer: Mutable, Thread-safe, Slower
```

### wait() vs sleep()
```
wait(): Releases lock, Object class, notify() wakes
sleep(): Keeps lock, Thread class, time wakes
```

### == vs equals()
```
==: Reference comparison
equals(): Content comparison
```

### Abstract Class vs Interface
```
Abstract: Can have constructor, concrete methods, single inheritance
Interface: No constructor, only abstract/default, multiple inheritance
```

---

## 🔢 IMPORTANT NUMBERS

```
Integer cache: -128 to 127
Default thread priority: 5 (range 1-10)
Default heap: 1/4 of RAM
Young:Old ratio: 1:2
Eden:Survivor: 8:1:1
```

---

## 💾 DATA TYPES

| Type | Size | Range |
|------|------|-------|
| byte | 8 bit | -128 to 127 |
| int | 32 bit | -2³¹ to 2³¹-1 |
| long | 64 bit | -2⁶³ to 2⁶³-1 |

---

## 🧵 CONCURRENCY

### Thread Creation
```java
// Preferred
Thread t = new Thread(() -> { /* task */ });
t.start(); // NOT run()
```

### Synchronization
```java
// Method
public synchronized void method() { }

// Block (better)
synchronized (lock) { /* critical section */ }
```

### Volatile
```java
private volatile boolean flag = true; // Visibility guarantee
```

### ExecutorService
```java
ExecutorService executor = Executors.newFixedThreadPool(10);
executor.submit(() -> { /* task */ });
executor.shutdown();
```

---

## 🎨 DESIGN PATTERNS

### Singleton (Enum - Best)
```java
enum Singleton { INSTANCE; }
```

### Factory
```java
Shape shape = ShapeFactory.getShape("CIRCLE");
```

### Builder
```java
User user = new User.Builder("name", "email").age(25).build();
```

### Strategy
```java
context.setStrategy(new ConcreteStrategy());
```

---

## 🗄️ DATABASE

### Indexing
```sql
CREATE INDEX idx_email ON users(email);
-- Use for: WHERE, JOIN, ORDER BY
-- Avoid for: Low cardinality, frequent writes
```

### Transaction
```sql
BEGIN TRANSACTION;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
COMMIT; -- or ROLLBACK;
```

### Isolation Levels
```
Read Uncommitted < Read Committed < Repeatable Read < Serializable
(Fastest)                                              (Slowest)
```

---

## 🌐 SYSTEM DESIGN

### Caching
```
Cache-Aside: App manages cache
Write-Through: Update cache on write
Write-Behind: Async write to DB
```

### Replication
```
Primary (Write) → Replica 1, 2, 3 (Read)
```

### Sharding
```
Hash-based: shard = hash(key) % N
Range-based: Shard 1 (A-M), Shard 2 (N-Z)
```

### CAP Theorem
```
CP: MongoDB, HBase (Consistency + Partition)
AP: Cassandra, DynamoDB (Availability + Partition)
```

### Latency Percentiles
```
p50 = Median (50% faster)
p95 = 95% faster (only 5% slower)
p99 = 99% faster (only 1% slower)

Rule: Monitor p95/p99, not average
Memory Hook: Average lies, p95 shows stress, p99 shows pain
```

---

## 🍃 SPRING BOOT

### Annotations
```java
@RestController + @RequestMapping("/api/users")
@GetMapping("/{id}") + @PathVariable
@PostMapping + @RequestBody
@Service + @Autowired (constructor injection)
@Transactional
```

### HTTP Status
```
200 OK, 201 Created, 204 No Content
400 Bad Request, 401 Unauthorized, 404 Not Found
500 Internal Server Error, 503 Service Unavailable
```

---

## 🐳 DEVOPS

### Docker
```bash
docker build -t myapp:1.0 .
docker run -d -p 8080:8080 myapp:1.0
docker logs -f myapp
```

### Kubernetes
```bash
kubectl apply -f deployment.yaml
kubectl get pods
kubectl logs pod-name
kubectl scale deployment myapp --replicas=5
```

---

## ⚠️ COMMON MISTAKES

```java
// ❌ String concatenation in loop
String s = ""; for(int i=0; i<1000; i++) s += i;

// ✅ Use StringBuilder
StringBuilder sb = new StringBuilder();

// ❌ Wrapper comparison with ==
Integer a = 128; Integer b = 128; if(a == b) // false!

// ✅ Use equals()
if(a.equals(b)) // true

// ❌ Calling run() instead of start()
thread.run(); // Same thread

// ✅ Call start()
thread.start(); // New thread

// ❌ volatile for count++
private volatile int count; count++; // Not atomic!

// ✅ Use AtomicInteger
AtomicInteger count = new AtomicInteger(0);
```

---

## 🎯 INTERVIEW MANTRAS

1. **Ask clarifying questions** - Don't assume
2. **Think out loud** - Show your process
3. **Start simple** - Optimize later
4. **Test your code** - Walk through examples
5. **Discuss trade-offs** - Every choice has pros/cons
6. **Be honest** - "I don't know" is OK

---

## 🔥 LAST 5 MINUTES

**Breathe. You know this.**

- JVM: JDK → JRE → JVM
- OOPS: A-PIE
- SOLID: All 5 principles
- Threads: start() not run()
- Sync: synchronized or Lock
- GC: Eden → S0/S1 → Old
- Index: Faster SELECT, slower INSERT
- CAP: Pick 2 of 3
- Spring: Constructor injection
- HTTP: 2xx success, 4xx client, 5xx server

**You've got this! 💪**

[← Back](./README.md)
