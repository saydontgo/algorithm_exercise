#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        while (start < nums.size() && nums[start] != 0) {
            start++;
        }
        while (true) {
            int tmp = start;
            while (tmp < nums.size() && nums[tmp] == 0) {
                tmp++;
            }
            if (tmp >= nums.size()) { break; }
            int cur_batch_max = tmp - start;
            int flag = 0;
            for (int i = start; i < start + cur_batch_max; i++) {
                if (i + cur_batch_max >= nums.size() || nums[i + cur_batch_max] == 0) {
                    flag = 1;
                    start = i;
                    break;
                }
                int tt = nums[i];
                nums[i] = nums[i + cur_batch_max];
                nums[i + cur_batch_max] = tt;
            }
            start = flag ? start : tmp;
        }
    }
};