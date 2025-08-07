// 跳跃游戏

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int cover = 0;
    if (nums.size() == 1) {
        return true;
    }
    for (int i = 0; i <= cover; i++) {
        cover = max(cover, i + nums[i]);
        if (cover >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums);

    return 0;
}