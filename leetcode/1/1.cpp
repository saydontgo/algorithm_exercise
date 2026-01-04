#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& numss, int target) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < numss.size(); i++) {
            nums.push_back({numss[i], i});
        }
        sort(nums.begin(), nums.end(), cmp);

        int first = 0;
        int last = nums.size() - 1;
        vector<int> res({first, last});
        while (first < last) {
            int tmp = nums[first].first + nums[last].first;
            if (tmp > target) {
                last--;
                while (first < last && nums[last].first == nums[last + 1].first) { last--; }
            } else if (tmp < target) {
                first++;
                while (first < last && nums[first].first == nums[first - 1].first) { first++; }
            } else {
                res[0] = nums[first].second;
                res[1] = nums[last].second;
                break;
            }
        }
        return res;
    }
};