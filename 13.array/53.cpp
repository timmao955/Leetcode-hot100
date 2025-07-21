// 最大字数组和

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}