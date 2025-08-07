// 搜索旋转排序数组

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 2;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums.back()) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int lower_bound(vector<int>& nums, int l, int r, int target) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return nums[l] == target ? l : -1;
}

int search(vector<int>& nums, int target) {
    int i = findMin(nums);
    if (target < nums.back()) return lower_bound(nums, i, nums.size() - 1, target);
    return lower_bound(nums, 0, i - 1, target);
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;
    return 0;
}