#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int longestPalindrome(string s) {
    unordered_map<char, int> dict;

    int res = 0;

    for(const auto& c : s) {
        if (dict.find(c) != dict.end()) {
            dict[c]++;
        } else {
            dict[c] = 1;
        }
    }
    int flag = 0;
    for (const auto& kv : dict) {
        if (kv.second & 1) {
            res += kv.second - 1;
            flag = 1;
        } else {
            res += kv.second;
        }
    }

    if (flag == 1) {
        res++;
    }
    return res;
}

void test() {
    string s = "a";
    cout << longestPalindrome(s) << endl;
}
int main() {
    test();
    return 0;
}