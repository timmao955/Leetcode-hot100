#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

void QuickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = partition(nums, left, right);
    QuickSort(nums, left, mid - 1);
    QuickSort(nums, mid + 1, right);
}

int main() {
    vector<int> nums = {4,1,3,2,5,1};
    QuickSort(nums, 0, nums.size() - 1);
    for (int& n : nums) {
        cout << n << " ";
    }

    return 0;
}