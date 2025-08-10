// 二叉树的层序遍历

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

void dfs(TreeNode* root, vector<vector<int>>& ans, int depth) {
    if (root == nullptr) {
        return;
    }
    if (ans.size() == depth) {
        ans.push_back(vector<int>());
    }
    ans[depth].push_back(root->val);
    dfs(root->left, ans, depth + 1);
    dfs(root->right, ans, depth + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    int depth = 0;
    dfs(root, ans, depth);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);

    for (auto& vec : ans) {
        for (int& n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}