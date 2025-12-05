#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector<int>& res, vector<vector<int>>& map, int cur, int visited[], int& valid) {
    if (visited[cur] == 1) {
        valid = 0;
        return;
    }
    if (visited[cur] == 0) {
        visited[cur] = 1;
        for (int i = 0; i < map[cur].size(); i++) {
            dfs(res, map, i, visited, valid);
        }
        res.push_back(cur);
        
    }
    visited[cur] = 2;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> map(numCourses);
    vector<int> res;
    int visited[numCourses];
    memset(visited, 0, numCourses * sizeof(int));
    int valid = 1;
    for (int i = 0; i < prerequisites.size(); i++) {
        map[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < map.size(); i++) {
        dfs(res, map, i, visited, valid);
    }
    if (!valid) {
        return {};
    }
    vector<int> tmp_res;
    for (int i = res.size() - 1; i > -1; i--) {
        tmp_res.push_back(res[i]);
    }
    return tmp_res;
}
int main() {
    return 0;
}