// 缺失的第一个正数

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    unordered_map<int, int> hash;
    for (int& n : nums) {
        hash[n]++;
    }
    for (int i = 1; i < INT_MAX; i++) {
        if (hash.find(i) != hash.end()) {
            continue;
        } else {
            return i;
        }
    }
    return INT_MAX;
}

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << firstMissingPositive(nums);
    return 0;
}