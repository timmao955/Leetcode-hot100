// 二叉树中的最近公共祖先

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

TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q || root == nullptr) {
        return root;
    }
    TreeNode* left = traversal(root->left, p, q);
    TreeNode* right = traversal(root->right, p, q);
    if (left != nullptr && right != nullptr) {
        return root;
    }
    if (left != nullptr) {
        return left;
    }
    return right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traversal(root, p, q);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    TreeNode* ans = lowestCommonAncestor(root, root->left, root->right);
    cout << ans->val;

    return 0;
}