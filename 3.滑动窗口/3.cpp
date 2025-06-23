// 无重复字符的最长子串

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> hash;
    int ans = 0;
    int last = -1; // 上一个重复字母的位置
    for (int i = 0; i < s.size(); i++) {
        if (hash.find(s[i]) != hash.end()) {
            last = max(last, hash.find(s[i])->second);
        }
        hash[s[i]] = i;
        ans = max(ans, i - last);
    }
    return ans;
}

int main () {
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}