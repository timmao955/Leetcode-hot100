// 合并两个有序数组

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            swap(nums1[m], nums1[i]);
            i--;
            m--;
        }
        swap(nums1[i], nums2[n]);
        i--;
        n--;
    }
}
int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for (int& n : nums1) {
        cout << n << " ";
    }

    return 0;
}