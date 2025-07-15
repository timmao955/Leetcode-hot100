// 接雨水

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int l = st.top(), r = i, h = min(height[l], height[r]) - height[cur];
            ans += (r - l - 1) * h;
        }
        st.push(i);
    }
    return ans;
}

int main () {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(height);
    cout << ans << endl;
    return 0;
}