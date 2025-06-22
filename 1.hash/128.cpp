// 最长连续序列

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> hash(nums.begin(), nums.end());
    for (int n : hash) {
        if (hash.find(n - 1) != hash.end()) {
            continue;
        }
        int m = n + 1;
        while (hash.find(m) != hash.end()) {
            m++;
        }
        ans = max(ans, m - n);
    }
    return ans;
}

int main () {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}