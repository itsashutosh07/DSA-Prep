# 🧵 CONCURRENCY ESSENTIALS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 🚀 THREAD BASICS

**Lightweight process that enables concurrent execution**

### Key Points
- **Creation**: Extend Thread OR implement Runnable (preferred)
- **start()**: Creates new thread, calls run()
- **run()**: Executes in same thread (no concurrency)
- **Lifecycle**: NEW → RUNNABLE → RUNNING → TERMINATED (with BLOCKED/WAITING states)
- **Why Runnable**: Allows extending other classes, better design

### Creation
```java
Thread t = new Thread(() -> {
    System.out.println(Thread.currentThread().getName());
});
t.start(); // ✅ New thread
// t.run(); // ❌ Same thread
```

---

## 🔒 SYNCHRONIZATION

**Prevents race conditions when multiple threads access shared data**

### Key Points
- **Race Condition**: Multiple threads modify shared variable, unpredictable result
- **synchronized method**: Locks entire object (this)
- **synchronized block**: Locks specific object (better granularity)
- **Atomic classes**: Lock-free, CAS-based (faster for simple operations)
- **Always use**: For shared mutable state

### Problem & Solutions
```java
// ❌ Race condition
class Counter {
    private int count = 0;
    public void increment() { count++; } // Not atomic
}

// ✅ Solution 1: synchronized
public synchronized void increment() { count++; }

// ✅ Solution 2: AtomicInteger (faster)
private AtomicInteger count = new AtomicInteger(0);
public void increment() { count.incrementAndGet(); }
```

---

## ⚡ WAIT VS SLEEP

**Both pause thread execution but differ in lock behavior**

### Key Points
- **wait()**: Releases lock, must be in synchronized block, woken by notify()/notifyAll()
- **sleep()**: Keeps lock, can be called anywhere, wakes after timeout
- **Use wait()**: Inter-thread communication (producer-consumer)
- **Use sleep()**: Delay execution

| Feature | wait() | sleep() |
|---------|--------|---------|
| Class | Object | Thread |
| Lock | Releases ✅ | Keeps ❌ |
| Location | synchronized only | Anywhere |
| Wake | notify() | Time expires |

```java
synchronized (lock) {
    lock.wait(); // Releases lock
}

Thread.sleep(1000); // Keeps lock
```

---

## 💀 DEADLOCK

**Two or more threads waiting for each other to release locks, causing infinite wait**

### Key Points
- **Conditions**: Mutual exclusion, hold & wait, no preemption, circular wait
- **Prevention**: Lock ordering, timeouts, avoid nested locks
- **Detection**: Thread dumps, monitoring tools

### Problem
```java
// Thread 1: lock1 → lock2
// Thread 2: lock2 → lock1
synchronized (lock1) {
    synchronized (lock2) { } // Deadlock!
}
```

### Prevention
1. **Lock ordering**: Always acquire locks in same order
2. **Timeout**: Use tryLock(timeout) instead of lock()
3. **Avoid nested locks**: Minimize lock scope

---

## 🌊 VOLATILE

**Ensures visibility of variable changes across threads (prevents CPU cache issues)**

### Key Points
- **Purpose**: Guarantees reads/writes go to main memory (not CPU cache)
- **Use for**: Boolean flags, status variables, single writer scenarios
- **NOT for**: Compound operations (count++), multiple writers
- **Prevents**: Instruction reordering, stale reads
- **Lighter than**: synchronized (no locking overhead)

### When to Use
```java
private volatile boolean running = true; // ✅ Flag
public void stop() { running = false; } // Visible to all
```

### When NOT to Use
```java
private volatile int count = 0;
public void increment() { count++; } // ❌ Not atomic
// Use AtomicInteger instead
```

---

## 🎯 EXECUTORSERVICE

**Thread pool framework that manages thread lifecycle and reuses threads for efficiency**

### Key Points
- **Why**: Avoid overhead of creating threads, control resource usage
- **Types**: Fixed (n threads), Cached (dynamic), Single (1 thread), Scheduled
- **Callable**: Returns result (vs Runnable)
- **Future**: Handle to async result (get() blocks until done)
- **Always shutdown**: executor.shutdown() to release resources

### Usage
```java
ExecutorService executor = Executors.newFixedThreadPool(10);

// Submit task
executor.submit(() -> {
    System.out.println("Task executed");
});

// Shutdown (important!)
executor.shutdown();
executor.awaitTermination(1, TimeUnit.MINUTES);
```

### Types
```java
newFixedThreadPool(10)     // Fixed 10 threads
newCachedThreadPool()      // Creates as needed
newSingleThreadExecutor()  // Single thread (sequential)
newScheduledThreadPool(5)  // Scheduled/periodic tasks
```

---

## 🔮 COMPLETABLEFUTURE

**Async programming with composable, non-blocking operations (Java 8+)**

### Key Points
- **supplyAsync()**: Returns value (uses ForkJoinPool)
- **thenApply()**: Transform result (sync)
- **thenApplyAsync()**: Transform in different thread
- **thenCombine()**: Combine two futures
- **exceptionally()**: Handle errors
- **Non-blocking**: Main thread continues, callback executes when ready

### Chaining
```java
CompletableFuture.supplyAsync(() -> "Hello")
    .thenApply(s -> s + " World")
    .thenApply(String::toUpperCase)
    .thenAccept(System.out::println); // Non-blocking
```

### Combining
```java
CompletableFuture<String> f1 = CompletableFuture.supplyAsync(() -> "Hello");
CompletableFuture<String> f2 = CompletableFuture.supplyAsync(() -> "World");

f1.thenCombine(f2, (s1, s2) -> s1 + " " + s2)
  .thenAccept(System.out::println); // Hello World
```

---

## 🔐 LOCKS

**Explicit locks with more flexibility than synchronized**

### ReentrantLock
**More control than synchronized: tryLock, timeout, fairness, interruptible**

### Key Points
- **tryLock()**: Non-blocking attempt to acquire lock
- **Timeout**: Avoid indefinite waiting
- **Fairness**: Longest-waiting thread gets lock first (slower)
- **Always unlock in finally**: Prevent deadlock
- **Reentrant**: Same thread can acquire multiple times

```java
Lock lock = new ReentrantLock();

lock.lock();
try {
    // Critical section
} finally {
    lock.unlock(); // Always in finally
}

// Timeout to prevent deadlock
if (lock.tryLock(1, TimeUnit.SECONDS)) {
    try { /* critical */ } finally { lock.unlock(); }
}
```

### ReadWriteLock
**Allow multiple readers OR single writer (optimizes read-heavy scenarios)**

### Key Points
- **Read lock**: Multiple threads can hold simultaneously
- **Write lock**: Exclusive access
- **Use when**: Many reads, few writes

```java
ReadWriteLock rwLock = new ReentrantReadWriteLock();

// Multiple readers allowed
rwLock.readLock().lock();
try { /* read */ } finally { rwLock.readLock().unlock(); }

// Exclusive writer
rwLock.writeLock().lock();
try { /* write */ } finally { rwLock.writeLock().unlock(); }
```

---

## 🎯 INTERVIEW QUESTIONS

**Q: How to make class thread-safe?**
1. Immutability (best)
2. synchronized
3. Lock
4. Atomic classes
5. Thread-safe collections

**Q: synchronized vs ReentrantLock?**
- ReentrantLock: tryLock(), timeout, fair, interruptible
- synchronized: Simpler

**Q: When to use volatile?**
- Boolean flags
- Status variables
- Single writer, multiple readers
- NOT for count++ (not atomic)

**Q: What is CAS?**
- Compare-And-Swap
- Atomic hardware operation
- Used in AtomicInteger

---

## ⚠️ COMMON MISTAKES

```java
// ❌ Calling run()
thread.run(); // Same thread

// ❌ volatile for count++
private volatile int count;
count++; // Race condition

// ❌ Forgetting to unlock
lock.lock();
// ... no finally
lock.unlock(); // May not execute

// ❌ wait() outside synchronized
lock.wait(); // IllegalMonitorStateException
```

---

## 💡 QUICK WINS

**Always mention:**
- start() creates new thread, run() doesn't
- wait() releases lock, sleep() doesn't
- volatile for visibility, not atomicity
- Use ExecutorService over manual threads
- AtomicInteger for simple counters

**Impress interviewer:**
- Mention CAS (Compare-And-Swap)
- Discuss lock-free algorithms
- Know G1 GC basics
- Understand happens-before relationship

---

[← Back](./README.md) | [Next: Memory & GC →](./05_MEMORY_GC.md)
