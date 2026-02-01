#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int arr[2 * (int(1e4) + 10)];

        memset(arr, 0, 2 * 4 * (int(1e4) + 10));

        for (const auto& interval : intervals) {
            arr[interval[0] * 2]++;
            arr[interval[1] * 2 + 1]--;
        }
        vector<vector<int>> res;
        vector<int> tmp;
        if (arr[0] > 0) { tmp.push_back(0); }
        for (int i = 1; i <= 2 * (int(1e4) + 1); i++) {
            arr[i] = arr[i - 1] + arr[i];
            if (arr[i - 1] == 0 && arr[i] >= 1) {
                tmp.push_back(i / 2);
            }
            if (arr[i - 1] >= 1 && arr[i] == 0) {
                tmp.push_back((i - 1) / 2);
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};