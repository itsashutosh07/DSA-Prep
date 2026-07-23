# 🍃 SPRING BOOT ESSENTIALS

[← Back](./README.md) | **⏱️ 15 minutes**

---

## 💉 DEPENDENCY INJECTION

**Spring creates and injects dependencies automatically (Inversion of Control)**

### Key Points
- **Purpose**: Loose coupling, easy testing, follows SOLID
- **Constructor injection**: Best practice (immutable, testable)
- **Field injection**: Avoid (hard to test, hidden dependencies)
- **Setter injection**: Rare (optional dependencies)
- **@Autowired**: Optional if single constructor (Spring 4.3+)
- **How it works**: Spring scans @Component/@Service/@Repository, creates beans, injects

### Constructor Injection (Best ✅)
```java
@Service
public class UserService {
    private final UserRepository repo; // Immutable
    
    @Autowired // Optional if single constructor
    public UserService(UserRepository repo) {
        this.repo = repo;
    }
}
```

### Field Injection (Avoid ❌)
```java
@Autowired
private UserRepository repo; // Hard to test, mutable
```

---

## 🏷️ KEY ANNOTATIONS

**Spring uses annotations for component scanning, DI, and web mapping**

### Stereotype Annotations
**Mark classes for Spring to manage as beans**

```java
@Component       // Generic bean
@Service         // Business logic layer
@Repository      // Data access layer (exception translation)
@Controller      // Web MVC (returns views)
@RestController  // REST API (@Controller + @ResponseBody)
```

### Web Annotations
**Map HTTP requests to methods**

```java
@RequestMapping("/api/users")  // Base path
@GetMapping("/{id}")           // GET /api/users/123
@PostMapping                   // POST /api/users
@PutMapping("/{id}")           // PUT /api/users/123
@DeleteMapping("/{id}")        // DELETE /api/users/123

@PathVariable    // Extract from URL: /users/{id}
@RequestParam    // Extract from query: /users?name=John
@RequestBody     // Parse JSON from request body
```

### DI Annotations
```java
@Autowired              // Inject dependency
@Qualifier("beanName")  // Specify which bean (multiple candidates)
@Primary                // Preferred bean (default choice)
```

---

## 🎯 BEAN SCOPES

**Control lifecycle and number of bean instances**

### Key Points
- **singleton (default)**: One instance per Spring container (shared)
- **prototype**: New instance every time requested
- **request**: One per HTTP request (web apps only)
- **session**: One per HTTP session (web apps only)
- **Use singleton**: Stateless services (most common)
- **Use prototype**: Stateful objects

| Scope | Lifecycle |
|-------|-----------|
| **singleton** (default) | One per container |
| **prototype** | New every time |
| **request** | One per HTTP request |
| **session** | One per HTTP session |

---

## 🗄️ JPA & HIBERNATE

**ORM framework that maps Java objects to database tables (eliminates boilerplate SQL)**

### Key Points
- **Entity**: Java class mapped to DB table (@Entity)
- **Repository**: Interface for CRUD operations (extends JpaRepository)
- **JPQL**: Object-oriented query language (SELECT u FROM User u)
- **Lazy loading**: Load related entities on demand (default for collections)
- **Eager loading**: Load immediately (use sparingly)
- **N+1 Problem**: 1 query for parent, N for children (use JOIN FETCH)

### Entity Mapping
```java
@Entity
@Table(name = "users")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @Column(unique = true, nullable = false)
    private String email;
    
    @OneToMany(mappedBy = "user", fetch = FetchType.LAZY)
    private List<Order> orders;
}
```

### Repository
```java
@Repository
public interface UserRepository extends JpaRepository<User, Long> {
    User findByEmail(String email);
    List<User> findByAgeGreaterThan(int age);
    
    @Query("SELECT u FROM User u WHERE u.email = :email")
    User findUserByEmail(@Param("email") String email);
}
```

### N+1 Problem (Critical!)
**Most common performance issue in JPA**

```java
// ❌ Problem (1 + N queries)
List<User> users = userRepo.findAll();        // 1 query
for (User u : users) {
    u.getOrders(); // N queries (lazy load)
}

// ✅ Solution: JOIN FETCH (1 query)
@Query("SELECT u FROM User u LEFT JOIN FETCH u.orders")
List<User> findAllWithOrders();
```

---

## 🔄 TRANSACTIONS

**@Transactional ensures atomicity: all operations succeed or all rollback**

### Key Points
- **Default**: Rollback on unchecked exceptions only
- **readOnly = true**: Optimization for read operations (no flush)
- **Propagation**: How transactions relate to each other
- **Isolation**: Control concurrent transaction behavior
- **Best practice**: Apply on service layer, not controller

### Usage
```java
@Transactional
public void transfer(Long from, Long to, double amount) {
    accountRepo.debit(from, amount);
    accountRepo.credit(to, amount);
    // If any fails, both rollback
}

@Transactional(readOnly = true) // Optimization
public User getUser(Long id) {
    return userRepo.findById(id).orElseThrow();
}
```

### Propagation Types
- **REQUIRED** (default): Use existing transaction or create new
- **REQUIRES_NEW**: Always create new transaction (suspend existing)
- **SUPPORTS**: Use transaction if exists, else non-transactional

---

## 🌐 REST CONTROLLER

**Handle HTTP requests and return JSON responses**

### Key Points
- **@RestController**: @Controller + @ResponseBody (auto-converts to JSON)
- **@RequestMapping**: Base path for all methods
- **ResponseEntity**: Control status code, headers, body
- **@Valid**: Trigger validation
- **Best practice**: Thin controllers (delegate to service layer)

```java
@RestController
@RequestMapping("/api/users")
public class UserController {
    private final UserService service;
    
    @Autowired
    public UserController(UserService service) {
        this.service = service;
    }
    
    @GetMapping("/{id}")
    public ResponseEntity<User> getUser(@PathVariable Long id) {
        return ResponseEntity.ok(service.getUser(id));
    }
    
    @PostMapping
    public ResponseEntity<User> createUser(@Valid @RequestBody User user) {
        User created = service.createUser(user);
        return ResponseEntity.status(201).body(created);
    }
    
    @DeleteMapping("/{id}")
    public ResponseEntity<Void> deleteUser(@PathVariable Long id) {
        service.deleteUser(id);
        return ResponseEntity.noContent().build();
    }
}
```

---

## ✅ VALIDATION

**Bean Validation (JSR-303) for input validation**

### Key Points
- **@Valid**: Trigger validation in controller
- **@NotNull**: Field cannot be null
- **@NotBlank**: String not null, not empty, not whitespace
- **@Size**: Length constraints
- **@Email, @Min, @Max**: Specific validations
- **Custom messages**: Provide user-friendly error messages

```java
@Entity
public class User {
    @NotBlank(message = "Name required")
    @Size(min = 2, max = 50)
    private String name;
    
    @Email(message = "Invalid email")
    private String email;
    
    @Min(18) @Max(100)
    private Integer age;
}

@PostMapping
public User createUser(@Valid @RequestBody User user) {
    return service.createUser(user); // Validation happens here
}
```

---

## 🚨 EXCEPTION HANDLING

**Centralized error handling with @RestControllerAdvice**

### Key Points
- **@RestControllerAdvice**: Global exception handler (applies to all controllers)
- **@ExceptionHandler**: Handle specific exception type
- **Return**: ResponseEntity with error details + status code
- **Best practice**: Custom exceptions (ResourceNotFoundException), structured error response

```java
@RestControllerAdvice
public class GlobalExceptionHandler {
    @ExceptionHandler(ResourceNotFoundException.class)
    public ResponseEntity<Error> handleNotFound(ResourceNotFoundException ex) {
        return ResponseEntity.status(404).body(new Error(ex.getMessage()));
    }
    
    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<Error> handleValidation(MethodArgumentNotValidException ex) {
        return ResponseEntity.status(400).body(new Error("Validation failed"));
    }
    
    @ExceptionHandler(Exception.class)
    public ResponseEntity<Error> handleGeneral(Exception ex) {
        return ResponseEntity.status(500).body(new Error("Internal error"));
    }
}
```

---

## 🔐 SECURITY (JWT)

**Spring Security with JWT for stateless authentication**

### Key Points
- **JWT**: JSON Web Token (header.payload.signature)
- **Stateless**: No session on server (token contains all info)
- **Flow**: Login → Generate JWT → Client stores → Send in header → Validate
- **Header**: `Authorization: Bearer <token>`
- **Expiry**: Set expiration (e.g., 1 hour), refresh token for renewal
- **Security**: Sign with secret key, validate signature

### Configuration
```java
@Configuration
@EnableWebSecurity
public class SecurityConfig {
    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) {
        http.csrf().disable()
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/api/public/**").permitAll()
                .requestMatchers("/api/admin/**").hasRole("ADMIN")
                .anyRequest().authenticated()
            )
            .sessionManagement(s -> s
                .sessionCreationPolicy(SessionCreationPolicy.STATELESS)
            );
        return http.build();
    }
}
```

### JWT Flow
```
1. POST /login → Validate credentials → Generate JWT
2. Client stores JWT (localStorage/cookie)
3. Client sends: Authorization: Bearer <token>
4. JwtFilter validates token → Extract user → Set SecurityContext
5. Grant access
```

---

## 🎯 INTERVIEW QUESTIONS

**Q: Constructor vs Field injection?**
- Constructor: Immutable, testable ✅
- Field: Hard to test ❌

**Q: @Component vs @Service?**
- @Service is specialization of @Component
- Use @Service for business logic (semantic)

**Q: Bean scopes?**
- singleton (default), prototype, request, session

**Q: What is N+1 problem?**
- 1 query for parent, N for children
- Solution: JOIN FETCH

**Q: EAGER vs LAZY?**
- EAGER: Load immediately
- LAZY: Load on demand (default for collections)

**Q: What is @Transactional?**
- Marks method as transaction
- Rollback on unchecked exception

**Q: How Spring Boot auto-configuration works?**
- Scans classpath
- Configures beans automatically
- Can override with custom config

**Q: How to handle circular dependency?**
- Setter injection
- @Lazy annotation
- Refactor design (best)

---

## ⚠️ COMMON MISTAKES

```java
// ❌ Field injection
@Autowired private Repo repo;

// ✅ Constructor injection
private final Repo repo;
@Autowired
public Service(Repo repo) { this.repo = repo; }

// ❌ Exposing entities
@GetMapping("/{id}")
public User getUser() { } // Exposes all fields

// ✅ Use DTOs
public UserDTO getUser() { } // Control what to expose

// ❌ No exception handling
public User getUser(Long id) {
    return repo.findById(id).get(); // May throw NoSuchElementException
}

// ✅ Handle exceptions
public User getUser(Long id) {
    return repo.findById(id)
        .orElseThrow(() -> new ResourceNotFoundException());
}
```

---

## 💡 QUICK WINS

**Always mention:**
- Constructor injection (immutable, testable)
- @RestController = @Controller + @ResponseBody
- N+1 problem and JOIN FETCH solution
- @Transactional for atomicity
- Use DTOs, not entities

**Impress interviewer:**
- Know transaction propagation types
- Explain Spring Boot magic (auto-config)
- Discuss connection pooling (HikariCP)
- Mention Spring Security filter chain
- Know JPA fetch strategies

---

## 🏗️ COMPLETE FLOW

**Request lifecycle in Spring Boot application**

### Key Points
- **Filter**: Security (JWT validation), logging, CORS (runs before controller)
- **Controller**: Handle HTTP, validate input, delegate to service
- **Service**: Business logic, transactions, orchestration
- **Repository**: Data access, JPA queries
- **Layered architecture**: Separation of concerns, testability

```
Request
  ↓
Filter (Security, Logging, CORS)
  ↓
Controller (@RestController) - HTTP handling
  ↓
Service (@Service, @Transactional) - Business logic
  ↓
Repository (@Repository, JPA) - Data access
  ↓
Database
```

---

[← Previous: System Design](./08_SYSTEM_DESIGN.md) | [Back](./README.md) | [Next: Production →](./10_PRODUCTION.md)
