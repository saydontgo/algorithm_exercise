#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

// 因为负数还要维护一个最小连续乘积子数组，逆天了😅
int maxProduct(vector<int>& nums) {
  auto size = nums.size();

  int dp[size];
  int dp_min[size];

  dp[0] = nums[0];
  dp_min[0] = nums[0];

  for (int i = 1; i < size; i++) {
    dp[i] = nums[i];
    dp_min[i] = nums[i];
    dp[i] = max(dp[i], nums[i] * dp[i - 1]);
    dp[i] = max(dp[i], nums[i] * dp_min[i - 1]);

    dp_min[i] = min(dp_min[i], nums[i] * dp[i - 1]);
    dp_min[i] = min(dp_min[i], nums[i] * dp_min[i - 1]);
  }

  int maxx = INT32_MIN;
  for (const auto &ele : dp) {
    if (ele > maxx) {
      maxx = ele;
    }
  }
  return maxx;
}
int main() {
  return 0;
}