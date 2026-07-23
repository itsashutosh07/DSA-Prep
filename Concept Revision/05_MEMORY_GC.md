# 💾 MEMORY & GARBAGE COLLECTION

[← Back](./README.md) | **⏱️ 10 minutes**

---

## 🗺️ MEMORY AREAS

**JVM divides memory into 5 areas (Mnemonic: H-S-M-P-N)**

### Key Points
- **Heap**: All objects, shared across threads, GC managed
- **Stack**: Local variables, method calls, thread-specific, LIFO
- **Metaspace**: Class metadata, replaces PermGen (Java 8+), native memory
- **PC Register**: Current instruction address, thread-specific
- **Native Stack**: Native method calls (JNI), thread-specific

| Area | Stores | Scope |
|------|--------|-------|
| **Heap** | Objects | Shared |
| **Stack** | Local vars, method calls | Thread-specific |
| **Metaspace** | Class metadata | Shared |
| **PC Register** | Current instruction | Thread-specific |
| **Native Stack** | Native methods | Thread-specific |

---

## 📚 STACK VS HEAP

**Two primary memory areas with different characteristics and purposes**

### Key Points
- **Stack**: LIFO, fast access, fixed size, automatic cleanup (method returns)
- **Heap**: Dynamic allocation, slower, GC managed, shared across threads
- **Reference**: Object reference on Stack, actual object on Heap
- **StackOverflowError**: Deep/infinite recursion
- **OutOfMemoryError**: Heap exhausted (memory leak, large objects)

| Feature | Stack | Heap |
|---------|-------|------|
| **Stores** | Local vars | Objects |
| **Speed** | ⚡ Fast | Slower |
| **Size** | Small (MB) | Large (GB) |
| **Error** | StackOverflowError | OutOfMemoryError |
| **Lifetime** | Method scope | Until GC |

### Example
```java
void method() {
    int x = 10;          // Stack
    User u = new User(); // u (reference) on Stack, User object on Heap
}
```

---

## 🗑️ HEAP STRUCTURE

**Heap divided into generations based on object age (Generational Hypothesis: most objects die young)**

### Key Points
- **Young Gen (1/3)**: New objects, frequent Minor GC, fast
- **Old Gen (2/3)**: Long-lived objects, infrequent Major GC, slow
- **Eden (8/10 of Young)**: All new objects created here
- **Survivor (S0, S1)**: Objects surviving Minor GC, one always empty
- **Promotion**: After ~15 Minor GCs, object moves to Old Gen

```
Heap
├── Young Generation (1/3)
│   ├── Eden (8/10) ← New objects
│   ├── S0 (1/10)
│   └── S1 (1/10)
└── Old Generation (2/3) ← Long-lived objects

Metaspace (outside heap, native memory)
```

---

## ♻️ GC PROCESS

**Automatic memory management that reclaims unused objects**

### Key Points
- **Minor GC**: Cleans Young Gen, fast (ms), frequent
- **Major GC**: Cleans Old Gen, slow (seconds), infrequent
- **Full GC**: Cleans entire heap, very slow (STW - Stop The World)
- **Mark & Sweep**: Mark reachable → Sweep unreachable
- **Compaction**: Defragment memory (prevent fragmentation)

### Flow
```
1. New objects → Eden
2. Eden full → Minor GC → Survivors → S0
3. Next Minor GC → S0 ⇄ S1 (swap, one always empty)
4. After ~15 cycles → Old Generation (promotion)
5. Old full → Major GC (slow)
```

---

## 🎯 GC TYPES

**Different GC algorithms optimized for different scenarios**

### Key Points
- **Serial**: Single-threaded, small apps (<100MB heap)
- **Parallel**: Multi-threaded, high throughput, batch jobs
- **G1**: Default (Java 9+), predictable pause times, general purpose
- **ZGC**: Ultra-low latency (<10ms), large heaps (TB+)

| Type | Description | Use Case |
|------|-------------|----------|
| **Serial** | Single-threaded | Small apps |
| **Parallel** | Multi-threaded | Batch processing |
| **G1** | Default Java 9+ | Most apps ✅ |
| **ZGC** | <10ms pause | Large heaps |

### G1 GC (Most Important!)
**Garbage-First: Collects regions with most garbage first**

- Divides heap into ~2048 regions
- Predictable pause times (default target: 200ms)
- Concurrent marking (app runs during GC)
- Compaction (prevents fragmentation)

```bash
java -XX:+UseG1GC -XX:MaxGCPauseMillis=200 -Xmx4g MyApp
```

---

## 🎯 WHEN OBJECT ELIGIBLE FOR GC?

**Object is eligible when no live thread can access it**

### Key Points
- **Nullifying**: Set reference to null
- **Reassignment**: Assign reference to new object
- **Method ends**: Local references go out of scope
- **Island of isolation**: Circular references with no external reference
- **System.gc()**: Request GC (not guaranteed), avoid in production

```java
// 1. No references
User u = new User();
u = null; // Eligible

// 2. Reference reassigned
User u1 = new User();
u1 = new User(); // First object eligible

// 3. Method ends
void method() {
    User u = new User();
} // u eligible after method

// 4. Island of isolation
Node n1 = new Node(), n2 = new Node();
n1.next = n2; n2.next = n1;
n1 = null; n2 = null; // Both eligible
```

---

## ⚙️ JVM PARAMETERS

**Command-line flags to tune JVM performance**

### Key Points
- **-Xms**: Initial heap size (start large to avoid resizing)
- **-Xmx**: Maximum heap size (production: set equal to Xms)
- **-Xss**: Stack size per thread (default ~1MB)
- **-XX:+UseG1GC**: Enable G1 GC (default Java 9+)
- **-XX:MaxGCPauseMillis**: Target pause time (default 200ms)

```bash
# Heap size
-Xms2g          # Initial heap
-Xmx4g          # Max heap (production: -Xms4g -Xmx4g)

# Stack size
-Xss1m          # Stack per thread

# GC selection
-XX:+UseG1GC
-XX:+UseZGC

# GC logging
-Xlog:gc*:file=gc.log
```

---

## 🎯 INTERVIEW QUESTIONS

**Q: Stack vs Heap?**
- Stack: Local vars, thread-specific, fast, LIFO
- Heap: Objects, shared, GC managed

**Q: When StackOverflowError?**
- Infinite/deep recursion
- Solution: Base case, increase stack `-Xss2m`

**Q: When OutOfMemoryError?**
- Heap exhausted
- Solution: Increase heap `-Xmx4g`, fix memory leaks

**Q: What is Minor GC?**
- Cleans Young Generation
- Fast (milliseconds), frequent

**Q: What is G1 GC?**
- Default Java 9+
- Divides heap into regions
- Predictable pause times

**Q: How to detect memory leak?**
- Heap dump (jmap)
- Monitor heap usage over time
- VisualVM, JProfiler

---

## ⚠️ COMMON MISTAKES

```java
// ❌ Infinite recursion
void method() {
    method(); // StackOverflowError
}

// ❌ Memory leak (static collection)
static List<Object> list = new ArrayList<>();
void method() {
    list.add(new Object()); // Never removed
}

// ❌ Unclosed resources
Connection conn = getConnection();
// ... forgot to close
```

---

## 💡 QUICK WINS

**Always mention:**
- Stack for local vars, Heap for objects
- Young Gen (Eden, S0, S1) → Old Gen
- G1 GC is default (Java 9+)
- Minor GC fast, Major GC slow

**Impress interviewer:**
- Know G1 GC phases
- Mention ZGC for low latency
- Understand replication lag
- Discuss JVM tuning parameters

---

[← Previous: Java Fundamentals](./03_JAVA_FUNDAMENTALS.md) | [Back](./README.md) | [Next: Design Patterns →](./06_DESIGN_PATTERNS.md)
