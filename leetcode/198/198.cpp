#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    auto size = nums.size();
    int dp[nums.size()];
    dp[0] = nums[0];

    if (size >= 2) {
        dp[1] = nums[1];
    }

    if (size >= 3) {
        dp[2] = nums[2] + dp[0];
    }

    for (int i = 3; i < size; i++) {
        dp[i] = max(dp[i - 3] + nums[i], dp[i - 2] + nums[i]);
    }

    int res = 0;
    for (int i = size - 1; i > -1 && i >= int(size) - 2; i--) {
        res = max(res, dp[i]);
    }
    return res;
}


int main() {
    return 0;
}