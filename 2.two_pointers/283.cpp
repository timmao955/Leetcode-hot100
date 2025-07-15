// 移动零

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int i0 = 0; // i0表示下一个非零元素存放的位置
    for (int& n : nums) {
        if (n) {
            swap(n, nums[i0]);
            i0++;
        }
    }
}

int main () {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int& n : nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}