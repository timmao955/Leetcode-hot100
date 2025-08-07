// 环形链表II

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

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* index1 = head;
            ListNode* index2 = fast;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return nullptr;
}

int main () {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << detectCycle(head)->val << endl;
    return 0;
}