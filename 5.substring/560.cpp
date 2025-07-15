// 和为K的子数组

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    // 前缀和
    vector<int> s(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
        s[i + 1] = s[i] + nums[i];
    }

    unordered_map<int, int> hash;
    for (int j = 0; j < s.size(); j++) {
        if (hash.find(s[j] - k) != hash.end()) {
            ans += hash[s[j] - k];
        }
        hash[s[j]]++;
    }
    return ans;
}

int main () {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << subarraySum(nums, k) << endl;
    return 0;
}