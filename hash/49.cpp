// 字母异位词分组

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> hash;
    for (string& s : strs) {
        string sort_s = s;
        sort(sort_s.begin(), sort_s.end());
        hash[sort_s].push_back(s);
    }
    for (auto& pair : hash) {
        ans.push_back(pair.second);
    }
    return ans;
}

int main () {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (vector<string>& v : ans) {
        for (string& s : v) {
            cout << s << " ";
        }
    }
    cout << endl;
    return 0;
}