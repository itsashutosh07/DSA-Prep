# ☕ JAVA FUNDAMENTALS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 🎯 JVM ARCHITECTURE

**Java Virtual Machine executes bytecode and provides platform independence**

### Key Points
- **Flow**: JDK (dev tools) → JRE (runtime) → JVM (executes) → OS
- **Components**: Class Loader + Runtime Memory + Execution Engine + GC
- **Platform Independence**: Bytecode is universal, JVM is platform-specific
- **JIT Compiler**: Converts hot bytecode to native machine code for performance
- **Why WORA**: Write Once, Run Anywhere - same .class runs on any OS with JVM

---

## 📊 DATA TYPES

**8 primitive types with fixed sizes and ranges**

### Key Points
- **Integer types**: byte (8), short (16), int (32), long (64) bits
- **Floating**: float (32), double (64) - use BigDecimal for money
- **Others**: char (16 bit Unicode), boolean (JVM dependent)
- **Wrappers**: Each primitive has object wrapper (int → Integer)
- **Default values**: Numbers = 0, boolean = false, objects = null

| Type | Size | Range | Wrapper |
|------|------|-------|---------|
| byte | 8 bit | -128 to 127 | Byte |
| int | 32 bit | -2³¹ to 2³¹-1 | Integer |
| long | 64 bit | -2⁶³ to 2⁶³-1 | Long |

### BigDecimal for Financial
**Floating point is imprecise due to binary representation**

```java
0.1 + 0.2 = 0.30000000000000004 ❌

BigDecimal a = new BigDecimal("0.1"); // ✅ String constructor
BigDecimal b = new BigDecimal("0.2");
a.add(b); // 0.3 ✅
```

---

## 🎨 OOPS (A-PIE)

**Four fundamental principles of Object-Oriented Programming**

### Abstraction
**Hide complexity, show only essential features**
- Use interfaces/abstract classes to define "what" not "how"
- Example: Payment interface hides card processing details

```java
interface Payment { void pay(double amount); }
class CreditCard implements Payment { /* hidden logic */ }
```

### Polymorphism
**One interface, many implementations**
- **Compile-time**: Method overloading (same name, different params)
- **Runtime**: Method overriding (parent reference, child object)

```java
int add(int a, int b) { }        // Overloading
double add(double a, double b) { }

Animal a = new Dog();
a.sound(); // Dog's sound (runtime)
```

### Inheritance
**Acquire properties from parent class (IS-A relationship)**
- Code reuse, hierarchical classification
- Java supports single inheritance (classes), multiple (interfaces)

```java
class Vehicle { void start() { } }
class Car extends Vehicle { } // Inherits start()
```

### Encapsulation
**Bundle data + methods, restrict direct access (data hiding)**
- Private fields + public methods
- Controlled access with validation

```java
class Account {
    private double balance; // Hidden
    public void deposit(double amt) { // Controlled
        if (amt > 0) balance += amt;
    }
}
```

---

## 🔐 ACCESS MODIFIERS

**Control visibility of classes, methods, and variables**

### Key Points
- **public**: Accessible everywhere
- **protected**: Same package + subclasses (even in different package)
- **default** (no modifier): Same package only
- **private**: Same class only
- **Mnemonic**: Pub-Pro-Pack-Pri (decreasing access)

| Modifier | Class | Package | Subclass | World |
|----------|-------|---------|----------|-------|
| public | ✅ | ✅ | ✅ | ✅ |
| protected | ✅ | ✅ | ✅ | ❌ |
| default | ✅ | ✅ | ❌ | ❌ |
| private | ✅ | ❌ | ❌ | ❌ |

---

## 🔤 STRINGS

**Immutable sequence of characters stored in String Pool (Heap) for memory efficiency**

### Key Points
- **String Pool**: Literal strings reuse same object in pool
- **new String()**: Creates new object in heap (not pool)
- **Immutable**: Cannot be changed after creation
- **Why immutable**: String pool, security, thread-safe, hashcode caching
- **Use StringBuilder**: For concatenation in loops (mutable, not thread-safe)
- **Use StringBuffer**: When thread-safety needed (synchronized, slower)

### Creation & Comparison
```java
String s1 = "Hello";              // Pool
String s2 = "Hello";              // Same reference
String s3 = new String("Hello");  // Heap

s1 == s2;        // true (same object)
s1 == s3;        // false (different objects)
s1.equals(s3);   // true (same content) ✅
```

### Performance
```java
// ❌ Creates 1000 String objects
String s = "";
for (int i = 0; i < 1000; i++) s += i;

// ✅ Modifies same object
StringBuilder sb = new StringBuilder();
for (int i = 0; i < 1000; i++) sb.append(i);
```

---

## 📦 WRAPPER CLASSES

**Object representation of primitives (needed for Collections, Generics, nullability)**

### Key Points
- **Mapping**: int → Integer, char → Character, boolean → Boolean
- **Autoboxing**: Automatic primitive → wrapper conversion
- **Unboxing**: Automatic wrapper → primitive conversion
- **Caching**: -128 to 127 cached (same object returned)
- **Always use equals()**: Don't use == for wrappers (reference comparison)
- **NPE risk**: Unboxing null wrapper throws NullPointerException

### Integer Caching Trap
```java
Integer a = 127, b = 127;
a == b;  // true (cached) ✅

Integer c = 128, d = 128;
c == d;  // false (not cached) ❌
c.equals(d); // true ✅

// Rule: Always use equals() for wrappers
```

---

## 🔄 GENERICS

**Type parameters for compile-time type safety (prevents ClassCastException)**

### Key Points
- **Purpose**: Type safety, no casting, catch errors at compile-time
- **Type Erasure**: Generics removed at runtime (replaced with Object)
- **Upper Bound** `<? extends T>`: Read-only, accepts T or subclasses (Producer)
- **Lower Bound** `<? super T>`: Write-only, accepts T or superclasses (Consumer)
- **PECS Rule**: Producer Extends, Consumer Super

### Wildcards
```java
// Producer (read from) - extends
List<? extends Number> list = Arrays.asList(1, 2, 3);
Number n = list.get(0); // ✅ Can read
// list.add(5); // ❌ Cannot write

// Consumer (write to) - super
List<? super Integer> list = new ArrayList<Number>();
list.add(5); // ✅ Can write
// Integer i = list.get(0); // ❌ Cannot read as Integer
```

---

## ⚠️ EXCEPTIONS

**Mechanism to handle runtime errors gracefully**

### Key Points
- **Checked**: Must handle at compile-time (IOException, SQLException)
- **Unchecked**: Optional handling (NullPointerException, ArithmeticException)
- **Error**: JVM problems, don't catch (OutOfMemoryError, StackOverflowError)
- **try-catch-finally**: finally always executes (even with return)
- **try-with-resources**: Auto-closes resources (must implement AutoCloseable)

### Hierarchy
```
Throwable
├── Error (Unchecked) - OutOfMemoryError, StackOverflowError
└── Exception
    ├── RuntimeException (Unchecked) - NPE, ArithmeticException
    └── Checked - IOException, SQLException
```

### Try-with-Resources
```java
try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
    String line = br.readLine();
} // Auto-closed, no finally needed
```

---

## 🎯 INTERVIEW TRAPS

### Trap 1: Integer Comparison
```java
Integer a = 128, b = 128;
if (a == b) { } // ❌ false
if (a.equals(b)) { } // ✅ true
```

### Trap 2: String Concatenation
```java
// ❌ In loop
for (int i = 0; i < 1000; i++) s += i;

// ✅ StringBuilder
StringBuilder sb = new StringBuilder();
```

### Trap 3: Autoboxing NPE
```java
Integer i = null;
int j = i; // ❌ NullPointerException
```

### Trap 4: Type Erasure
```java
// ❌ Cannot create generic array
T[] arr = new T[10]; // Compilation error
```

---

## 💡 QUICK WINS

**Always mention:**
- Why String is immutable (4 reasons)
- Integer caching (-128 to 127)
- PECS principle for generics
- Constructor injection over field injection
- Use equals() for wrappers

**Common follow-ups:**
- "Why?" - Explain reasoning
- "Trade-offs?" - Pros and cons
- "Alternatives?" - Other approaches

---

[← Back](./README.md) | [Next: Concurrency →](./04_CONCURRENCY.md)
