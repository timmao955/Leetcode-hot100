// 打家劫舍

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    vector<int> dp(n + 1);
    dp[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
}

int main () {
    vector<int> nums = {2,7,9,3,1};
    int ans = rob(nums);
    cout << ans << endl;
    return 0;
}