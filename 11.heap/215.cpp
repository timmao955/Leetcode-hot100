// 数组中的第K个最大元素

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int& n : nums) {
        minheap.push(n);
        if (minheap.size() > k) {
            minheap.pop();
        }
    }

    return minheap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(nums, k);
    return 0;
}
