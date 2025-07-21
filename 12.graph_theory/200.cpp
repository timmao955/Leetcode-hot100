// 岛屿数量

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y] == true) {
        return;
    }
    visited[x][y] = true;
    for (auto& d : dir) {
        int next_x = x + d[0];
        int next_y = y + d[1];
        dfs(grid, visited, next_x, next_y);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && visited[i][j] == false) {
                ans++;
                dfs(grid, visited, i, j);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };    
    cout << numIslands(grid);
    return 0;
}