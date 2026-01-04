#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int first = i + 1;
            int last = nums.size() - 1;
            while (first < last) {
                int tmp = nums[i] + nums[first] + nums[last];
                if (tmp > 0) {
                    last--;
                    while(last > first && nums[last] == nums[last + 1]) { last--; }
                } else if (tmp < 0) {
                    first++;
                    while (first < last && nums[first] == nums[first - 1]) { first++; }
                } else {
                    vector<int> one_res({nums[i], nums[first], nums[last]});
                    res.push_back(one_res);
                    first++;
                    while (first < last && nums[first] == nums[first - 1]) { first++; }
                }
            }
        }
        return res;
    }
};