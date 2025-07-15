// 删除链表的倒数第N个节点

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy{0, head};
    ListNode* slow = &dummy, *fast = &dummy;
    while (n--) {
        fast = fast->next;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* ans = removeNthFromEnd(head, n);

    while (ans) {
        cout << ans->val << "";
        ans = ans->next;
    }

    cout << endl;
    return 0;
}
