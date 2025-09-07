// 合并K个升序链表

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

struct comparator {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy;
    ListNode* cur = &dummy;
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    for (ListNode* head : lists) {
        if (head != nullptr) {
            pq.push(head);
        }
    }
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        if (node->next != nullptr) {
            pq.push(node->next);
        }
        cur->next = node;
        cur = cur->next;
    }
    return dummy.next;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* ans = mergeKLists(lists);

    for (ListNode* cur = ans; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }

    return 0;
}