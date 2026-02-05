#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cishu;
        unordered_set<char> existed;
        for (auto& c : t) {
            if (cishu.find(c) != cishu.end()) {
                cishu[c]++;
            } else {
                existed.insert(c);
                cishu[c] = 1;
            }
        }
        int start = 0;
        int length = 1e5 + 10;
        string res = "";
        while (start < s.size() && cishu.find(s[start]) == cishu.end()) start++;
        int end = start;
        for (int i = start; i < s.size(); i++) {
            if (cishu.find(s[i]) == cishu.end()) {
                end++;
            } else {
                if (cishu[s[i]] <= 0) {
                    if (s[start] == s[i]) {
                        start++;
                        end++;
                        for (int j = start; j < end; j++) {
                            if (cishu.find(s[j]) != cishu.end()) {
                                if (cishu[s[j]] >= 0) {
                                    break;
                                } else {
                                    start++;
                                    cishu[s[j]]++;
                                    if (cishu[s[j]] > 0) {
                                        existed.insert(s[j]);
                                    }
                                }
                            } else {
                                start++;
                            }
                        }
                    } else {
                        cishu[s[i]]--;
                        end++;
                    }
                } else {
                    cishu[s[i]]--;
                    if (cishu[s[i]] == 0) {
                        existed.erase(s[i]);
                    }
                    end++;
                }
            }
            if (existed.size() == 0) {
                if (end - start < length)  {
                    res = s.substr(start, end - start);
                    length = end - start;
                }
            }
        }
        return res;
    }
};