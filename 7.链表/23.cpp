// 合并K个升序链表

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nums;
    for (auto& l : lists) {
        ListNode* cur = l;
        while (cur != nullptr) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
    }
    sort(nums.begin(), nums.end());
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int i = 0; i < nums.size(); i++) {
        ListNode* tmp = new ListNode(nums[i]);
        cur->next = tmp;
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