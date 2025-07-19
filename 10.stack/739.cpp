// 每日温度

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& t) {
    stack<int> st;
    vector<int> ans(t.size(), 0);
    st.push(0);
    for (int i = 1; i < t.size(); i++) {
        if (t[st.top()] >= t[i]) {
            st.push(i);
        } else {
            while (!st.empty() && t[st.top()] < t[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

int main() {
    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(t);
    for (int& n : ans) {
        cout << n << " ";
    }
    return 0;
}