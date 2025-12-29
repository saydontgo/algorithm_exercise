#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(1, 0);
        int max_power = 1;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                max_power = i;
            }
            res.push_back(res[i - max_power] + 1);
        }
        return res;
    }
};