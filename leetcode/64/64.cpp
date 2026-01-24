#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> steps(row, vector<int>(col, 0));
        steps[0][0] = grid[0][0];
        for (int i = 1; i < col; i++) {
            steps[0][i] = steps[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; i++) {
            steps[i][0] = steps[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                steps[i][j] = min(steps[i - 1][j], steps[i][j - 1]) + grid[i][j];
            }
        }
        return steps[row - 1][col - 1];
    }
};