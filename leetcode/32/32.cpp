#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int tmp = s.size();
        if (tmp == 0) { return 0; }
        int dp[tmp];
        int max_len = 0;
        memset(dp, 0, sizeof(int) * s.size());
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 > -1) { dp[i] += dp[i - 2]; }
                } else {
                    if (i - 1 - dp[i - 1] > -1 && s[i - 1 - dp[i - 1]] == '(') {
                        dp[i] = 2 + dp[i - 1];
                        if (i - 1 - dp[i - 1] - 1 > -1) {
                            dp[i] += dp[i - 1 - dp[i - 1] - 1];
                        }
                    }
                }
            }
            if (dp[i] > max_len) { max_len = dp[i]; }
        }
        return max_len;
    }
};