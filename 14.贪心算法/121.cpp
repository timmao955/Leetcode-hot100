// 买卖股票的最佳时机

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 1) {
        return 0;
    }
    vector<int> dp(n, 0);
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < prices[min_index]) {
            min_index = i;
        }
        dp[i] = max(dp[i - 1], prices[i] - prices[min_index]);
    }
    return dp[n - 1];
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);

    return 0;
}