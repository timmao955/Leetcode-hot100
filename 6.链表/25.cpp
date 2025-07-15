// K个一组翻转链表

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

ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    ListNode* h = head;
    while (h) {
        n++;
        h = h->next;
    }

    ListNode dummy{0, head};
    ListNode* p0 = &dummy;
    ListNode* cur = head;
    ListNode* pre = nullptr;

    for (; n >= k; n -= k) {
        for (int i = 0; i < k; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode* nxt = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxt;
    }
    return dummy.next;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* ans = reverseKGroup(head, n);

    while (ans) {
        cout << ans->val << "";
        ans = ans->next;
    }

    cout << endl;
    return 0;
}
