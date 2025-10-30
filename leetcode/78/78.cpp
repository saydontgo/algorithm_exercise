#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& arr, int index, vector<int>& tmp, vector<vector<int>>& res) {
    for (int i = index; i < arr.size(); i++) {
        tmp.push_back(arr[i]);
        res.push_back(tmp);
        dfs(arr, i + 1, tmp, res);
        tmp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    int index = 0;
    vector<int> tmp;
    vector<vector<int>> res;
    res.push_back(tmp);
    dfs(nums, index, tmp, res);
    return res;
}

void test() {
    vector<int> nums({0});
    auto res = subsets(nums);

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