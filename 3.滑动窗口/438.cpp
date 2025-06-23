// 找到字符串中所有字母异位词

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map<char, int> s_hash;
    unordered_map<char, int> p_hash;
    for (int i = 0; i < p.size(); i++) {
        s_hash[s[i]]++;
    }
    for (int i = 0; i < p.size(); i++) {
        p_hash[p[i]]++;
    }
    int l = 0, r = p.size() - 1;
    while (r < s.size()) {
        if (s_hash == p_hash) {
            ans.push_back(l);
        }
        s_hash[s[l]]--;
        l++;
        if (s_hash[s[l - 1]] == 0) {
            s_hash.erase(s[l - 1]);
        }
        r++;
        s_hash[s[r]]++;
    }
    return ans;
}

int main () {
    string s = "abab", p = "ab";
    vector<int> ans = findAnagrams(s, p);
    for (int& n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}