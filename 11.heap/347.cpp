// 前K个高频元素

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (int& n : nums) {
        hash[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    for (auto& it : hash) {
        minheap.push({it.second, it.first});
        if (minheap.size() > k) {
            minheap.pop();
        }
    }

    vector<int> ans;
    while (k > 0) {
        ans.push_back(minheap.top().second);
        minheap.pop();
        k--;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    reverse(ans.begin(), ans.end());
    for (int& n : ans) {
        cout << n << " ";
    }
    return 0;
}