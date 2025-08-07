// 二叉树的中序遍历

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

void traversal (TreeNode* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    traversal(root->left, ans);
    ans.push_back(root->val);
    traversal(root->right, ans);
}

vector<int> inorderTraversal (TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
}

int main () {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);

    for (int& n : ans) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}