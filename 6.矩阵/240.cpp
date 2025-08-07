// 搜索二维矩阵II

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        if (target <= matrix[i][n - 1]) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    bool ans = searchMatrix(matrix, target);
    cout << ans;

    return 0;
}