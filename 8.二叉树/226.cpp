// 翻转二叉树

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

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

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void interval(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    ans.push_back(root->val);
    interval(root->left);
    interval(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode* res = invertTree(root);
    interval(res);

    for (int& n : ans) {
        cout << n << " ";
    }

    return 0;
}