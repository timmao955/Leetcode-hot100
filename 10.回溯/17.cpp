// 电话号码的字母组合

#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
string s;

const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

void backtracking(string digits, int index) {
    if (s.size() == digits.size()) {
        ans.push_back(s);
        return;
    }
    int num = digits[index] - '0';
    string letters = letterMap[num];
    for (int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);
        backtracking(digits, index + 1);
        s.pop_back();
    } 
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return ans;
    }
    backtracking(digits, 0);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    for (string& a : res) {
        cout << a << endl;
    }
    return 0;
}