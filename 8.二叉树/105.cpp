// 从前序与中序遍历序列构造二叉树

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
    TreeNode (int x, TreeNode* _left, TreeNode* _right) {
        val = x;
        left = _left;
        right = _right;
    }
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    int left_size = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
    vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
    vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
    vector<int> in1(inorder.begin(), inorder.begin() + left_size);
    vector<int> in2(inorder.begin() + left_size + 1, inorder.end());
    TreeNode* left = buildTree(pre1, in1);
    TreeNode* right = buildTree(pre2, in2);
    return new TreeNode(preorder[0], left, right);
}

void interval(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    interval(root->left);
    interval(root->right);
}

int main() {
    vector<int >preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    interval(root);

    return 0;
}