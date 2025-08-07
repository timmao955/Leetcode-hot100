// 旋转图像

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (auto& row : matrix) {
        int l = 0;
        int r = row.size() - 1;
        while (l <= r) {
            swap(row[l], row[r]);
            l++;
            r--;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for (auto& row : matrix) {
        for (int& col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}