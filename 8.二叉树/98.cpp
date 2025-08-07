// 验证二叉搜索树

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

TreeNode* last = nullptr;

bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    bool left = isValidBST(root->left);
    if (last != nullptr && last->val >= root->val) {
        return false;
    }
    last = root;
    bool right = isValidBST(root->right);
    return left && right;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << isValidBST(root);

    return 0;
}