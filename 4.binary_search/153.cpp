// 寻找旋转排序数组中的最小值

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
    return nums[l];
}

int main() {
    vector<int> nums = {3,4,5,1,2};
    cout << findMin(nums) << endl;
    return 0;
}