#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = nums[0];
        int min_val = nums[n - 1];
        int leftp = n - 1;
        int rightp = 0;
        for (int i = 0; i < n; i++) {
            max_val = max(max_val, nums[i]);
            if (nums[i] != max_val) {
                rightp = i;
            }
        }
        for (int i = n - 1; i > -1; i--) {
            min_val = min(min_val, nums[i]);
            if (nums[i] != min_val) {
                leftp = i;
            }
        }

        return leftp < rightp ? rightp - leftp + 1 : 0;
    }
};