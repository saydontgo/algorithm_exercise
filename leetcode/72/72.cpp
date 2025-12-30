#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) { return word2.size(); }
        if (word2.empty()) { return word1.size(); }

        int dp[510][510] = {0};
        int flag = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word2[0] == word1[i]) {
                flag = 1;
            }
            if (flag) {
                dp[i][0] = i;
            } else {
                dp[i][0] = i + 1;
            }
        }
        flag = 0;
        for (int i = 0; i < word2.size(); i++) {
            if (word1[0] == word2[i]) {
                flag = 1;
            }
            if (flag) {
                dp[0][i] = i;
            } else {
                dp[0][i] = i + 1;
            }
        }
        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = min (dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min (dp[i - 1][j - 1], dp[i][j]);
                } else {
                    dp[i][j] = min (dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min (dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        return dp[word1.size() - 1][word2.size() - 1];
    }
};