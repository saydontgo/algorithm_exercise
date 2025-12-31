#include <vector>
using namespace std;

class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) { return vector<int>(2, -1); }

        int left = 0;
        int right = nums.size() - 1;
        int start = -1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                start = mid;
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (start == -1) { return vector<int>(2, -1); }
        return vector<int>({start, last});
    }
};