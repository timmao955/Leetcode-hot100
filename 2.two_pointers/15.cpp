// 三数之和

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            return ans;
        }
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                ans.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[r - 1] == nums[r]) {
                    r--;
                }
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                l++;
                r--;
            }
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto& v : ans) {
        for (auto& n : v) {
            cout << n << " ";
        }
    }
    cout << endl;
    return 0;
}