#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int longestPalindromeSubseq(string s) {
    auto size = s.size();

    int dp[size + 1][size + 1];
    memset(dp, 0, (size + 1) * (size + 1) * 4);
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    for (int interval = 1; interval < size; interval++) {
        for (int j = 0; j + interval < size; j++) {
            if (interval == 1) {
                if (s[j] == s[j + interval]) { dp[j][j + interval] = 2; }
                else { dp[j][j + interval] = 1; }
            } else {
                if (s[j] == s[j + interval]) { dp[j][j + interval] = dp[j + 1][j + interval - 1] + 2; }
                else { dp[j][j + interval] = max(dp[j + 1][j + interval], dp[j][j + interval - 1]); }
            }
        }
    }

    // for (int i = 0; i < size; i++) {
    //     for (int j = i; j < size; j++) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return dp[0][size - 1];
}

void test() {
    cout << longestPalindromeSubseq("cbbd") << endl;
}
int main() {
    test();
    return 0;
}