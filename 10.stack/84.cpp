// 柱状图中最大的矩形

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] > heights[st.top()]) {
            st.push(i);
        } else if (heights[i] == heights[st.top()]) {
            st.pop();
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int l = st.top();
                    int r = i;
                    int w = r - l - 1;
                    int h = heights[mid];
                    ans = max(ans, w * h);
                }
            }
            st.push(i);
        }
    }
    return ans;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}