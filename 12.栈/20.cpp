// 有效的括号

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(')');
        } else if (s[i] == '[') {
            st.push(']');
        } else if (s[i] == '{') {
            st.push('}');
        } else if (st.empty() || st.top() != s[i]) {
            return false;
        } else {
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";
    cout << isValid(s);
    return 0;
}