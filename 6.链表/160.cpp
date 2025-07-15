// 相交链表

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x) {
        val = x;
        next = nullptr;
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
        if (a != nullptr) {
            a = a->next;
        } else {
            a = headB;
        }
        if (b != nullptr) {
            b = b->next;
        } else {
            b = headA;
        }
    }
    return a;
}

int main () {
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    ListNode* ans = getIntersectionNode(headA, headB);
    cout << ans->val << endl;
    return 0;
}