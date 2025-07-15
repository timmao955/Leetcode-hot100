// 分割等和子集

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int& n : nums) {
        sum += n;
    }
    if (sum % 2 == 1) {
        return false;
    }
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if (dp[target] == target) {
        return true;
    }
    return false;
}

int main () {
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums) << endl;
    return 0;
}