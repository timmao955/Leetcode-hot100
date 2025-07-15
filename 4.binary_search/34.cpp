// 在排序数组中查找元素的第一个和最后一个的位置

#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start = lower_bound(nums, target);
    if (start == nums.size() || nums[start] != target) {
        return {-1, -1};
    }
    int end = lower_bound(nums, target + 1) - 1;
    return {start, end};
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    for (int& n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}