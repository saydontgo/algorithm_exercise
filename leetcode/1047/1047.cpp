#include <string>
#include <deque>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == st.back()) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        string res;
        for (const auto& c : st) {
            res += c;
        }
        return res;
    }
};