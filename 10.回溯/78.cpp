// 子集

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracking(vector<int>& nums, int start) {
    ans.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    backtracking(nums, 0);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    for (vector<int>& vec : res) {
        for (int& n : vec) {
            cout << n << "";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}