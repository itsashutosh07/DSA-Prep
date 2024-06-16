#include <iostream>
#include <stack>
#include <queue>
#include <chrono>  // Include the chrono library

using namespace std;
using namespace std::chrono;  // Use the chrono namespace for convenience

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

struct NodeWithLevel {
    Node* parent;
    Node* n;
    int level;
    NodeWithLevel(Node* _n, Node* _p, int _l) : n(_n), parent(_p), level(_l) {}
};

class TreeNode {
public:
    int val;
    int height;
    int maxHeight;
    bool placeholder;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), height(0), maxHeight(0), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(int x, int h) : val(x), height(h), maxHeight(0), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(int x, int h, int mh) : val(x), height(h), maxHeight(mh), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(bool ph, int h) : val(0), height(h), maxHeight(0), placeholder(ph), left(NULL), right(NULL) {}
};

template<typename T>
void printStack(const stack<T>& stk) {
    stack<T>cpy(stk);
    cout << "Top:: ";
    while(!cpy.empty()) {
        cout << cpy.top();
        cpy.pop();
        if (!cpy.empty()) cout << " -> ";
    }
    cout << " ::Bottom" << endl;
};

template<typename T>
void printVector(const vector<T>& vct, const string delim = " ", const string linebreak = "\n") {
    for(size_t i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << delim;
    }
    cout << linebreak;
}

template<typename T>
void printArray(const T* arr, size_t size, const string delim = " ", const string linebreak = "\n") {
    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << delim;
    }
    cout << linebreak;
}

template<typename T>
void printMatrix(const vector< vector<T> >& mat, const string delim = " ", const string linebreak = "\n") {
    for(size_t i = 0; i < mat.size(); i++)
    {
        printVector(mat[i], delim, linebreak);
    }
    cout << linebreak;
}

template<typename T>
void printFormattedMatrix(const vector<vector<T>>& mat, const string& start = "[", const string& end = "]", 
        const string& lineBreak = "") {
    cout << start << lineBreak;
    for (size_t i = 0; i < mat.size(); i++) 
    {
        if (lineBreak != "") cout << " ";
        cout << start;
        for (size_t j = 0; j < mat[i].size(); j++) 
        {
            cout << mat[i][j];
            if (j != mat[i].size() - 1) {
                cout << ",";
            }
        }
        cout << end;
        if (i != mat.size() - 1) {
            cout << ",";
        }
        cout << lineBreak;
    }
    cout << end << endl;
}

template<typename T>
vector<T> vectorFromArray(const T arr[], size_t asz) {
    return vector<T> (arr, arr+asz/sizeof(T));
}

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void printList(ListNode* head, bool verbose = false) {
    if (!head) {
        printf("NULL head.\n");
        return;
    }
    while (head) {
        if (verbose)
            printf("%d:%p", head->val, head);
        else
            printf("%d", head->val);
            
        if (head -> next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void printTree(TreeNode* root) {
    if (!root) {
        printf("Null Tree\n");
        return; 
    }
    // bfs
    queue<TreeNode*> q;
    q.push(root);
    int curH = root->height;
    int maxH = root->maxHeight;
    int pad = maxH - curH + 1;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (!cur->placeholder) {
            if (cur->height > curH) {
                curH = cur->height;
                pad = maxH - curH + 1;
                printf("\n");
            }
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            printf("%d", cur->val);
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            // Do not iterate leaf child
            if (cur->left || cur->right) {
                if (cur->left)
                    q.push(cur->left);
                else
                    q.push(new TreeNode(true, curH+1));

                if (cur->right)
                    q.push(cur->right);
                else
                    q.push(new TreeNode(true, curH+1));
            }
        }
        else {
            if (cur->height > curH) {
                curH = cur->height;
                pad = maxH - curH + 1;
                printf("\n");
            }
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            printf("nul");
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
        }
    }
    printf("\n");
}

ListNode* makeList(vector<int>& v) {
    ListNode *h, *p;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            h = new ListNode(v[i]);
            p = h;
        }
        else {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
    return h;
}

Node* makeDoublyLinkedList(vector<int>& v) {
    Node *h = nullptr, *p1 = nullptr;

    if (v.size() == 0) return h;
    if (v.size() == 1) {
        h = new Node(v[0], nullptr, nullptr, nullptr);
        return h;
    }

    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            h = new Node(v[i], nullptr, nullptr, nullptr);
            p1 = h;
        }
        else {
            p1->next = new Node(v[i], nullptr, nullptr, nullptr);
            p1->next->prev = p1;
            p1 = p1->next;
        }
    }

    return h;
}

//@return: last element;
Node* printDListForward(Node* forh, bool verbose) {

    Node* end;

    if (forh == nullptr) {
        cout << "null head" << endl;
        return nullptr;
    }

    while (forh) {
        if (!verbose)
            printf("%d", forh->val);
        else
            printf("%d:%p", forh->val, forh);
        if (forh->next) {
            printf(" -> ");
        }
        else {
            end = forh;
        }
        forh = forh->next;
    }
    printf("\n");

    return end;
}

//@return: last element;
Node* printDListForward(Node* forh, bool verbose, queue<NodeWithLevel*>& childs, int level) {

    Node* end;

    if (forh == nullptr) {
        cout << "null head" << endl;
        return nullptr;
    }

    while (forh) {
        if (!verbose)
            printf("%d", forh->val);
        else
            printf("%d:%p", forh->val, forh);
        
        if (forh->next) {
            printf(" -> ");
        }
        else {
            end = forh;
        }

        if (forh->child) {
            childs.push(new NodeWithLevel(forh->child, forh, level+1));
        }

        forh = forh->next;
    }

    return end;
}

void printDListBackward(Node* bckh, bool verbose) {
    if (bckh == nullptr) {
        cout << "null head" << endl;
    }

    while (bckh) {
        if (!verbose)
            printf("%d", bckh->val);
        else
            printf("%d:%p", bckh->val, bckh);
        if (bckh->prev) {
            printf(" <- ");
        }
        bckh = bckh->prev;
    }
    printf("\n");
}

void printDListTwoWay(Node* h, bool verbose) {
    Node* end = printDListForward(h, verbose);
    printDListBackward(end, verbose);
}

void insertChildListAt(int at, Node* h_parent, Node* h_child) {
    for (int i = 1; i <= at; i++) h_parent = h_parent->next;
    h_parent->child = h_child;
}

void printListWithChild(Node* h, bool verbose) {
    queue<NodeWithLevel*> cHeads;
    cHeads.push(new NodeWithLevel(h, nullptr, 0));

    int curL = 0;
    while(!cHeads.empty()) {
        NodeWithLevel *pl = cHeads.front();
        cHeads.pop();

        if (pl->level > curL) {
            curL = pl->level;
            printf("\n");
        }
        Node *p = pl->n;

        if (pl->parent) {
            if (verbose) {
                printf("|From %d:%p| ", pl->parent->val, pl->parent);
            }
            else {
                printf("|From %d| ", pl->parent->val);
            }
        }
        printDListForward(p, verbose, cHeads, curL);
        printf("\t");
    }

    printf("\n");
}

// Function to measure and print the time taken by a sorting function (two-parameter version)
void measureSortTime(void (*sortFunc)(int[], int), int arr[], int n, const string& sortName)
{
    int trials = 25;
    double totalDuration = 0.0;

    for (int t = 0; t < trials; t++) {
        auto start = high_resolution_clock::now(); // Start the timer
        sortFunc(arr, n);                          // Sort the original array
        auto end = high_resolution_clock::now();   // End the timer

        auto duration = duration_cast<microseconds>(end - start).count(); // Calculate duration in microseconds
        totalDuration += duration;
    }

    double avgDurationMicroseconds = totalDuration / trials;
    double avgDurationSeconds = avgDurationMicroseconds / 1'000'000.0; // Convert microseconds to seconds

    cout << sortName << ": " << endl;
    cout << fixed << setprecision(4);
    cout << "Average Time Taken: " << avgDurationMicroseconds << " µs (" << avgDurationSeconds << " seconds)" << endl << endl;
}

// Overloaded measureSortTime function for merge sort (three-parameter version)
void measureSortTime(void (*sortFunc)(int[], int, int), int arr[], int l, int r, const string& sortName)
{
    int trials = 25;
    double totalDuration = 0.0;

    for (int t = 0; t < trials; t++) {
        auto start = high_resolution_clock::now(); // Start the timer
        sortFunc(arr, l, r);                       // Sort the subarray arr[l...r]
        auto end = high_resolution_clock::now();   // End the timer

        auto duration = duration_cast<microseconds>(end - start).count(); // Calculate duration in microseconds
        totalDuration += duration;
    }

    double avgDurationMicroseconds = totalDuration / trials;
    double avgDurationSeconds = avgDurationMicroseconds / 1'000'000.0; // Convert microseconds to seconds

    cout << sortName << ": " << endl;
    cout << fixed << setprecision(4);
    cout << "Average Time Taken: " << avgDurationMicroseconds << " µs (" << avgDurationSeconds << " seconds)" << endl << endl;
}


