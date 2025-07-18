// 爬楼梯

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n == 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main () {
    int ans = climbStairs(3);
    cout << ans << endl;
    return 0;
}