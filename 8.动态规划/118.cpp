// 杨辉三角

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp(numRows);
    for (int i = 0; i < numRows; i++) {
        dp[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp;
}

int main () {
    vector<vector<int>> ans = generate(5);
    for (auto& vec : ans) {
        for (auto& num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}