// 单词拆分

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak (string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            string word = s.substr(j, i - j);
            if (dict.find(word) != dict.end() && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main () {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}