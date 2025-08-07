// 最长回文子串

#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_length = 0;
    int left = 0, right = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) {
                    dp[i][j] = 1;
                } else {
                    if (dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                    }
                }
            }
            if (dp[i][j] == 1 && j - i + 1 > max_length) {
                max_length = j - i + 1;
                left = i;
                right = j;
            }
        }
    }
    return s.substr(left, right - left + 1);
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}