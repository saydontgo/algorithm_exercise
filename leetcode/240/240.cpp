#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int col_index = 0;
        int row_index = row - 1;
        while (row_index > -1 && col_index < col) {
            if (matrix[row_index][col_index] == target) {
                return true;
            } else if (matrix[row_index][col_index] > target) {
                row_index--;
            } else {
                col_index++;
            }
        }
        return false;
    }
}; 