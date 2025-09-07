// 零钱兑换II

#include <iostream>
#include <vector>
using namespace std;

int change(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[coins.size()][amount];
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(coins, amount);

    return 0;
}