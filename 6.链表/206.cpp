// 反转链表

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

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* nxt;
    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseList(head);

    ListNode* cur = ans;
    
    while (cur != nullptr) {
        cout << cur->val << "";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}