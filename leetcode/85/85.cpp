#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        int max_sq = 0;
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    tmp++;
                    left[i][j] = tmp;
                    int min_val = tmp;
                    for (int k = i; k > -1; k--) {
                        if (left[k][j] == 0) { break; }
                        min_val = min(left[k][j], min_val);
                        max_sq = max(max_sq, min_val * (i - k + 1));
                    }
                } else {
                    tmp = 0;
                }
            }
        }
        return max_sq;
    }
};