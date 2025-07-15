// 两辆交换链表中的节点

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x) {
        val = x;
        next = nullptr;
    }
    ListNode (int x, ListNode* n) {
        val = x;
        next = n;
    }
};

ListNode* swapPairs(ListNode* head) {
    ListNode dummy{0, head};
    ListNode* n0 = &dummy;
    ListNode* n1 = head;
    while (n1 && n1->next) {
        ListNode* n2 = n1->next;
        ListNode* n3 = n1->next->next;
        n0->next = n2;
        n1->next = n3;
        n2->next = n1;

        n0 = n1;
        n1 = n3;
    }
    return dummy.next;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* ans = swapPairs(head);

    while (ans) {
        cout << ans->val << "";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}