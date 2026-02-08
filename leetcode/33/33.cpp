#include <vector>
using namespace std;
class Solution {
public:
    int findk(vector<int>& nums, int start, int end) {
        if (start >= end) { return start; }
        int mid = start + ((end - start) >> 1);
        int res;
        if (nums[mid] > nums[end]) {
            res = findk(nums, mid + 1, end);
        } else {
            res = findk(nums, start, mid);
        }
        return res;
    }

    int findtarget(vector<int>& nums, int start, int end, int target) {
        if (start > end) { return -1; }
        int mid = start + ((end - start) >> 1);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return findtarget(nums, mid + 1, end, target);
        } else {
            return findtarget(nums, start, mid - 1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = findk(nums, 0, n - 1);
        int start = 0, end = n - 1;
        if (k != 0)
        if (target >= nums[0]) {
            end = k - 1;
        } else {
            start = k;
        }
        return findtarget(nums, start, end, target);
    }
};