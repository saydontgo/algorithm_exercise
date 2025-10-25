#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;

    int child_index = g.size() - 1;
    int cookie_index = s.size() - 1;

    while (child_index > -1 && cookie_index > -1) {
        if (s[cookie_index] >= g[child_index]) {
            --cookie_index;
            res++;
        }
            --child_index;
    }
    return res;
}

void test() {
    auto g = vector<int>({1,2});
    auto s = vector<int>({1,2,3});
    cout << findContentChildren(g, s) << endl;
}
int main() {
    test();
}