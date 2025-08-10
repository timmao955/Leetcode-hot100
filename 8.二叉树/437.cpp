// 路径总和III

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

int ans = 0;

void dfs2(TreeNode* root, long long sum, int targetSum) {
    if (root == nullptr) {
        return;
    }
    sum += root->val;
    if (sum == targetSum) {
        ans++;
    }
    dfs2(root->left, sum, targetSum);
    dfs2(root->right, sum, targetSum);
}

void dfs1(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return;
    }
    dfs2(root, 0, targetSum);
    dfs1(root->left, targetSum);
    dfs1(root->right, targetSum);
}

int pathSum(TreeNode* root, int targetSum) {
    dfs1(root, targetSum);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);

    cout << pathSum(root, 8);

    return 0;
}