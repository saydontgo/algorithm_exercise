#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int change(int amount, vector<int>& coins) {
    // 题目有点sb了，说是32位整数可以表示，实际上有两个题目的答案为0，但是却会overflow（不优化为一维数组的话），需要unsigned long long才行😅
    unsigned long long dp[coins.size()][amount + 1];
    memset(dp, 0, coins.size() * (amount + 1) * 8);
    dp[0][0] = 1;
    for (int i = 1; i <= amount; i++) {
        if (i % coins[0] == 0) { dp[0][i] = 1; }
        else { dp[0][i] = 0; }
    }
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            for (int z = 0; z * coins[i] <= j; z++) {
                dp[i][j] += dp[i - 1][j - z * coins[i]];
            }
        }
    }
    return dp[coins.size() - 1][amount];
}

void test() {
    auto res = vector<int>({2});
    cout << change(3, res) << endl;
}
int main() {
    test();
    return 0;
}