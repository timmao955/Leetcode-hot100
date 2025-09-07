#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);

    // 暂存需合并区间元素
    int tmp[right - left + 1];
    for (int k = left; k <= right; k++) {
        tmp[k - left] = nums[k];  
    }

    // 两指针分别指向左/右子数组的首个元素
    int i = 0, j = mid - left + 1;

    // 遍历合并左/右子数组
    for (int k = left; k <= right; k++) {
        if (i == mid - left + 1)
            nums[k] = tmp[j++];
        else if (j == right - left + 1 || tmp[i] <= tmp[j])
            nums[k] = tmp[i++];
        else { //tmp[i] > tmp[j]
            nums[k] = tmp[j++];
        }
    }
}

int main() {
    vector<int> nums = {4,1,3,2,5,1};
    MergeSort(nums, 0, nums.size() - 1);
    for (int& n : nums) {
        cout << n << " ";
    }

    return 0;
}
    
        