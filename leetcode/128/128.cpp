#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uni_nums;

        for (const auto& num : nums) {
            uni_nums.insert(num);
        }

        int max_l = 0;
        int tmp = 0;
        for (auto it = uni_nums.begin(); it != uni_nums.end(); it++) {
            if (uni_nums.find(*it - 1) == uni_nums.end()) {
                // 找到一个最小值
                int start = *it;
                tmp = 1;
                while (uni_nums.find(start + 1) != uni_nums.end()) {
                    tmp++;
                    start++;
                }
                if (tmp > max_l) { max_l = tmp; }
            }
        }
        return max_l;
    }
};