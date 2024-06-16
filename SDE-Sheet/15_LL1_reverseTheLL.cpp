
#include <bits/stdc++.h>
#include "dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: June 14, 2024
// Creation TIME: 12:29:04

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// LEETCODE #206. Reverse Linked List

/*
DESCRIPTION :
    Given the head of a singly linked list, reverse the list, and return the reversed list.


Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
Example 2:
    Input: head = [1,2]
    Output: [2,1]
Example 3:
    Input: head = []
    Output: []
 

Constraints:
    - The number of nodes in the list is the range [0, 5000].
    - -5000 <= Node.val <= 5000

    Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/ 


class Solution {
    public:
    ListNode* reverseList1(ListNode* head) { // iterative
        ListNode* curr = head;
        ListNode* temp = curr;
        ListNode* prev = NULL;

        while(curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;

    }

    ListNode* reverseLL2(ListNode* prev, ListNode* curr) { // recursion
        if (!curr)
            return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        return reverseLL2(curr, temp);
    }
    ListNode* reverseList2(ListNode* head) {
        return reverseLL2(NULL, head);
    }

};


int main() 
{
    Solution sol;

    // Input Initialization
    vector<int> vec1 {1,2,3,4,5};
    ListNode* l1 = makeList(vec1);
    cout << "l1: ";
    printList(l1);

    ListNode* l2Head = new ListNode(1);
    ListNode* l2a = new ListNode(2);
    l2Head->next = l2a;
    ListNode* l2b = new ListNode(3);
    l2a->next = l2b;
    ListNode* l2c = new ListNode(4);
    l2b->next = l2c;
    ListNode* l2d = new ListNode(5);
    l2c->next = l2d;
    ListNode* l2e = new ListNode(6);
    l2d->next = l2e;
    cout << "l2: ";
    printList(l2Head);

    vector<int> vec3 {1};
    ListNode* l3 = makeList(vec3);
    cout << "l3: ";
    printList(l3);

    ListNode* l4 = new ListNode;
    cout << "l4: ";
    printList(l4);


    // Method Invocation
    ListNode* ans1 = sol.reverseList2(l1);
    ListNode* ans2 = sol.reverseList2(l2Head);
    ListNode* ans3 = sol.reverseList2(l3);
    ListNode* ans4 = sol.reverseList2(l4);

    // Result Visualization
    cout << "l1 reverse: ";
    printList(ans1);
    cout << "l2 reverse: ";
    printList(ans2);
    cout << "l3 reverse: ";
    printList(ans3);
    cout << "l4 reverse: ";
    printList(ans4);


    return 0;
}

/*
SOLUTIONS:-

1. O(1) Space & O(n) TC | Brute Force
    traverse each element of matrix and for each element, 

2. O(n+m) Space & O(n^2) TC | Optimized


3.  O(1) extra space & 2O(n^2) TC | OPTIMIZED


*/

