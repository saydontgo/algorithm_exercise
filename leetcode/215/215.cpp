#include <iostream>
#include <vector>
using namespace std;
// 桶排
int findKthLargest(vector<int>& nums, int k) {
    int flag[int(2 * 1e4) + 10] = {0};
    int max = -1e5;
    int min = 1e5;
    for (const auto& ele : nums) {
        flag[ele + int(1e4)]++;
        max = ele > max ? ele : max;
        min = ele < min ? ele : min;
    }
    for (int i = max; i >= min; i--) {
        if (k - flag[i + int(1e4)] <= 0) return i;
        k -= flag[i + int(1e4)];
    }
    return -1e4;
}
int main() {
    return 0;
}