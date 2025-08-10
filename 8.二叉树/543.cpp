// 二叉树的直径

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

int ans = 1;

int depth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    ans = max(left + right + 1, ans);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    depth(root);
    return ans - 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    
    cout << diameterOfBinaryTree(root);

    return 0;
}