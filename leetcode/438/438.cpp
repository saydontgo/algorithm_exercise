#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int alph_cnt[26] = {0};
        int exist[26] = {0};
        for (const auto& c : p) {
            alph_cnt[c - 'a']++;
            exist[c - 'a'] = 1;
        }
        // 初始化
        int s_size = s.size();
        int p_size = p.size();
        if (s_size < p_size) { return res; }
        for (int i = 0; i < p_size; i++) {
            if (exist[s[i] - 'a']) {
                alph_cnt[s[i] - 'a']--;
            }
        }
        for (int i = p_size; i < s_size; i++) {
            int flag = 0;
            for (const auto& cnt : alph_cnt) {
                if (cnt != 0) { flag = 1; break; }
            }

            if (!flag) { res.push_back(i - p_size); }
            if (exist[s[i - p_size] - 'a']) {
                alph_cnt[s[i - p_size] - 'a']++;
            }
            if (exist[s[i] - 'a']) {
                alph_cnt[s[i] - 'a']--;
            }
        }
        int flag = 0;
        for (const auto& cnt : alph_cnt) {
            if (cnt != 0) { flag = 1; break; }
        }

        if (!flag) { res.push_back(s_size - p_size); }
        return res;
    }
};