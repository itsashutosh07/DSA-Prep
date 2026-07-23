# 🚀 PRODUCTION & DEVOPS

[← Back](./README.md) | **⏱️ 10 minutes**

---

## 🐳 DOCKER

**Containerization platform that packages app + dependencies into lightweight, portable containers**

### Key Points
- **Container vs VM**: Shares OS kernel (MB, seconds) vs Full OS (GB, minutes)
- **Dockerfile**: Recipe to build image (FROM, COPY, EXPOSE, ENTRYPOINT)
- **Image**: Template (read-only)
- **Container**: Running instance of image
- **Why use**: Consistency across environments, isolation, portability

### Essential Commands
```bash
docker build -t myapp:1.0 .                    # Build image
docker run -d -p 8080:8080 myapp:1.0          # Run container
docker ps                                      # List running
docker logs -f myapp                          # View logs
docker exec -it myapp bash                    # Enter container
docker stop myapp && docker rm myapp          # Stop & remove
```

### Docker Compose
**Orchestrate multi-container apps with single YAML file**

```yaml
version: '3.8'
services:
  app:
    build: .
    ports: ["8080:8080"]
    depends_on: [db]
  db:
    image: mysql:8.0
```

```bash
docker-compose up -d      # Start all services
docker-compose down       # Stop all services
```

---

## ☸️ KUBERNETES

**Container orchestration platform that automates deployment, scaling, and management**

### Key Points
- **Pod**: Smallest unit (1+ containers), shared network/storage
- **Deployment**: Manages ReplicaSets, handles rolling updates
- **Service**: Stable endpoint for Pods, load balancing (ClusterIP, NodePort, LoadBalancer)
- **ConfigMap**: Non-sensitive config (DB host, ports)
- **Secret**: Sensitive data (passwords, keys) - base64 encoded
- **HPA**: Horizontal Pod Autoscaler (auto-scale based on CPU/memory)

### Essential Commands
```bash
kubectl apply -f deployment.yaml              # Deploy
kubectl get pods                              # List pods
kubectl logs -f pod-name                      # View logs
kubectl describe pod pod-name                 # Detailed info
kubectl exec -it pod-name -- bash             # Enter pod
kubectl scale deployment myapp --replicas=5   # Scale
kubectl rollout status deployment/myapp       # Check rollout
kubectl rollout undo deployment/myapp         # Rollback
```

### Minimal Deployment
```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: myapp
spec:
  replicas: 3
  selector:
    matchLabels:
      app: myapp
  template:
    spec:
      containers:
      - name: myapp
        image: myapp:1.0
        ports:
        - containerPort: 8080
```

---

## 🔄 CI/CD

**Continuous Integration: Auto-build/test on commit | Continuous Deployment: Auto-deploy to production**

### Key Points
- **CI**: Catch bugs early, ensure code quality, run tests automatically
- **CD**: Faster releases, reduced manual errors, consistent deployments
- **Pipeline**: Code → Build → Test → Docker Build → Push → Deploy
- **Tools**: GitHub Actions, Jenkins, GitLab CI, CircleCI

### Typical Pipeline
```
1. Code commit (git push)
2. Build (mvn clean package)
3. Test (mvn test)
4. Build Docker image
5. Push to registry (Docker Hub, ECR)
6. Deploy to K8s (kubectl set image)
7. Health check
```

### GitHub Actions Example
```yaml
name: CI/CD
on: [push]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    - name: Build
      run: mvn clean package
    - name: Test
      run: mvn test
    - name: Docker
      run: docker build -t myapp .
```

---

## 📊 MONITORING

**Observability through Metrics, Logs, and Traces to detect issues before users do**

### 3 Pillars

**1. Metrics (Prometheus + Grafana)**
- What: CPU, memory, request rate, latency (p50, p95, p99), error rate
- Why: Real-time health, performance trends, alerting
- Tools: Prometheus, Grafana, Micrometer

**2. Logs (ELK Stack)**
- What: Application logs, access logs, error logs
- Why: Debug issues, audit trail, troubleshooting
- Tools: Elasticsearch, Logstash, Kibana

**3. Traces (Jaeger/Zipkin)**
- What: Request flow across microservices
- Why: Find bottlenecks, debug latency issues
- Tools: Jaeger, Zipkin, Spring Cloud Sleuth

---

## ⚡ LATENCY PERCENTILES (Critical!)

**Measure response time distribution (p50, p95, p99) instead of average**

### Key Points
- **p50 (Median)**: 50% of requests faster than this (typical user experience)
- **p95**: 95% faster (5% slower) - shows stress scenarios
- **p99**: 99% faster (1% slower) - captures tail latency (worst-case)
- **Why not average**: Hides outliers that ruin user experience
- **Memory Hook**: Average lies, p95 shows stress, p99 shows pain

### Example
```
10 requests: 100ms, 110ms, 120ms, 130ms, 140ms, 150ms, 160ms, 170ms, 180ms, 3000ms

Average = 426ms ❌ (misleading)
p50 = 145ms ✅ (median)
p95 = 180ms ✅ (95% faster)
p99 = 3000ms ⚠️ (tail latency problem!)
```

### Real Production Metrics
| Metric | Value | Meaning |
|--------|-------|---------|
| p50 | 80ms | Most users happy ✅ |
| p95 | 250ms | 5% see slight delay ⚠️ |
| p99 | 1200ms | 1% see serious delay ❌ |

**Diagnosis**: Tail latency problem (investigate GC, DB locks, thread exhaustion)

### How to Improve p99
- Tune GC (G1, `-XX:MaxGCPauseMillis=50`)
- Add caching (Redis)
- Connection pooling (HikariCP)
- Optimize slow queries (EXPLAIN, indexes)
- Increase thread pool size
- Use async processing (message queues)
- Add timeouts & circuit breakers

### Tail Latency Amplification
**In microservices, tail latency compounds across services**
```
Service A: p99 = 100ms
Service B: p99 = 100ms
Service C: p99 = 100ms

Request needs A + B + C
→ Overall p99 >> 300ms (tail amplification)
```

---

## 🏗️ HIGH AVAILABILITY

**System remains operational even when components fail (target: 99.9% = 8.76 hours downtime/year)**

### Key Strategies
- **Redundancy**: Multiple instances (no single point of failure)
- **Load Balancing**: Distribute traffic, health checks, auto-remove unhealthy
- **Replication**: Database replicas for failover
- **Auto-healing**: K8s restarts failed pods automatically
- **Circuit Breaker**: Stop calling failed service, prevent cascade
- **Multi-region**: Deploy across geographic regions

### Architecture
```
Load Balancer (health checks)
    ↓
App Instances (3+, auto-healing)
    ↓
Cache (Redis cluster)
    ↓
Database (Primary + 2 Replicas)
```

---

## 🎯 DEPLOYMENT STRATEGIES

**Methods to deploy new version without downtime**

### Blue-Green Deployment
**Run two identical environments, switch traffic instantly**
- Process: Deploy v2.0 (Green) → Test → Switch traffic → Keep v1.0 (Blue) for rollback
- Pros: Zero downtime, instant rollback, easy testing
- Cons: Double resources, database migration tricky

### Canary Deployment
**Gradually roll out to subset of users, monitor, then full rollout**
- Process: v1.0 (90%) + v2.0 (10%) → Monitor → Increase v2.0 gradually
- Pros: Low risk, real user testing, gradual rollout
- Cons: Complex routing, longer deployment time

### Rolling Update
**Replace instances one by one**
- Process: [v1 v1 v1 v1] → [v2 v1 v1 v1] → [v2 v2 v1 v1] → [v2 v2 v2 v2]
- Pros: No extra resources, gradual
- Cons: Mixed versions during rollout, slower rollback

---

## ✅ PRODUCTION CHECKLIST

**Essential items before deploying to production**

### Key Points
- **Health checks**: Endpoint for load balancer to verify app is running
- **Graceful shutdown**: Finish in-flight requests before stopping
- **Connection pooling**: Reuse DB connections (HikariCP default in Spring Boot)
- **Monitoring**: Metrics, logs, traces (know when things break)
- **Security**: HTTPS, JWT, input validation, secrets management

### Application
- [ ] Health check endpoint (`/actuator/health`)
- [ ] Graceful shutdown (handle SIGTERM)
- [ ] Connection pooling (DB, HTTP clients)
- [ ] Caching (Redis for hot data)
- [ ] Rate limiting (prevent abuse)
- [ ] Input validation (@Valid)
- [ ] Error handling (GlobalExceptionHandler)
- [ ] Logging (structured JSON, correlation IDs)

### Database
- [ ] Indexes on frequent queries
- [ ] Connection pooling (HikariCP)
- [ ] Replication (1 primary + 2 replicas)
- [ ] Backup strategy (daily snapshots)
- [ ] Query optimization (EXPLAIN)

### Security
- [ ] HTTPS (TLS 1.2+)
- [ ] Authentication (JWT)
- [ ] Authorization (role-based)
- [ ] Input sanitization (prevent SQL injection)
- [ ] Secrets management (AWS Secrets Manager, Vault)
- [ ] Security headers (CORS, CSP)

### Infrastructure
- [ ] Load balancer (health checks)
- [ ] Auto-scaling (HPA in K8s)
- [ ] Multiple availability zones
- [ ] Monitoring & alerting (Prometheus, Grafana)
- [ ] Disaster recovery plan (RTO, RPO)

---

## 🎯 INTERVIEW QUESTIONS

**Q: Container vs VM?**
- Container: Shares kernel, MB, seconds
- VM: Full OS, GB, minutes

**Q: What is Kubernetes?**
- Container orchestration
- Auto-scaling, self-healing, load balancing

**Q: What is Pod?**
- Smallest unit (1+ containers)
- Shared network and storage

**Q: What is Service in K8s?**
- Exposes Pods
- Load balancing
- Types: ClusterIP, NodePort, LoadBalancer

**Q: What is CI/CD?**
- CI: Build + Test on every commit
- CD: Auto-deploy to production

**Q: Deployment strategies?**
- Blue-Green: Zero downtime, easy rollback
- Canary: Gradual rollout
- Rolling: No extra resources

**Q: What is p99 latency?**
- 99% of requests complete faster than this
- Captures tail latency (worst-case)
- Critical for user experience

**Q: Why not use average latency?**
- Average hides outliers
- Few slow requests inflate average
- Use p95/p99 instead

**Q: How to ensure high availability?**
- Multiple instances
- Load balancer with health checks
- Database replication
- Auto-healing

**Q: What is circuit breaker?**
- Prevent cascade failures
- States: Closed → Open → Half-Open

---

## ⚠️ COMMON MISTAKES

```
❌ No health check endpoint
❌ No graceful shutdown
❌ Single instance (no redundancy)
❌ No monitoring/alerting
❌ Secrets in code/config
❌ No backup strategy
❌ No rollback plan
```

---

## 💡 QUICK WINS

**Always mention:**
- Docker for consistency
- K8s for orchestration
- CI/CD for automation
- Monitoring (metrics, logs, traces)
- p95/p99 latency (not average) ⭐
- Multiple instances for HA

**Impress interviewer:**
- Know deployment strategies
- Discuss zero-downtime deployment
- Mention circuit breaker
- Understand health checks
- Explain p99 tail latency
- Know basic kubectl commands

---

## 🏗️ PRODUCTION ARCHITECTURE

**Scale architecture based on traffic and requirements**

### Key Points
- **Small**: Single server (< 10K users, < 100 RPS)
- **Medium**: Load balancer, cache, replicas (< 1M users, < 10K RPS)
- **Large**: CDN, sharding, microservices (> 1M users, > 10K RPS)
- **Principle**: Start simple, scale based on bottlenecks

### Small Scale (< 10K users)
```
Client → Server → DB
```

### Medium Scale (< 1M users)
```
Client → LB → Servers (3+) → Cache → DB (Primary + Replicas)
```

### Large Scale (> 1M users)
```
Client → CDN → LB → Servers → Cache Cluster → DB (Sharded + Replicated)
                             → Message Queue
                             → Microservices
```

---

[← Previous: Spring Boot](./09_SPRING_BOOT.md) | [Back](./README.md)
