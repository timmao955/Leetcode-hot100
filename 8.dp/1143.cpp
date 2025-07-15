// 最长公共子序列

#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    int ans = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i] == text2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            if (dp[i][j] > ans) {
                ans = dp[i][j];
            }
        }
    }
    return ans;
}

int main() {
    string text1 = "abcde", text2 = "ace";
    int ans = longestCommonSubsequence(text1, text2);
    cout << ans << endl;
    return 0;
}