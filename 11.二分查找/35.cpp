// 搜索插入位置

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main () {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int ans = searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}