// 划分字母区间

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> hebingqujian(vector<vector<int>>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        while (i < nums.size() - 1 && nums[i][1] >= nums[i + 1][0]) {
            nums[i + 1][0] = nums[i][0];
            nums[i + 1][1] = max(nums[i + 1][1], nums[i][1]);
            i++;
        }
        res.push_back(nums[i]);
    }
    return res;
}

vector<int> partitionLabels(string s) {
    unordered_map<char, vector<int>> map;
    vector<vector<int>> res;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        if (map.find(s[i]) != map.end()) {
            map[s[i]][1] = i;
        } else {
            map[s[i]] = vector<int>(2, i);
        }
    }
    for (auto& it : map) {
        res.push_back(it.second);
    }
    vector<vector<int>> res2 = hebingqujian(res);
    for (auto& v : res2) {
        ans.push_back(v[1] - v[0] + 1);
    }
    return ans;
}

int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(s);
    for (int& n : ans) {
        cout << n;
    }
    
    return 0;
}