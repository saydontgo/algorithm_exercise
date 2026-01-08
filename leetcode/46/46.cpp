#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int>& tmp, vector<vector<int>>& res, vector<int>& visited) {
        if (index >= nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                tmp.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums, index + 1, tmp, res, visited);
                visited[i] = 0;
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> visited(nums.size(), 0);
        dfs(nums, 0, tmp, res, visited);
        return res;
    }
};