#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

// 使用dfs实现拓扑排序
// void dfs(vector<int>& res, vector<vector<int>>& map, int cur, int visited[], int& valid) {
//     if (visited[cur] == 1) {
//         valid = 0;
//         return;
//     }
//     if (visited[cur] == 0) {
//         visited[cur] = 1;
//         for (int i = 0; i < map[cur].size(); i++) {
//             dfs(res, map, i, visited, valid);
//         }
//         res.push_back(cur);
//     }
//     visited[cur] = 2;
// }

// vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//     vector<vector<int>> map(numCourses);
//     vector<int> res;
//     int visited[numCourses];
//     memset(visited, 0, numCourses * sizeof(int));
//     int valid = 1;
//     for (int i = 0; i < prerequisites.size(); i++) {
//         map[prerequisites[i][1]].push_back(prerequisites[i][0]);
//     }
//     for (int i = 0; i < map.size(); i++) {
//         dfs(res, map, i, visited, valid);
//     }
//     if (!valid) {
//         return {};
//     }
//     vector<int> tmp_res;
//     for (int i = res.size() - 1; i > -1; i--) {
//         tmp_res.push_back(res[i]);
//     }
//     return tmp_res;
// }


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> out(numCourses);
    vector<set<int>> in(numCourses);
    vector<int> res;
    int visited[numCourses];
    memset(visited, 0, numCourses * sizeof(int));
    int valid = 1;
    for (int i = 0; i < prerequisites.size(); i++) {
        out[prerequisites[i][1]].push_back(prerequisites[i][0]);
        in[prerequisites[i][0]].insert(prerequisites[i][1]);
    }
    queue<int> q;
    for (int i = 0; i < in.size(); i++) {
        if (in[i].empty()) {
            q.push(i);
            res.push_back(i);
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (const auto& child : out[cur]) {
            in[child].erase(cur);
            if (in[child].empty()) {
                q.push(child);
                res.push_back(child);
            }
        }
    }
    if (res.size() == numCourses) { return res; }
    return {};
}
int main() {
    return 0;
}