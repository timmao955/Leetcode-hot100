// 合并两个有序链表

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    cur->next = list1 == nullptr ? list2 : list1;
    return dummy.next;
}

int main () {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* ans = mergeTwoLists(list1, list2);
    
    while (ans != nullptr) {
        cout << ans->val << "";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}