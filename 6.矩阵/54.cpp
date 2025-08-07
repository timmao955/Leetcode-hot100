// 螺旋矩阵

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int u = 0;
    int d = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while (true) {
        for (int i = l; i <= r; i++) {
            ans.push_back(matrix[u][i]);
        }
        u++;
        if (u > d) {
            break;
        }
        for (int i = u; i <= d; i++) {
            ans.push_back(matrix[i][r]);
        }
        r--;
        if (r < l) {
            break;
        }
        for (int i = r; i >= l; i--) {
            ans.push_back(matrix[d][i]);
        }
        d--;
        if (d < u) {
            break;
        }
        for (int i = d; i >= u; i--) {
            ans.push_back(matrix[i][l]);
        }
        l++;
        if (l > r) {
            break;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder(matrix);
    for (int& n : ans) {
        cout << n << " ";
    }
    
    return 0;
}