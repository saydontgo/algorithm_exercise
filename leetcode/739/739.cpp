#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    stack<pair<int, int>> tmp;
    for (int i = 0; i < temperatures.size(); i++) {
        if (!tmp.empty() && temperatures[i] > tmp.top().first) {
            while (!tmp.empty() && temperatures[i] > tmp.top().first) {
                res[tmp.top().second] = i - tmp.top().second;
                tmp.pop();
            }
        }
        tmp.push({temperatures[i], i});
    }
    while (!tmp.empty()) {
        res[tmp.top().second] = 0;
        tmp.pop();
    }
    return res;
}

int main() {
    return 0;
}