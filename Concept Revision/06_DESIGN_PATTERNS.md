# 🎨 DESIGN PATTERNS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 🎯 SOLID PRINCIPLES

**Five design principles for maintainable, scalable OOP code (Mnemonic: S-O-L-I-D)**

### S - Single Responsibility
**Each class should have one reason to change**
- Improves maintainability, reduces coupling
- Separate concerns (business logic, persistence, presentation)

```java
// ❌ Multiple responsibilities
class User {
    void save() { } // DB
    void sendEmail() { } // Email
}

// ✅ Single responsibility
class User { }
class UserRepository { void save(User u) { } }
class EmailService { void send(User u) { } }
```

### O - Open/Closed
**Open for extension, closed for modification**
- Add new features without changing existing code
- Use interfaces, abstract classes, polymorphism

```java
// ❌ Modify for new shapes
if (shape instanceof Circle) { }

// ✅ Extend via interface
interface Shape { double area(); }
class Circle implements Shape { }
```

### L - Liskov Substitution
**Subclass must be substitutable for parent without breaking behavior**
- Child shouldn't break parent's contract
- Don't throw exceptions in overridden methods

```java
// ❌ Violates LSP
class Bird { void fly() { } }
class Ostrich extends Bird {
    void fly() { throw new Exception(); } // Breaks contract
}

// ✅ Follows LSP
interface FlyingBird { void fly(); }
class Ostrich { } // No fly()
```

### I - Interface Segregation
**Many specific interfaces better than one general interface**
- Clients shouldn't depend on methods they don't use

```java
// ❌ Fat interface
interface Worker { void work(); void eat(); void sleep(); }

// ✅ Segregated
interface Workable { void work(); }
interface Eatable { void eat(); }
```

### D - Dependency Inversion
**Depend on abstractions, not concrete classes**
- High-level modules shouldn't depend on low-level modules
- Use interfaces, inject dependencies

```java
// ❌ Depends on concrete
class Service {
    private MySQLDB db = new MySQLDB();
}

// ✅ Depends on abstraction
class Service {
    private Database db; // Interface
    Service(Database db) { this.db = db; }
}
```

---

## 🏗️ CREATIONAL PATTERNS

**Control object creation process**

### Singleton
**Ensure only one instance exists globally**
- Use for: Config, Logger, DB connection pool
- Best: Enum (thread-safe, serialization-safe)
- Alternative: Bill Pugh (lazy, thread-safe)

```java
// ✅ Best: Enum
enum Singleton {
    INSTANCE;
    public void doSomething() { }
}

// ✅ Alternative: Bill Pugh
class Singleton {
    private Singleton() {}
    private static class Helper {
        static final Singleton INSTANCE = new Singleton();
    }
    public static Singleton getInstance() { return Helper.INSTANCE; }
}
```

### Factory
**Delegate object creation to factory method**
- Use for: Loose coupling, hide creation logic
- Client doesn't know concrete class

```java
interface Shape { void draw(); }

class ShapeFactory {
    public static Shape getShape(String type) {
        return switch(type) {
            case "CIRCLE" -> new Circle();
            case "RECTANGLE" -> new Rectangle();
            default -> throw new IllegalArgumentException();
        };
    }
}
```

### Builder
**Construct complex objects step-by-step**
- Use for: Many optional parameters, immutability, readability
- Avoids telescoping constructors

```java
class User {
    private User(Builder b) { }
    
    static class Builder {
        public Builder(String name) { }
        public Builder age(int age) { return this; }
        public User build() { return new User(this); }
    }
}

User user = new User.Builder("Ashu").age(25).build();
```

---

## 🔧 STRUCTURAL PATTERNS

**Organize relationships between classes and objects**

### Adapter
**Convert one interface to another (make incompatible interfaces work together)**
- Use for: Integrate legacy code, third-party libraries
- Example: XML to JSON converter

```java
class Adapter implements TargetInterface {
    private Adaptee adaptee;
    public void request() {
        adaptee.specificRequest(); // Convert
    }
}
```

### Decorator
**Add functionality dynamically without modifying original class**
- Use for: Add features at runtime, avoid subclass explosion
- Example: Java I/O streams (BufferedReader wraps FileReader)

```java
Coffee coffee = new SimpleCoffee();
coffee = new MilkDecorator(coffee);
coffee = new SugarDecorator(coffee);
System.out.println(coffee.cost()); // 5 + 1.5 + 0.5
```

### Proxy
**Control access to object (lazy loading, security, logging)**
- Use for: Expensive object creation, access control
- Example: Hibernate lazy loading

```java
class ProxyImage implements Image {
    private RealImage realImage;
    public void display() {
        if (realImage == null) realImage = new RealImage(); // Lazy
        realImage.display();
    }
}
```

---

## 🎭 BEHAVIORAL PATTERNS

**Define communication between objects**

### Strategy
**Select algorithm at runtime (encapsulate interchangeable behaviors)**
- Use for: Multiple ways to do same task, avoid if-else chains
- Example: Payment methods, sorting algorithms

```java
interface PaymentStrategy { void pay(int amount); }

class ShoppingCart {
    private PaymentStrategy strategy;
    void setStrategy(PaymentStrategy s) { this.strategy = s; }
    void checkout(int amt) { strategy.pay(amt); }
}

cart.setStrategy(new CreditCardPayment());
cart.checkout(1000);
```

### Observer
**One-to-many dependency: when one object changes, notify all dependents**
- Use for: Event handling, pub-sub systems
- Example: MVC (Model notifies Views), event listeners

```java
interface Observer { void update(String msg); }

class Subject {
    private List<Observer> observers = new ArrayList<>();
    void attach(Observer o) { observers.add(o); }
    void notifyAll(String msg) { observers.forEach(o -> o.update(msg)); }
}
```

### Template Method
**Define algorithm skeleton, let subclasses override specific steps**
- Use for: Common workflow with customizable steps
- Example: Data processing pipeline

```java
abstract class DataProcessor {
    final void process() { // Template (final)
        readData();
        processData();
        saveData();
    }
    abstract void readData();
    abstract void processData();
    void saveData() { } // Default
}
```

---

## 🎯 PATTERN SELECTION

**Quick reference to choose the right pattern for your problem**

### Key Points
- **Singleton**: Global access point (Logger, Config)
- **Builder**: Many optional params (User with 10+ fields)
- **Factory**: Hide creation logic (ShapeFactory)
- **Decorator**: Add features dynamically (I/O streams)
- **Adapter**: Make incompatible interfaces work (Legacy integration)
- **Strategy**: Swap algorithms at runtime (Payment methods)
- **Observer**: Notify dependents on change (Event listeners)

| Problem | Pattern |
|---------|---------|
| Only one instance | Singleton |
| Complex object creation | Builder |
| Hide creation logic | Factory |
| Add functionality | Decorator |
| Convert interface | Adapter |
| Algorithm selection | Strategy |
| Notify multiple objects | Observer |

---

## 🎯 INTERVIEW QUESTIONS

**Q: How to implement thread-safe Singleton?**
- Enum (best)
- Bill Pugh (inner static class)
- Double-checked locking with volatile

**Q: When to use Builder?**
- Many optional parameters
- Immutable objects
- Readable construction

**Q: Strategy vs Template Method?**
- Strategy: Entire algorithm interchangeable
- Template: Override specific steps

**Q: What is Liskov violation?**
- Subclass breaks parent's contract
- Example: Ostrich extends Bird but can't fly()

---

## 💡 QUICK WINS

**Always mention:**
- SOLID principles (can explain all 5)
- Singleton: Enum is best
- Factory for loose coupling
- Builder for immutability

**Impress interviewer:**
- Discuss when NOT to use patterns
- Mention real-world examples (Spring uses Factory, Proxy)
- Know multiple Singleton implementations
- Explain trade-offs

---

[← Previous: Memory & GC](./05_MEMORY_GC.md) | [Back](./README.md) | [Next: Database →](./07_DATABASE.md)
