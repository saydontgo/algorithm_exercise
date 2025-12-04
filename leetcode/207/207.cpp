#include <cstring>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

// dfs 实现拓扑排序
bool dfs(vector<vector<int>>& map, int visited[], int start) {
    visited[start] = 1;
    for (const auto& next : map[start]) {
        if (visited[next] == 1) {
            return false;
        } else if (visited[next] == 0) {
            auto success = dfs(map, visited, next);
            if (!success) {
                return false;
            }
        }
    }
    visited[start] = 2;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int visited[2010] = {0};
    vector<vector<int>> map(numCourses);

    for (const auto& pair : prerequisites) {
        map[pair[1]].push_back(pair[0]);
    }
    
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            auto success = dfs(map, visited, i);           
            if (!success) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    return 0;
}