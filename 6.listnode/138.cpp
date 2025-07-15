// 随机链表的复制

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node (int x) {
        val = x;
        next = nullptr;
        random = nullptr;
    }
    Node (int x, Node* n, Node* r) {
        val = x;
        next = n;
        random = r;
    }
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    
    for (Node* cur = head; cur; cur = cur->next->next) {
        cur->next = new Node(cur->val, cur->next, nullptr);
    }

    for (Node* cur = head; cur; cur = cur->next->next) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        }
    }

    Node* cur = head;
    Node* new_head = head->next;

    for (; cur->next->next; cur = cur->next) {
        Node* copy = cur->next;
        cur->next = copy->next;
        copy->next = copy->next->next;
    }
    cur->next = nullptr;
    return new_head;
}

int main () {
    // 创建所有节点
    Node* node0 = new Node(7);
    Node* node1 = new Node(13);
    Node* node2 = new Node(11);
    Node* node3 = new Node(10);
    Node* node4 = new Node(1);

    // 链接next指针
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // 链接random指针
    node0->random = nullptr;
    node1->random = node0;    // 13 -> 7
    node2->random = node4;    // 11 -> 1
    node3->random = node2;    // 10 -> 11
    node4->random = node0;    // 1  -> 7

    Node* head = copyRandomList(node0);

    return 0;
}