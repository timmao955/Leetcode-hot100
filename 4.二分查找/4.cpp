// 寻找两个正序数组的中位数

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) {
        swap(a, b);
    }

    int m = a.size(), n = b.size();
    a.insert(a.begin(), INT_MIN);
    b.insert(b.begin(), INT_MIN);
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);

    int left = 1, right = m;
    while (left <= right) {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;
        if (a[i] <= b[j + 1]) {
            left = i + 1;
        } else {
            right = i - 1;
        }
    }

    int i = right;
    int j = (m + n + 1) / 2 - i;
    int max1 = max(a[i], b[j]);
    int min2 = min(a[i + 1], b[j + 1]);
    return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
}

int main () {
    vector<int> nums1 = {1,3}, nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
