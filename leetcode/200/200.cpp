#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int flag[310][310], int i, int j) {
    flag[i][j] = 1;
    if (i - 1 > -1 && grid[i - 1][j] == '1' && flag[i - 1][j] == 0) {
        dfs(grid, flag, i - 1, j);
    }
    if (i + 1 < grid.size() && grid[i + 1][j] == '1' && flag[i + 1][j] == 0) {
        dfs(grid, flag, i + 1, j);
    }
    if (j - 1 > -1 && grid[i][j - 1] == '1' && flag[i][j - 1] == 0) {
        dfs(grid, flag, i, j - 1);
    }
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' && flag[i][j + 1] == 0) {
        dfs(grid, flag, i, j + 1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int flag[310][310];
    memset(flag, 0, sizeof(int) * 310 * 310);
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1' && flag[i][j] == 0) {
                dfs(grid, flag, i, j);
                res++;
            }
        }
    }
    return res;
}
int main() {
    return 0;
}