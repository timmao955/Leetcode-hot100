// 二叉树的右视图

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

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    if (root != nullptr) {
        q.push(root);
    }
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (i == n - 1) {
                ans.push_back(node->val);
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightSideView(root);

    for (int& n : ans) {
        cout << n << " ";
    }

    return 0;
}