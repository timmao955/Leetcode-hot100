// 滑动窗口最大值

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() >= k) {
            q.pop_front();
        }
        if (i >= k -1) {
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int& n : ans) {
        cout << n << "";
    }
    cout << endl;
    return 0;
}