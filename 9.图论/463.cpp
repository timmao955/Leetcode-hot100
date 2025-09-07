// 岛屿的周长

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
        return 1;
    }
    if (visited[x][y]) {
        return 0;
    }
    visited[x][y] = true;
    int L = 0;
    for (auto& d : dir) {
        int x_next = x + d[0];
        int y_next = y + d[1];
        L += dfs(grid, visited, x_next, y_next);
    }
    return L;
}

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return dfs(grid, visited, i, j);
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << islandPerimeter(grid);

    return 0;
}