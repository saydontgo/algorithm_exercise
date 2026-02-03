#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& visited, vector<vector<char>>& board, int i, int j, string word, int index) {
        if (word[index] != board[i][j]) { return false; }
        if (index == word.size() - 1) { return true; }
        visited[i][j] = 1;
        int success = 0;
        if (i - 1 > -1 && !visited[i - 1][j]) { success = max(success, dfs(visited, board, i - 1, j, word, index + 1)); }
        if (!success && i + 1 < board.size() && !visited[i + 1][j]) { success = dfs(visited, board, i + 1, j, word, index + 1); }
        if (!success && j - 1 > -1 && !visited[i][j - 1]) { success = dfs(visited, board, i, j - 1, word, index + 1); }
        if (!success && j + 1 < board[0].size() && !visited[i][j + 1]) { success = dfs(visited, board, i, j + 1, word, index + 1); }
        visited[i][j] = 0;
        return success;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int exist = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                exist = max(exist, dfs(visited, board, i, j, word, 0));
            }
        }
        return exist;
    }
};