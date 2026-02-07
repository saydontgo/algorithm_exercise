#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int sum = 0;

        unordered_map<int, int> m;

        m.insert({0, 1});

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (m.find(sum - k) != m.end()) {
                res += m[sum - k];
            }
            if (m.find(sum) != m.end()) {
                m[sum]++;
            } else {
                m[sum] = 1;
            }
        }
        return res;
    }
};