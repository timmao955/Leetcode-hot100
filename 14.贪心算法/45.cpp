// 跳跃游戏2

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }
    int cur = 0, next = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        next = max(i + nums[i], next);
        if (i == cur) {
            ans++;
            cur = next;
            if (next >= nums.size() - 1) {
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);

    return 0;
}