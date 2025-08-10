// 将有序数组转换为二叉搜索树

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

TreeNode* traversal(vector<int>& nums, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traversal(nums, l, mid - 1);
    root->right = traversal(nums, mid + 1, r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traversal(nums, 0, nums.size() - 1);
    return root;
}

void interval(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    res.push_back(root->val);
    interval(root->left, res);
    interval(root->right, res);
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* ans = sortedArrayToBST(nums);
    vector<int> res;
    interval(ans, res);
    for (int& n : res) {
        cout << n << " ";
    }
    return 0;
}
