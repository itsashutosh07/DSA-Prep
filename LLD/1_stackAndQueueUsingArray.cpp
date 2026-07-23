#include <bits/stdc++.h>

using namespace std;

class StackArrImpl {
private:
    int* st;
    int capacity;
    int topIdx;

public:
    StackArrImpl(int n) {
        st = new int[n];
        capacity = n;
        topIdx = -1;
    }

    ~StackArrImpl() {
        delete[] st;
    }

    bool isEmpty() {
        // check if the stack is empty
        return topIdx < 0;
    }

    bool isFull() {
        // check if the stack is full
        return topIdx + 1 >= capacity;
    }

    void push(long long x) {
        // inserts x at the topIdx of the stack
        if (!isFull()) {
            st[topIdx+1] = x;
            topIdx++;
            cout << "Element push(" << x << ") successfull." << endl;
            return;
        }
        cout << "Could not push(" << x << ") since stack is full." << endl;
    }

    void pop() {
        // removes an element from the topIdx of the stack
        long long temp;
        if(!isEmpty()) {
            temp = st[topIdx];
            topIdx--;
            cout << "Element : " << temp << " was poped from stack." << endl;
            return;
        }
        cout << "Could not pop() element since stack is empty." << endl;
    }

    int top() {
        // Returns the topIdx element of the stack
        if (!isEmpty()) {
            cout << "Top : " << st[topIdx] << endl;
            return st[topIdx];
        }
        cout << "Could not peek() since stck is empty.";
        return -1;
    }

    int size() {
        return topIdx+1;
    }
};

int main()
{
    // Initialisation
    StackArrImpl st(10);

    // Operations
    cout << st.size() << endl;

    cout << ((st.isEmpty() == 1) ? "true" : "false") << endl;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << ((st.isEmpty() == 1) ? "true" : "false") << endl;
    
    st.pop();
    st.pop();

    cout << ((st.isEmpty() == 1) ? "true" : "false") << endl;

    st.pop();
    st.pop();

    cout << ((st.isEmpty() == 1) ? "true" : "false") << endl;

    st.pop();

    cout << ((st.isEmpty() == 1) ? "true" : "false") << endl;
    
    st.push(10);
    st.push(11);
    st.push(12);
    
    st.pop();
    
    st.top();

    cout << st.size() << endl;

    return 0;
}