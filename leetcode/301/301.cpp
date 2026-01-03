#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValid(const string& str) {
        int left = 0;
        for (const auto& c : str) {
            if (c == '(') {
                left++;
            } else if (c== ')') {
                if (left == 0) { return false; }
                left--;
            }
        }
        return !left;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> cur;
        cur.insert(s);

        while (1) {
            for (const auto& str : cur) {
                if (isValid(str)) {
                    res.push_back(str);
                }
            }
            if (!res.empty()) {
                return res;
            }
            unordered_set<string> next;
            for (const auto& str : cur) {
                for (int i = 0; i < str.size(); i++) {
                    if (i > 0 && str[i] == str[i - 1]) {
                        continue;
                    }
                    if (str[i] == '(' || str[i] == ')') {
                        auto tmp = str;
                        next.insert(tmp.erase(i, 1));
                    }
                }
            }
            cur = next;
        }
    }
};