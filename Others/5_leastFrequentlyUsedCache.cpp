// C++ Program to implement LFU Cache
// using array
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    int timeStamp, cnt;

    Node(int key, int val, int timeStamp) {
        this->key = key;
        this->value = val;
        this->cnt = 1;
        this->timeStamp = timeStamp;
    }
};

class LFUCache {
  
  public:
    int capacity;
    int curSize;
    int curTime;
    vector<Node *> cacheList;

    // Constructor to initialize values
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        curTime = 0;
        cacheList.resize(capacity, nullptr);
    }

    // Function to get the key's value
    int get(int key) {

        curTime++;
        for (int i = 0; i < capacity; i++) {
            if (cacheList[i] != nullptr && cacheList[i]->key == key) {
                cacheList[i]->cnt++;
                cacheList[i]->timeStamp = curTime;
                return cacheList[i]->value;
            }
        }
        return -1;
    }

    // Function to put a key-value pair
    void put(int key, int value) {

        curTime++;

        if (capacity == 0)
            return;

        for (int i = 0; i < capacity; i++) {
            if (cacheList[i] != nullptr && cacheList[i]->key == key) {
                cacheList[i]->value = value;
                cacheList[i]->cnt++;
                cacheList[i]->timeStamp = curTime;
                return;
            }
        }

        if (curSize < capacity) {

            curSize++;
            for (int i = 0; i < capacity; i++) {
                if (cacheList[i] == nullptr) {
                    cacheList[i] = new Node(key, value, curTime);
                    return;
                }
            }
        }

        else {
            int minCnt = INT_MAX, minTime = INT_MAX, minIndex = -1;
            for (int i = 0; i < capacity; i++) {

                if (cacheList[i]->cnt < minCnt ||
                    (cacheList[i]->cnt == minCnt && cacheList[i]->timeStamp < minTime)) {
                    minCnt = cacheList[i]->cnt;
                    minTime = cacheList[i]->timeStamp;
                    minIndex = i;
                }
            }
            cacheList[minIndex] = new Node(key, value, curTime);
        }
    }
};

int main() {

    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cache.put(4, 4);
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";
    cache.put(5, 5);

    return 0;
}