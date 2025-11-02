#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <memory>
using namespace std;

vector<string> Tovector(deque<pair<int, int>> tmp, int n) {
    vector<string> res;
    for (int i = 0; i < n; i++) {
        string stmp = "";   
        auto pos = tmp.front().second;
        for (int j = 1; j <= n; j++) {
            if (j != pos) { stmp += '.'; }
            else { stmp += 'Q'; }
        }
        tmp.pop_front();
        res.push_back(stmp);
    }
    return res;
}

void insert(int flag[10][10], int ii, int jj, int n) {
    for (int i = 1; i <= n; i++) {
        if (i != ii) { flag[i][jj]++; }
    }
    for (int j = 1; j <= n; j++) {
        if (j != jj) { flag[ii][j]++; }
    }
    auto start = ii > jj ? jj : ii;
    auto start_i = ii - start + 1;
    auto start_j = jj - start + 1;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]++; }
        start_i++;
        start_j++;
    }
    start_i = ii;
    start_j = jj;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]++; }
        start_i--;
        start_j++;
    }
    start_i = ii;
    start_j = jj;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]++; }
        start_i++;
        start_j--;
    }
    flag[ii][jj]++;
}

void erase(int flag[10][10], int ii, int jj, int n) {
    for (int i = 1; i <= n; i++) {
        if (i != ii) { flag[i][jj]--; }
    }
    for (int j = 1; j <= n; j++) {
        if (j != jj) { flag[ii][j]--; }
    }
    auto start = ii > jj ? jj : ii;
    auto start_i = ii - start + 1;
    auto start_j = jj - start + 1;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]--; }
        start_i++;
        start_j++;
    }
    start_i = ii;
    start_j = jj;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]--; }
        start_i--;
        start_j++;
    }
    start_i = ii;
    start_j = jj;
    while (start_i <= n && start_i > 0 && start_j <= n && start_j > 0) {
        if (start_i != ii) { flag[start_i][start_j]--; }
        start_i++;
        start_j--;
    }
    flag[ii][jj]--;
}
void dfs(int flag[10][10], vector<vector<string>>& res, deque<pair<int, int>>& tmp, int ii, int jj, int index, int n) {
    if (index == n) {
        res.push_back(Tovector(tmp, n));
        return;
    }

    for (int i = ii; i <= n; i++) {
        int j = 1;
        if (i == ii) { j = jj; }
        for (; j <= n; j++) {
            if (flag[i][j] == 0) {
                tmp.push_back({i, j});
                insert(flag, i, j, n);
                dfs(flag, res, tmp, i, j, index + 1, n);
                erase(flag, i, j, n);
                tmp.pop_back();
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    int flag[10][10];
    vector<vector<string>> res;
    deque<pair<int, int>> tmp;
    memset(flag, 0, 10 * 10 * 4);
    dfs(flag, res, tmp, 1, 1, 0, n);
    return res;
}


void test() {
    auto res = solveNQueens(4);
    for (const auto& arr : res) {
        cout << "[ ";
        for (const auto& ele : arr) {
            cout << ele << ", ";
        }
        cout << "]\n";
    }

    // int flag[10][10];
    // memset(flag, 0, 10 * 10 * 4);

    // insert(flag, 3, 3, 4);
    // for (int i = 1; i <= 4; i++) {
    //     for (int j = 1; j <= 4; j++) {
    //         cout << flag[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
int main() {
    test();
    return 0;
}