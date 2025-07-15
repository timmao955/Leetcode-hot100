// 最长有小括号

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    if (s.size() == 0 || s.size() == 1) {
        return 0;
    }
    stack<int> st;
    int ans = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                start  = i + 1;
            } else {
                st.pop();
                if (!st.empty()) {
                    ans = max(ans, i - st.top());
                } else {
                    ans = max(ans, i - start + 1);
                }
            }
        }
    }
    return ans;
}

int main () {
    string s = ")()())";
    cout << longestValidParentheses(s) << endl;
    return 0;
}