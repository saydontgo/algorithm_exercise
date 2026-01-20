#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
unordered_map<char, string> mm;
    void dfs(int index, string& digits, vector<string>& res, string& tmp) {
        if (index == digits.size()) {
            res.push_back(tmp);
            return;
        }
        for (const auto& c : mm[digits[index]]) {
            tmp += c;
            dfs(index + 1, digits, res, tmp);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        mm.insert({'2', "abc"});
        mm.insert({'3', "def"});
        mm.insert({'4', "ghi"});
        mm.insert({'5', "jkl"});
        mm.insert({'6', "mno"});
        mm.insert({'7', "pqrs"});
        mm.insert({'8', "tuv"});
        mm.insert({'9', "wxyz"});

        vector<string> res;
        string tmp;
        dfs(0, digits, res, tmp);
        return res;
    }
};