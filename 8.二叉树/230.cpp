// 二叉搜索树中第K小的元素

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

int i = 0;
int ans = 0;

void dfs(TreeNode* root, int k) {
    if (root == nullptr) {
        return;
    }
    dfs(root->left, k);
    i++;
    if (i == k) {
        ans = root->val;
        return;
    }
    dfs(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    cout << kthSmallest(root, 2);

    return 0;
}