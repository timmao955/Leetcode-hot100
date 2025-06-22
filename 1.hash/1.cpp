// 两数之和

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum (vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        auto iter = hash.find(target - nums[i]);
        if (iter != hash.end()) {
            ans.push_back(i);
            ans.push_back(iter->second);
            return ans;
        }
        hash.insert(pair<int, int>(nums[i], i));
    }
    return ans;
} 

int main () {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}