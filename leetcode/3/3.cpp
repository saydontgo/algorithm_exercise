#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) { return 0; }
        queue<char> windows;
        unordered_set<char> existed;
        int max_s = 1;
        windows.push(s[0]);
        existed.insert(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (existed.count(s[i])) {
                if (windows.size() > max_s) {
                    max_s = windows.size();
                }
                while (!windows.empty()) {
                    auto tmp = windows.front();
                    windows.pop();
                    existed.erase(tmp);
                    if (tmp == s[i]) {
                        break;
                    }
                }
            }
            windows.push(s[i]);
            existed.insert(s[i]);
    }
        if (windows.size() > max_s) {
            max_s = windows.size();
        }
        return max_s;
    }
};