// 回文链表

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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* nxt;
    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    ListNode* mid = middleNode(head);
    ListNode* head2 = reverseList(mid);
    while (head2 != nullptr) {
        if (head->val != head2->val) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << isPalindrome(head) << endl;
    return 0;
}