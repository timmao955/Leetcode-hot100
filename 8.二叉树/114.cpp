// 二叉树展开为链表

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    dfs(root->left);
    dfs(root->right);
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    TreeNode* p = root;
    while (p->right != nullptr) {
        p = p->right;
    }
    p->right = tmp;
}

void interval(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    interval(root->left);
    interval(root->right);
}

void flatten(TreeNode* root) {
    dfs(root);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    flatten(root);
    interval(root);

    return 0;
}