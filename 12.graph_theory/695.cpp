// 岛屿的最大面积

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
        return 0;
    }
    grid[x][y] = 0;

    int S = 1;
    for (auto& d : dir) {
        S += dfs(grid, x + d[0], y + d[1]);
    }
    return S;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid);
    return 0;
}