// 两数相加

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode () {
        val = 0;
        next = nullptr;
    }
    ListNode (int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* cur = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        cur->next = new ListNode(carry % 10);
        cur = cur->next;
        carry /= 10;
    }
    return dummy.next;
}

int main () {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* ans = addTwoNumbers(l1, l2);

    while (ans) {
        cout << ans->val << "";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}