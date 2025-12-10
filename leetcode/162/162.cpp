#include <iostream>
#include <vector>
using namespace std;

int BinnarySearch(vector<int>& nums, int left, int right) {
    if (left == right) { return left; }
    auto mid = left + (right - left) / 2 + 1;
    int res = -1;
    if (nums[mid] < nums[mid - 1]) {
        res = BinnarySearch(nums, left, mid - 1);
    } else {
        res = BinnarySearch(nums, mid, right);
    }
    return res;
}

int findPeakElement(vector<int>& nums) {
    return BinnarySearch(nums, 0, nums.size() - 1);
}
int main() {
    return 0;
}