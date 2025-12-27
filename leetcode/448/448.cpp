#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int tmp = nums[i] - 1;
            if (tmp & (1 << 30)) {
                tmp -= (1 << 30);
            }
            nums[tmp] |= (1 << 30);
        }
        for (int i = 0; i < n; i++) {
            if ((nums[i] & (1 << 30)) == 0) {
                res.push_back(i + 1);
            } else {
                nums[i] -= (1 << 30);
            }
        }
        return res;
    }
};