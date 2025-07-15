// 最长递增子序列

#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS (vector<int>& nums) {
    int n = nums.size();
    int ans = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int ans = lengthOfLIS(nums);
    cout << ans << endl;
    return 0;
}