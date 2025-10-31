#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, int>& arr, vector<int>& enums, int index, vector<int>& tmp, vector<vector<int>>& res) {
    for (int i = index; i < enums.size(); i++) {
        auto num = enums[i];
        auto cishu = arr[num];
        for (int j = 1; j <= cishu; j++) {
            for (int z = 1; z <= j; z++) {
                tmp.push_back(num);
            }
            res.push_back(tmp);
            dfs(arr, enums, i + 1, tmp, res);
            for (int z = 1; z <= j; z++) {
                tmp.pop_back();
            }
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    unordered_map<int, int> arr;
    int flag[40];
    memset(flag, 0, 40 * 4);
    for (const auto& num : nums) {
        auto it = arr.find(num );
        if (it == arr.end()) {
            flag[num + 10] = 1;
            arr.insert({num, 0});
        }
        ++arr[num];
    }
    vector<int> enums;

    for (int i = 0; i < 40; i++) {
        if (flag[i]) { enums.push_back(i - 10); }
    }

    vector<vector<int>> res;
    vector<int> tmp;
    res.push_back(tmp);
    dfs(arr, enums, 0, tmp, res);
    return res;
}

void test() {
    auto nums = vector<int>({0});
    auto res = subsetsWithDup(nums);
    for (const auto& arr : res) {
        cout << "[ ";
        for (const auto& ele : arr) {
            cout << ele << " ";
        }
        cout << "]\n";
    }
}
int main() {
    test();
    return 0;
}