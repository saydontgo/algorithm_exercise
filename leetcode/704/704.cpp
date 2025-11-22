#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int middle = (left + right) / 2;
        if (nums[middle] >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    if (nums[left] != target) { return -1; }
    return left;
}
int main() {
    return 0;
}