// 轮转数组

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    for (int& n : nums) {
        cout << n << " ";
    }
    return 0;
}