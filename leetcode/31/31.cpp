#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[n - 1];
        for (int i = n - 2; i > -1; i--) {
            if (nums[i] < tmp) {
                int start = i + 1;
                int end = n - 1;
                while (start < end) {
                    int t = nums[start];
                    nums[start] = nums[end];
                    nums[end] = t;
                    start++;
                    end--;
                }
                start = i + 1;
                while (nums[start] <= nums[i]) { start++; }
                int t = nums[start];
                nums[start] = nums[i];
                nums[i] = t;
                tmp = -1;
                break;
            } else {
                tmp = nums[i];
            }
        }
        if (tmp == nums[0]) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                int t = nums[start];
                nums[start] = nums[end];
                nums[end] = t;
                start++;
                end--;
            }
        }
    }
};