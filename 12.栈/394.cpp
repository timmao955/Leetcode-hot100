// 字符串解码

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string decodeString(string s) {
    stack<int> st1;
    stack<string> st2;
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            cnt = cnt * 10 + s[i] - '0';
        } else if (isalpha(s[i])) {
            ans += s[i];
        } else if (s[i] == '[') {
            st1.push(cnt);
            cnt = 0;
            st2.push(ans);
            ans = "";
        } else {
            int n = st1.top();
            st1.pop();
            for (int j = 0; j < n; j++) {
                st2.top() += ans;
            }
            ans = st2.top();
            st2.pop();
        }
    }
    return ans;
}

int main() {
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s);
    return 0;
}