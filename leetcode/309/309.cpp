#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto size = prices.size();

        int dp[5000][2];

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < size; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            if (i - 2 >= 0) {
                dp[i][1] = max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
            } else {
                dp[i][1] = max(-prices[0], -prices[1]);
            }
        }
        return dp[size - 1][0];
    }
};