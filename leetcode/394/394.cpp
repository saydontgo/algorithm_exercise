#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (const auto& c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                string tmp;
                auto cur_char = st.top();
                while (cur_char != '[') {
                    tmp += cur_char;
                    st.pop();
                    cur_char = st.top();
                }
                st.pop();
                reverse(tmp.begin(), tmp.end());
                int cnt = 1;
                int cishu = 0;
                cur_char = st.top();
                while(cur_char <= '9' && cur_char >= '0') {
                    cishu = (cur_char - '0') * cnt + cishu;
                    cnt *= 10;
                    st.pop();
                    if (st.empty()) { break; }
                    cur_char = st.top();
                }
                for (int i = 0; i < cishu; i++) {
                    for (const auto& tmp_c : tmp) {
                        st.push(tmp_c);
                    }
                }
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};