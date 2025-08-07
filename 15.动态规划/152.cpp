// 乘积最大字数组

#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    vector<int> dp_max(n), dp_min(n);
    dp_max[0] = dp_min[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp_max[i] = max({nums[i], dp_max[i - 1]*nums[i], dp_min[i - 1]*nums[i]});
        dp_min[i] = min({nums[i], dp_max[i - 1]*nums[i], dp_min[i - 1]*nums[i]});
        ans = max(ans, dp_max[i]);
    }
    return ans;
}

int main () {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    return 0;
}