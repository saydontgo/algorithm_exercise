#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) { return a[0] < b[0]; }
    return a[1] > b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size());
        for (const auto& person : people) {
            int index = 0;
            int cursor = 0;
            while (index < person[1]) {
                if (res[cursor].empty()) {
                    index++;
                }
                cursor++;
            }
            while(!res[cursor].empty()) {
                cursor++;
            }
            res[cursor] = person;
        }
        return res;
    }
};