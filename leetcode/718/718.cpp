#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            dp[i][0] = nums1[i] == nums2[0];
            if (dp[i][0] > res) { res = dp[i][0]; }
        }
        for (int i = 0; i < nums2.size(); i++) {
            dp[0][i] = nums1[0] == nums2[i];
            if (dp[0][i] > res) { res = dp[0][i]; }
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > res) { res = dp[i][j]; }
                }
            }
        }
        return res;
    }
};