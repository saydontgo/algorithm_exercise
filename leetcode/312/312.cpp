#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        int dp[310][310];

        for (int i = 1; i < nums.size() - 1; i++) {
            dp[i][i] = nums[i] * nums[i - 1] * nums[i + 1];
        }

        dp[0][0] = nums[0];
        if (size > 1) { dp[0][0] *= nums[1]; }
        dp[size - 1][size - 1] = nums[size - 1];
        if (size > 1) { dp[size - 1][size - 1] *= nums[size - 2]; }
        
        for (int interval = 1; interval < size; interval++) {
            for (int i = 0; i + interval < size; i++) {
                auto ahead = 1;
                auto last = 1;
                if (i != 0) {
                    ahead = nums[i - 1];
                }
                if (i + interval + 1 < size) {
                    last = nums[i + interval + 1];
                }
                dp[i][i + interval] = ahead * nums[i] * last + dp[i + 1][i + interval];
                for (int k = i + 1; k < i + interval; k++) {
                    dp[i][i + interval] = max(dp[i][i + interval], ahead * nums[k] * last + dp[i][k - 1] + dp[k + 1][i + interval]);
                }
                dp[i][i + interval] = max(dp[i][i + interval], ahead * nums[i + interval] * last + dp[i][i + interval - 1]);
            }
        }
        return dp[0][size - 1];
    }
};