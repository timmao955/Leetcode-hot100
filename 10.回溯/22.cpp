// 括号生成

#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
string s;

void backtracking(int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(s);
        return;
    }
    if (open > 0) {
        s.push_back('(');
        backtracking(open - 1, close + 1);
        s.pop_back();
    }
    if (close > 0) {
        s.push_back(')');
        backtracking(open, close - 1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    backtracking(n, 0);
    return ans;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (string& a : res) {
        cout << a << endl;
    }
    return 0;
}