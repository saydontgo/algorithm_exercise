#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& tmp, int& target, int cur_val, int index, vector<int>& cishu, vector<int>& arr) {
    if (cur_val > target) { return; }
    if (cur_val == target) {
        // cout << "[ ";
        // for (const auto& ele: tmp) {
        //     cout << ele << " ";
        // }
        // cout << "]\n";
        res.push_back(tmp);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        for (int j = 1; j <= cishu[arr[i]]; j++) {
            tmp.push_back(arr[i]);
            // cout << "index: " << i << "推入 " << arr[i] << endl;
            dfs(res, tmp, target, cur_val + j * arr[i], i + 1, cishu, arr);
        }
        tmp.resize(tmp.size() - cishu[arr[i]]);
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    vector<int> cishu(55, 0);
    vector<int> arr;
    for (const auto& ele: candidates) {
        ++cishu[ele];
    }
    for (int i = 0; i < 55; i++) {
        if (cishu[i] != 0) arr.push_back(i);
    }
    // cout << "所有合法的数字：" << endl;
    // for (const auto& ele : arr) {
    //     cout << ele << " ";
    // }
    // cout << endl;
    dfs(res, tmp, target, 0, 0, cishu, arr);
    return res;
}

void test() {
    vector<int> candidates({10,1,2,7,6,1,5});
    int target = 8;
    auto res = combinationSum2(candidates, target);
    for (const auto& arr: res) {
        cout << "[ ";
        for (const auto& ele: arr) {
            cout << ele << " ";
        }
        cout << "]\n";
    }
}
int main() {
    test();
}