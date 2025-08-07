// 组和总和

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracking(vector<int>& candidates, int target, int sum, int index) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        ans.push_back(path);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, sum, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backtracking(candidates, target, 0, 0);
    return ans;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (vector<int>& vec : res) {
        for (int& n : vec) {
            cout << n << "";
        }
        cout << endl;
    }
    return 0;
}