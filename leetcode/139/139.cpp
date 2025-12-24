#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <unordered_set>
using namespace std;


// 暴力的写法，会超时
// void dfs(string& s, set<string>& wordDict, int cursor, bool &res) {
//   if (cursor == s.size() || res) {
//     res = true;
//     return;
//   }
//   if (cursor > s.size()) {
//     return;
//   }

//   string tmp;
//   int flag = 0;
//   vector<int> floor;
//   for (int i = cursor; i < s.size() && !flag; i++) {
//     tmp += s[i];
//     if (wordDict.find(tmp) != wordDict.end()) {
//       for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
//         if (s.substr(cursor).compare(0, it->size(), *it) == 0) {
//           floor.push_back(it->size());
//         }
//       }
//       flag = 1;
//     }
//   }
//   for (int i = 0; i < floor.size(); i++) {
//     dfs(s, wordDict, cursor + floor[i], res);
//   }
// }

// bool wordBreak(string s, vector<string>& wordDict) {
//   auto res = false;
//   set<string> words;
//   for (const auto &str : wordDict) {
//     words.insert(str);
//   }
//   dfs(s, words, 0, res);
//   return res;
// }

// dp 写法，没想到这样也行
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> words;
  for (const auto &str : wordDict) {
    words.insert(str);
  }

  int dp[s.size()];

  memset(dp, 0, sizeof(int) * s.size());
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] && words.find(s.substr(j + 1, i - j)) != words.end()) {
        dp[i] = 1;
        break;
      }
    }
    if (words.find(s.substr(0, i + 1)) != words.end()) { dp[i] = 1; }
  }
  return dp[s.size() - 1];
}

int main() {
  return 0;
}