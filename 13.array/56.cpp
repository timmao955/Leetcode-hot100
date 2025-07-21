// 合并区间

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++) {
        while (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            i++;
        }
        ans.push_back(intervals[i]);
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for (auto& a : ans) {
        for (auto& n : a) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}