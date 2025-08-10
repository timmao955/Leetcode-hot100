// 二叉树中的最大路径和

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

int ans = INT_MIN;

int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    ans = max(left + right + root->val, ans);
    return max(max(left, right) + root->val, 0);
}

int maxPathSum(TreeNode* root) {
    int res = dfs(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxPathSum(root);

    return 0;
}