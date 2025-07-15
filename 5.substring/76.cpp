// 最小覆盖子串

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> t_hash;
    for (char& c : t) {
        t_hash[c]++;
    }
    int l = 0;
    int left = -1, right = s.size() - 1;
    int cnt = t_hash.size();
    for (int r = 0; r < s.size(); r++) {
        if (t_hash.find(s[r]) != t_hash.end()) {
            t_hash[s[r]]--;
            if (t_hash[s[r]] == 0) {
                cnt--;
            }
        }
        while (cnt == 0) {
            if (right - left > r - l) {
                right = r;
                left = l;
            }
            if (t_hash.find(s[l]) != t_hash.end()) {
                if (t_hash[s[l]] == 0) {
                    cnt++;
                }
                t_hash[s[l]]++;
            }
            l++;
        }
    }
    return left == -1 ? "" : s.substr(left, right - left + 1);
}

int main () {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}