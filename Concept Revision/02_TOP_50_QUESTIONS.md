# 🔥 TOP 50 QUESTIONS - Detailed Answers

[← Back](./README.md) | **⏱️ 20 minutes**

**Most frequently asked with complete answers**

---

## JAVA FUNDAMENTALS

### Q1. Explain JVM architecture

**Answer:**
```
JDK → JRE → JVM → OS

JVM Components:
1. Class Loader (loads .class files)
2. Runtime Data Areas (Heap, Stack, Metaspace)
3. Execution Engine (Interpreter + JIT Compiler)
4. Garbage Collector
```

**Why platform-independent?**
- Bytecode is platform-independent
- JVM is platform-specific

---

### Q2. Why is String immutable?

**Answer:**
1. **String Pool** - Safe sharing
2. **Security** - File paths, URLs can't be changed
3. **Thread-safe** - No synchronization needed
4. **Hashcode caching** - Safe for HashMap keys

---

### Q3. Difference between == and equals()?

**Answer:**
- `==`: Reference comparison (same object?)
- `equals()`: Content comparison (same value?)

```java
String s1 = "Hello";
String s2 = "Hello";
String s3 = new String("Hello");

s1 == s2;        // true (same reference in pool)
s1 == s3;        // false (different objects)
s1.equals(s3);   // true (same content)
```

---

### Q4. Abstract class vs Interface?

**Answer:**

| Feature | Abstract Class | Interface |
|---------|---------------|-----------|
| Constructor | ✅ Yes | ❌ No |
| Methods | Abstract + Concrete | Abstract + Default (Java 8+) |
| Inheritance | Single | Multiple |
| Use Case | IS-A + shared code | CAN-DO capability |

---

### Q5. Method overloading vs overriding?

**Answer:**

**Overloading (Compile-time):**
```java
int add(int a, int b) { }
double add(double a, double b) { }
```

**Overriding (Runtime):**
```java
class Parent { void show() { } }
class Child extends Parent { @Override void show() { } }
```

---

### Q6. Why doesn't Java support multiple inheritance?

**Answer:**
- **Diamond problem** - Ambiguity when two parents have same method
- Can achieve via interfaces (must resolve conflicts)

---

### Q7. What are generics? Why use them?

**Answer:**
- Type parameters for compile-time type safety
- No casting needed
- Prevents ClassCastException

```java
List<String> list = new ArrayList<>();
list.add("Hello");
String s = list.get(0); // No cast needed
```

---

### Q8. Explain `<? extends T>` vs `<? super T>`

**Answer:**
- `<? extends T>`: Upper bound, **read-only** (Producer)
- `<? super T>`: Lower bound, **write-only** (Consumer)
- **PECS**: Producer Extends, Consumer Super

---

### Q9. Checked vs Unchecked exceptions?

**Answer:**

| Type | Check Time | Must Handle? | Example |
|------|-----------|--------------|---------|
| Checked | Compile-time | ✅ Yes | IOException |
| Unchecked | Runtime | ❌ No | NullPointerException |

---

### Q10. What is try-with-resources?

**Answer:**
- Auto-closes resources (Java 7+)
- Must implement AutoCloseable

```java
try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
    String line = br.readLine();
} // Automatically closed
```

---

## CONCURRENCY

### Q11. How to create thread in Java?

**Answer:**

**Method 1: Extend Thread**
```java
class MyThread extends Thread {
    public void run() { }
}
new MyThread().start();
```

**Method 2: Implement Runnable (Preferred)**
```java
Thread t = new Thread(() -> { /* task */ });
t.start();
```

---

### Q12. Difference between start() and run()?

**Answer:**
- `start()`: Creates new thread, calls run()
- `run()`: Executes in same thread (no new thread)

---

### Q13. Difference between wait() and sleep()?

**Answer:**

| Feature | wait() | sleep() |
|---------|--------|---------|
| Class | Object | Thread |
| Lock | Releases | Keeps |
| Location | synchronized block | Anywhere |
| Wake up | notify() | Time expires |

---

### Q14. What is race condition?

**Answer:**
- Multiple threads access shared data, at least one writes
- Unpredictable results

```java
count++; // Not atomic: read → increment → write
```

**Solution:** synchronized, Lock, AtomicInteger

---

### Q15. What is synchronized keyword?

**Answer:**
- Ensures only one thread executes critical section
- Acquires lock on object/class

```java
public synchronized void method() { } // Locks 'this'
synchronized (lock) { } // Locks specific object
```

---

### Q16. What is deadlock?

**Answer:**
- Two threads waiting for each other indefinitely

```
T1 holds Lock1, waits for Lock2
T2 holds Lock2, waits for Lock1
```

**Prevention:** Lock ordering, timeout

---

### Q17. What is volatile keyword?

**Answer:**
- Prevents CPU caching (reads from main memory)
- Ensures visibility across threads
- **NOT atomic** - don't use for count++

**Use case:** Boolean flags, status variables

---

### Q18. volatile vs synchronized?

**Answer:**

| Feature | volatile | synchronized |
|---------|----------|--------------|
| Atomicity | ❌ | ✅ |
| Visibility | ✅ | ✅ |
| Locking | ❌ | ✅ |

---

### Q19. What is ExecutorService?

**Answer:**
- Thread pool management
- Reuse threads, better than creating manually

```java
ExecutorService executor = Executors.newFixedThreadPool(10);
executor.submit(() -> { /* task */ });
executor.shutdown();
```

---

### Q20. Callable vs Runnable?

**Answer:**

| Feature | Runnable | Callable |
|---------|----------|----------|
| Return value | ❌ No | ✅ Yes |
| Throws exception | ❌ No | ✅ Yes |

---

### Q21. What is CompletableFuture?

**Answer:**
- Async programming
- Chain operations

```java
CompletableFuture.supplyAsync(() -> "Hello")
    .thenApply(s -> s + " World")
    .thenAccept(System.out::println);
```

---

### Q22. What is ThreadLocal?

**Answer:**
- Thread-specific variable
- Each thread has own copy
- Use case: User context, transaction management

---

### Q23. What are atomic classes?

**Answer:**
- Lock-free thread-safe operations
- AtomicInteger, AtomicLong, AtomicBoolean
- CAS (Compare-And-Swap) operation

---

### Q24. What is ReentrantLock?

**Answer:**
- Explicit lock (vs synchronized)
- Features: tryLock(), timeout, fair lock, interruptible

---

### Q25. What is ReadWriteLock?

**Answer:**
- Multiple readers simultaneously
- Exclusive writer
- Better for read-heavy workloads

---

## MEMORY & GC

### Q26. Stack vs Heap?

**Answer:**

| Feature | Stack | Heap |
|---------|-------|------|
| Stores | Local vars, method calls | Objects |
| Scope | Thread-specific | Shared |
| Speed | ⚡ Fast | Slower |
| Error | StackOverflowError | OutOfMemoryError |

---

### Q27. Explain heap structure

**Answer:**
```
Heap
├── Young Generation
│   ├── Eden (new objects)
│   ├── S0 (survivor)
│   └── S1 (survivor)
└── Old Generation (long-lived objects)

Metaspace (outside heap)
```

---

### Q28. Minor GC vs Major GC?

**Answer:**
- **Minor GC**: Cleans Young Gen, fast (ms), frequent
- **Major GC**: Cleans Old Gen, slow (100ms+), rare

---

### Q29. When is object eligible for GC?

**Answer:**
1. No references: `obj = null`
2. Reference reassigned: `obj1 = obj2`
3. Method ends: Local objects
4. Island of isolation: Circular references

---

### Q30. What is G1 GC?

**Answer:**
- Garbage First (default Java 9+)
- Divides heap into regions
- Predictable pause times
- Collects most garbage first

---

## DESIGN PATTERNS

### Q31. Explain SOLID principles

**Answer:**
- **S**: Single Responsibility - One class, one job
- **O**: Open/Closed - Extend, not modify
- **L**: Liskov - Subclass behaves like parent
- **I**: Interface Segregation - Small interfaces
- **D**: Dependency Inversion - Depend on abstractions

---

### Q32. Implement thread-safe Singleton

**Answer:**

**Best: Enum**
```java
enum Singleton {
    INSTANCE;
    public void doSomething() { }
}
```

**Alternative: Bill Pugh**
```java
class Singleton {
    private Singleton() {}
    
    private static class Helper {
        private static final Singleton INSTANCE = new Singleton();
    }
    
    public static Singleton getInstance() {
        return Helper.INSTANCE;
    }
}
```

---

### Q33. When to use Factory pattern?

**Answer:**
- Hide object creation logic
- Loose coupling
- Create objects based on input

```java
Shape shape = ShapeFactory.getShape("CIRCLE");
```

---

### Q34. When to use Builder pattern?

**Answer:**
- Many optional parameters
- Immutable objects
- Readable construction

```java
User user = new User.Builder("name", "email")
    .age(25)
    .phone("123")
    .build();
```

---

### Q35. Explain Strategy pattern

**Answer:**
- Define family of algorithms
- Make them interchangeable
- Select at runtime

```java
ShoppingCart cart = new ShoppingCart();
cart.setPaymentStrategy(new CreditCardPayment());
cart.checkout(1000);
```

---

## DATABASE

### Q36. What is indexing? When to use?

**Answer:**
- Data structure for fast lookup (B+ tree)
- **Use:** Frequent WHERE, JOIN, ORDER BY, high cardinality
- **Avoid:** Small tables, frequent writes, low cardinality

**Trade-off:** Faster SELECT, slower INSERT/UPDATE

---

### Q37. Explain ACID properties

**Answer:**
- **A**tomicity: All or nothing
- **C**onsistency: Valid state always
- **I**solation: Transactions don't interfere
- **D**urability: Committed data persists

---

### Q38. What are isolation levels?

**Answer:**

| Level | Dirty Read | Non-Repeatable | Phantom |
|-------|-----------|----------------|---------|
| Read Uncommitted | ✅ | ✅ | ✅ |
| Read Committed | ❌ | ✅ | ✅ |
| Repeatable Read | ❌ | ❌ | ✅ |
| Serializable | ❌ | ❌ | ❌ |

---

### Q39. What is N+1 problem in JPA?

**Answer:**
- 1 query for parent, N queries for children (lazy loading)

**Solution:**
```java
@Query("SELECT u FROM User u LEFT JOIN FETCH u.orders")
List<User> findAllWithOrders();
```

---

### Q40. SQL vs NoSQL?

**Answer:**

| Feature | SQL | NoSQL |
|---------|-----|-------|
| Schema | Fixed | Flexible |
| Scaling | Vertical | Horizontal |
| Transactions | ACID | BASE |
| Joins | ✅ | ❌ |
| Use Case | Complex queries | High throughput |

---

## SYSTEM DESIGN

### Q41. Explain CAP theorem

**Answer:**
- Can only guarantee **2 out of 3**:
  - **C**onsistency
  - **A**vailability
  - **P**artition Tolerance

**Reality:** P is mandatory (network failures happen)

**Choice:**
- **CP**: MongoDB, HBase (consistency over availability)
- **AP**: Cassandra, DynamoDB (availability over consistency)

---

### Q42. What is caching? Strategies?

**Answer:**

**Eviction:**
- LRU (Least Recently Used) - Most common
- LFU (Least Frequently Used)
- FIFO, TTL

**Patterns:**
- **Cache-Aside**: App checks cache, loads from DB on miss
- **Write-Through**: Update cache + DB together
- **Write-Behind**: Update cache, async write to DB

---

### Q43. What is database replication?

**Answer:**
- Copy data across servers

**Primary-Replica:**
- Primary: Writes
- Replicas: Reads (load balancing)
- Replication lag possible

**Benefits:** Read scalability, high availability

---

### Q44. What is sharding?

**Answer:**
- Horizontal partitioning across multiple databases

**Strategies:**
- **Hash-based**: `shard = hash(key) % N`
- **Range-based**: Shard 1 (A-M), Shard 2 (N-Z)
- **Geographic**: By region

**Benefits:** Scale beyond single server

---

### Q45. What is consistent hashing?

**Answer:**
- Minimize data movement when adding/removing nodes
- Hash ring structure
- Only neighboring nodes affected

**Use case:** Distributed caches, load balancing

---

### Q46. What is load balancing?

**Answer:**
- Distribute traffic across servers

**Algorithms:**
- Round Robin (rotate)
- Least Connections (fewest active)
- IP Hash (session affinity)

---

### Q47. How to handle high traffic?

**Answer:**
1. **Load balancing** - Distribute requests
2. **Caching** - Redis for hot data
3. **Database replication** - Read replicas
4. **Horizontal scaling** - Add more servers
5. **CDN** - Static assets
6. **Async processing** - Message queues

---

### Q48. What is circuit breaker?

**Answer:**
- Prevent cascade failures
- **States:** Closed → Open → Half-Open

```
Closed: Normal operation
Open: Too many failures, stop calling service
Half-Open: Try again after timeout
```

---

### Q49. What is rate limiting?

**Answer:**
- Limit requests per user/IP
- Prevent abuse, ensure fair usage

**Algorithms:**
- Token Bucket
- Sliding Window

---

### Q50. Microservices vs Monolith?

**Answer:**

| Feature | Monolith | Microservices |
|---------|----------|---------------|
| Structure | Single app | Multiple services |
| Deployment | All together | Independent |
| Scaling | Scale entire app | Scale individual services |
| Complexity | Simple | Complex |
| Technology | Single stack | Polyglot |

---

## SPRING BOOT (Bonus 10)

### Q51. What is Dependency Injection?

**Answer:**
- Objects receive dependencies (not create them)
- Loose coupling, easy testing

```java
// ❌ Without DI
class Service {
    private Repo repo = new Repo(); // Tight coupling
}

// ✅ With DI
class Service {
    private final Repo repo;
    
    @Autowired
    public Service(Repo repo) {
        this.repo = repo;
    }
}
```

---

### Q52. Constructor vs Field injection?

**Answer:**

**Constructor (Recommended):**
```java
private final Repo repo;

@Autowired
public Service(Repo repo) {
    this.repo = repo;
}
```
- ✅ Immutable (final)
- ✅ Easy to test
- ✅ Required dependencies clear

**Field (Not Recommended):**
```java
@Autowired
private Repo repo;
```
- ❌ Hard to test
- ❌ Cannot be final

---

### Q53. @Component vs @Service vs @Repository?

**Answer:**
- `@Component`: Generic component
- `@Service`: Business logic layer
- `@Repository`: Data access layer (exception translation)

All are specializations of @Component

---

### Q54. What are bean scopes?

**Answer:**
- **singleton** (default): One per container
- **prototype**: New instance every time
- **request**: One per HTTP request
- **session**: One per HTTP session

---

### Q55. What is @Transactional?

**Answer:**
- Marks method as transactional
- Rollback on exception (unchecked by default)

```java
@Transactional
public void transfer(int from, int to, double amount) {
    debit(from, amount);
    credit(to, amount);
    // If any fails, both rollback
}
```

---

### Q56. What is N+1 problem?

**Answer:**
- 1 query for parent, N queries for children

```java
// ❌ Problem
List<User> users = userRepo.findAll(); // 1 query
for (User u : users) {
    u.getOrders(); // N queries (lazy loading)
}

// ✅ Solution
@Query("SELECT u FROM User u LEFT JOIN FETCH u.orders")
List<User> findAllWithOrders(); // 1 query
```

---

### Q57. EAGER vs LAZY loading?

**Answer:**
- **EAGER**: Load immediately (default for @ManyToOne)
- **LAZY**: Load on demand (default for @OneToMany)

Use LAZY for collections to avoid loading unnecessary data

---

### Q58. What is @RestController?

**Answer:**
- `@Controller` + `@ResponseBody`
- Returns data (JSON), not views

---

### Q59. @PathVariable vs @RequestParam?

**Answer:**
- `@PathVariable`: From URL path `/users/{id}`
- `@RequestParam`: From query string `/users?name=John`

---

### Q60. What is Spring Boot auto-configuration?

**Answer:**
- Automatically configures beans based on classpath
- Example: Finds H2 → Configures DataSource
- Can override with custom configuration

---

## MEMORY & GC (Bonus 5)

### Q61. Explain Java Memory Model

**Answer:**

**Memory Areas (H-S-M-P-N):**
- **Heap**: Objects (shared)
- **Stack**: Local vars (thread-specific)
- **Metaspace**: Class metadata
- **PC Register**: Current instruction
- **Native Stack**: Native methods

---

### Q62. What is garbage collection?

**Answer:**
- Automatic memory management
- Reclaims unused objects

**Process:**
```
Eden → S0 ⇄ S1 → Old Generation
```

---

### Q63. Types of GC?

**Answer:**
- **Serial**: Single-threaded (small apps)
- **Parallel**: Multi-threaded (batch processing)
- **G1**: Default Java 9+, predictable pauses
- **ZGC**: Ultra-low latency (<10ms)

---

### Q64. What is StackOverflowError?

**Answer:**
- Stack memory exhausted
- **Cause:** Infinite/deep recursion
- **Solution:** Add base case, increase stack size `-Xss2m`

---

### Q65. What is OutOfMemoryError?

**Answer:**
- Heap memory exhausted
- **Cause:** Memory leak, too many objects
- **Solution:** Increase heap `-Xmx4g`, fix leaks

---

## QUICK FIRE ROUND

**Q66. Default access modifier?** Package-private

**Q67. Can interface have constructor?** No

**Q68. Can we override static method?** No (hidden, not overridden)

**Q69. Can we override private method?** No (not inherited)

**Q70. Is String thread-safe?** Yes (immutable)

**Q71. Is StringBuilder thread-safe?** No

**Q72. Is HashMap thread-safe?** No (use ConcurrentHashMap)

**Q73. Is ArrayList thread-safe?** No (use CopyOnWriteArrayList)

**Q74. Default thread priority?** 5 (range 1-10)

**Q75. Can we start thread twice?** No (IllegalThreadStateException)

---

## 🎯 ANSWER STRATEGY

### For "Explain X" Questions

```
1. One-line definition
2. Why it's needed
3. Quick example
4. Trade-offs (if relevant)
```

### For "Difference" Questions

```
1. Define both briefly
2. Key differences (table)
3. When to use each
```

### For Coding Questions

```
1. Clarify requirements
2. Think out loud
3. Write clean code
4. Test with examples
5. Discuss complexity
```

---

## 💡 INTERVIEW MANTRAS

1. **"Let me clarify..."** - Ask questions
2. **"Let me think out loud..."** - Show process
3. **"Let me start simple..."** - Basic first
4. **"The trade-off is..."** - Discuss pros/cons
5. **"I'm not sure, but..."** - Be honest

---

**You're prepared! 🚀**

[← Back](./README.md) | [Next: Java Fundamentals →](./03_JAVA_FUNDAMENTALS.md)
