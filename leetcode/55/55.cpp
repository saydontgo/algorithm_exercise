#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

bool canJump(vector<int>& nums) {
    // 用广搜做的，有更优的利用贪心的解法（遍历数组，维护最远能到达的位置即可）
    int flag[int(1e4) + 10];
    memset(flag, 0, (int(1e4) + 10) * 4);
    deque<int> reach_point;
    int target = nums.size() - 1;
    if (target == 0) { return true; }
    int cur_index = 0;
    reach_point.push_back(cur_index);
    while(!reach_point.empty()) {
        cur_index = reach_point.front();
        reach_point.pop_front();
        if (flag[cur_index]) { continue; }
        flag[cur_index] = 1;
        for (int i = 1; i <= nums[cur_index]; i++) {
            reach_point.push_back(cur_index + i);
            if (cur_index + i == target) { return true; }
        }
    }
    return false;
}

void test() {
    auto nums = vector<int>({3,2,1,0,4});
    cout << canJump(nums) << endl;
}
int main() {
    test();
    return 0;
}