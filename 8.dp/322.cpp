// 零钱兑换

#include <iostream>
#include <vector>
using namespace std;

int coinChange (vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}

int main () {
    vector<int> coin = {1,2,5};
    int amount = 11;
    int ans = coinChange(coin, amount);
    cout << ans << endl;
    return 0;
}