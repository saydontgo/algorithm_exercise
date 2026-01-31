#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        int res = last;
        for (int i = 1; i < nums.size(); i++) {
            last = max(nums[i], nums[i] + last);
            res = max(last, res);
        }
        return res;
    }
};