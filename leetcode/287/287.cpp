#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                int tmp = 0;
                while (slow != tmp) {
                    slow = nums[slow];
                    tmp = nums[tmp];
                }
                return slow;
            }
        }
    }
};