// 除自身以外数组的成积

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    int tmp = 1;
    for (int i = 1; i < nums.size(); i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    for (int j = nums.size() - 2; j >= 0; j--) {
        tmp *= nums[j + 1];
        ans[j] *= tmp;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for (int& n : ans) {
        cout << n << " ";
    }
    return 0;
}