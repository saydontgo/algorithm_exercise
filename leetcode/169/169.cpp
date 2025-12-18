#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int majorityElement(vector<int>& nums) {
    int cand = nums[0];
    int cnt = 0;

    for (const auto& ele : nums) {
        if (ele == cand) {
            cnt++;
        } else {
            if (cnt == 0) {
                cand = ele;
                cnt = 1;
            } else {
                cnt--;
            }
        }
    }
    return cand;
}
int main() {
    return 0;
}