#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> m;
        vector<double> res;
        for (int i = 0; i < values.size(); i++) {
            if(m.find(equations[i][0]) == m.end()) {
                m.insert({equations[i][0], vector<pair<string, double>>(1, {equations[i][1], values[i]})});
            } else {
                m[equations[i][0]].push_back({equations[i][1], values[i]});
            }
            if(m.find(equations[i][1]) == m.end()) {
                m.insert({equations[i][1], vector<pair<string, double>>(1, {equations[i][0], 1 / values[i]})});
            } else {
                m[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            }
        }
        for (const auto& quary : queries) {
            if (m.find(quary[0]) == m.end() || m.find(quary[1]) == m.end()) {
                res.push_back(-1.0);
            } else {
                queue<pair<string, double>> vars;
                auto match = quary[1];
                vars.push({quary[0], 1});
                bool flag = 0;
                unordered_set<string> visited;
                while (!vars.empty()) {
                    auto cur_var = vars.front();
                    vars.pop();
                    auto next = m[cur_var.first];
                    for (const auto& val : next) {
                        if (val.first == match) {
                            res.push_back(cur_var.second * val.second);
                            flag = 1;
                            break;
                        }
                        if (visited.count(val.first) == 0) {
                            vars.push({val.first, cur_var.second * val.second});
                            visited.insert(val.first);
                        }
                    }
                    if (flag) { break;}
                }
                if (!flag) {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};