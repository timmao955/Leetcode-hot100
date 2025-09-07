// 三角形最小路径和

#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(200, vector<int>(200, INT_MAX));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j], dp[i][j]);
        }
    }
    int tmp = INT_MAX;
    for (int k = 0; k < triangle[triangle.size() - 1].size(); k++) {
        if (dp[triangle.size() - 1][k] < tmp) {
            tmp = dp[triangle.size() - 1][k];
        }
    }
    return tmp;
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle);

    return 0;
}