#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int max = row < col ? row : col;
    int max_edge = 0;
    int dp[row][col];
    memset(dp, 0, row * col * sizeof(int));

    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == '1') { dp[0][i] = 1; max_edge = 1; }
    }

    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == '1') { dp[i][0] = 1; max_edge = 1; }
    }

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j]++;
                if (dp[i][j] > max_edge) {
                    max_edge = dp[i][j];
                }
            }
        }
    }

    return max_edge * max_edge;
}

int main() {
    return 0;
}