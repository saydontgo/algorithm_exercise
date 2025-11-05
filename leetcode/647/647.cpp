#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int countSubstrings(string s) {
    auto size = s.size();
    int dp[size + 1][size + 1];
    memset(dp, 0, (size + 1) * (size + 1) * 4);
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j + i < size; j++) {
            if (i > 1) {
                if (dp[j + 1][j + i - 1] && s[j + i] == s[j]) { dp[j][j + i] = 1; }
            } else {
                if (s[j + i] == s[j]) { dp[j][j + i] = 1; }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            // cout << dp[i][j] << " ";
            if (dp[i][j]) { res++; }
        }
        // cout << endl;
    }
    return res;
}


void test() {
    cout << countSubstrings("aaa") << endl;
}
int main() {
    test();
    return 0;
}