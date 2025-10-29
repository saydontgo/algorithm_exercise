#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

int jump(vector<int>& nums) {
    auto target = nums.size() - 1;
    int flag[int(1e4) + 10];
    memset(flag, 0, (int(1e4) + 10) * 4);
    deque<pair<int, int>> reach_point;
    reach_point.push_back({0, 0});

    while(!reach_point.empty()) {
        auto pair = reach_point.front();
        reach_point.pop_front();
        auto index = pair.first;
        auto step = pair.second;
        if (index == target) {
            return step;
        }
        if (flag[index]) { continue; }
        flag[index] = 1;
        for (int i = 1;i <= nums[index]; i++) {
            reach_point.push_back({index + i, step + 1});
        }
    }
    return -1;
}

void test() {
    auto nums = vector<int>({2,3,0,1,4});
    cout << jump(nums) << endl;
}
int main() {
    test();
    return 0;
}