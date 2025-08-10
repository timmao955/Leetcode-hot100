// 对称二叉树

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

bool compare(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right != nullptr) {
        return false;
    } else if (left != nullptr && right == nullptr) {
        return false;
    } else if (left == nullptr && right == nullptr) {
        return true;
    } else if (left->val != right->val) {
        return false;
    }
    bool inside = compare(left->right, right->left);
    bool outside = compare(left->left, right->right);
    return inside && outside;
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return compare(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << isSymmetric(root);

    return 0;
}