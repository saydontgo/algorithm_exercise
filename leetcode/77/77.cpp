#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &tmp, int cur_gen, int max_gen, int max_index, int index) {
    if (cur_gen == max_gen) {
        res.push_back(tmp);
        return;
    }

    for (int i = index + 1; i <= max_index;i++) {
        tmp.push_back(i);
        dfs(res, tmp, cur_gen + 1, max_gen, max_index, i);
        tmp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, tmp, 0, k, n, 0);
    return res;
}

void test() {
    auto t1 = combine(1, 1);

    for (const auto &entry:t1) {
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