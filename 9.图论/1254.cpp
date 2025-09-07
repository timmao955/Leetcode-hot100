// 封闭岛屿数量

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs1(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true || grid[x][y] == 1) {
        return;
    }
    visited[x][y] = true;
    grid[x][y] = 1;
    for (auto& d : dir) {
        dfs1(grid, visited, x + d[0], y + d[1]);
    }
}

void dfs2(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true || grid[x][y] == 1) {
        return;
    }
    visited[x][y] = true;
    for (auto& d : dir) {
        dfs2(grid, visited, x + d[0], y + d[1]);
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        dfs1(grid, visited, i, 0);
        dfs1(grid, visited, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        dfs1(grid, visited, 0, j);
        dfs1(grid, visited, m - 1, j);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && visited[i][j] == false) {
                ans++;
                dfs2(grid, visited, i, j);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    cout << closedIsland(grid);

    return 0;
}