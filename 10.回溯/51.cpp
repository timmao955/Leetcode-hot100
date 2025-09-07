// N皇后

#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> ans;

void backtracking(int i, int n, vector<int>& col, vector<int>& dg, vector<int>& udg, vector<string>& t) {
    if (i == n) {
        ans.push_back(t);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (col[j] + dg[i + j] + udg[j - i + n] == 0) {
            t[i][j] = 'Q';
            col[j] = dg[i + j] = udg[j - i + n] = 1;
            backtracking(i + 1, n, col, dg, udg, t);
            t[i][j] = '.';
            col[j] = dg[i + j] = udg[j - i + n] = 0;
        }
    }
}

void solveNQueens(int n) {
    vector<int> col(n);
    vector<int> dg(2 * n);
    vector<int> udg(2 * n);
    vector<string> t(n, string(n, '.'));
    backtracking(0, n, col, dg, udg, t);
}

int main() {
    solveNQueens(4);
    for (auto& v : ans) {
        for (string& s : v) {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}