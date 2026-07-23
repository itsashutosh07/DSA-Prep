"""
Python Implementations for R2 Live Coding (Design / Backend)
Round 1 DSA = C++ — see 11-cpp-dsa-implementations.cpp
"""

# ============================================================================
# 1. LRU CACHE (HIGHEST PROBABILITY - ties to your caching story)
# ============================================================================

from collections import OrderedDict

class LRUCache:
    """
    get(key) and put(key, val) in O(1)
    OrderedDict: move_to_end on access, popitem(last=False) evicts LRU
    """
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)


# ============================================================================
# 2. RATE LIMITER (backend-heavy interview favorite)
# ============================================================================

import time
from collections import deque

class RateLimiter:
    """Sliding window: max N requests per window_seconds"""
    def __init__(self, max_requests: int, window_seconds: int):
        self.max_requests = max_requests
        self.window = window_seconds
        self.requests = deque()

    def allow_request(self) -> bool:
        now = time.time()
        while self.requests and self.requests[0] < now - self.window:
            self.requests.popleft()
        if len(self.requests) < self.max_requests:
            self.requests.append(now)
            return True
        return False


class TokenBucketRateLimiter:
    def __init__(self, capacity: int, refill_rate: float):
        self.capacity = capacity
        self.tokens = capacity
        self.refill_rate = refill_rate
        self.last_refill = time.time()

    def allow_request(self) -> bool:
        now = time.time()
        elapsed = now - self.last_refill
        self.tokens = min(self.capacity, self.tokens + elapsed * self.refill_rate)
        self.last_refill = now
        if self.tokens >= 1:
            self.tokens -= 1
            return True
        return False


# ============================================================================
# 3. DECORATOR WITH RETRY (common R2 prompt)
# ============================================================================

import functools

def retry(times=3, delay=1):
    def decorator(fn):
        @functools.wraps(fn)
        def wrapper(*args, **kwargs):
            for attempt in range(times):
                try:
                    return fn(*args, **kwargs)
                except Exception as e:
                    if attempt == times - 1:
                        raise
                    time.sleep(delay * (2 ** attempt))
        return wrapper
    return decorator


# ============================================================================
# 4. MCP TOOL REGISTRY (role-aligned — R2 design)
# ============================================================================

from typing import Callable, Any

class MCPToolRegistry:
    def __init__(self):
        self._tools: dict[str, dict] = {}  # name -> {schema, handler}

    def register(self, name: str, schema: dict, handler: Callable) -> None:
        self._tools[name] = {"schema": schema, "handler": handler}

    def invoke(self, name: str, params: dict) -> Any:
        if name not in self._tools:
            raise ValueError(f"Unknown tool: {name}")
        # In real system: validate params against JSON schema
        return self._tools[name]["handler"](**params)


# ============================================================================
# 5. THREAD-SAFE COUNTER (concurrency — R2)
# ============================================================================

import threading

class ThreadSafeCounter:
    def __init__(self):
        self._value = 0
        self._lock = threading.Lock()

    def increment(self):
        with self._lock:
            self._value += 1

    def get(self):
        with self._lock:
            return self._value


# ============================================================================
# 6. PYTHON GOTCHAS (R2 conceptual — not DSA)
# ============================================================================

# Mutable default trap:
def good(x, lst=None):
    if lst is None:
        lst = []
    lst.append(x)
    return lst

# [[]]*3 vs [[] for _ in range(3)]


"""
INTERVIEW TIPS (R2 — Python):
1. LRU + Rate limiter — tie to Paytm caching story
2. MCP registry — bridge to Acrobat MCP at Adobe
3. Always @functools.wraps in decorators
4. GIL: I/O-bound → async/threading; CPU-bound → multiprocessing
5. R1 DSA is C++ — don't mix up in interview
"""
