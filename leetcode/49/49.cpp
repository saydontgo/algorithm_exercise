#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> existed;

        for (int i = 0; i < strs.size(); i++) {
            string tmp(26, '0');
            for (const auto& c : strs[i]) {
                tmp[c - 'a']++;
            }
            if (existed.find(tmp) != existed.end()) {
                res[existed[tmp]].push_back(strs[i]);
            } else {
                existed[tmp] = res.size();
                vector<string> t(1, strs[i]);
                res.push_back(t);
            }
        }
        return res;
    }
};