// 全排列

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true) {
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for (auto& vec : res) {
        for (int& n : vec) {
            cout << n << "";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}