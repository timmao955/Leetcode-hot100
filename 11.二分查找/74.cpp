// 搜索二维矩阵

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> nums;
    for (vector<int>& v : matrix) {
        for (int& n : v) {
            nums.push_back(n);
        }
    }
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

int main () {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}