#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>> &res, vector<int> &arr, vector<int> &tmp, int cur_num, int max_num, int index, int size) {
    if (cur_num == max_num) {
        res.push_back(tmp);
        return;
    }
    if (cur_num > max_num) { return; }
    for (int i = index; i < size; i++) {
        tmp.push_back(arr[i]);
        dfs(res, arr, tmp, cur_num + arr[i], max_num, i, size);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, candidates, tmp, 0, target, 0, candidates.size());
    return res;
}

void test() {
    auto candidates = vector<int>({2,3,5});
    auto res = combinationSum(candidates, 8);

    for (const auto &entry: res) {
        cout << "[ ";
        for (const auto &ele: entry) {
            cout << ele << " ";
        }
        cout << "]\n";
    }
}
int main() {
    test();
    return 0;
}