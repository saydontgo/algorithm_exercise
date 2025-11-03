#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (const auto& num : nums) {
        sum += num;
    }
    if (sum & 1) { return false; }
    sum /= 2;
    int dp[nums.size()][sum + 5];
    memset(dp, 0, nums.size() * (sum + 5) * 4);

    if (nums[0] <= sum) { dp[0][nums[0]] = true; }
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            if (dp[i - 1][j]) { dp[i][j] = true; }
            else {
                if (j > nums[i] && dp[i - 1][j - nums[i]]) { dp[i][j] = true; }
                else { dp[i][j] = false; }
            }
        }
    }
    return dp[nums.size() - 1][sum];
}

void test() {
    auto nums = vector<int>({1,2,3,5});
    cout << canPartition(nums) << endl;
}
int main() {
    test();
    return 0;
}