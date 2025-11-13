#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string longestPalindrome(string s) {
    auto size = s.size();
    int dp[size][size];
    memset(dp, 0, size * size * 4);
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    for (int interval = 1; interval < size; interval++) {
        for (int i = 0; i + interval < size; i++) {
            if (interval == 1) {
                if (s[i] == s[i + interval]) { dp[i][i + interval] = 1; }
                else { dp[i][i + interval] = 0; }
            } else {
                if (s[i] == s[i + interval] && dp[i + 1][i + interval - 1]) {
                    dp[i][i + interval] = 1;
                }
            }
        }
    }

    for (int interval = size - 1; interval >= 0; interval--) {
        for (int i = 0; i + interval < size; i++) {
            if(dp[i][i + interval]) {
                return s.substr(i, interval + 1);
            }
        }
    }
    return "";
}


int main() {
    return 0;
}