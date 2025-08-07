// 完全平方数

#include <iostream>
#include <vector>
using namespace std;

int numSquares (int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= n; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main () {
    int ans = numSquares(13);
    cout << ans << endl;
    return 0;
}