#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int index = 0;
    int digit = nums[0];
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (digit == nums[i]) {
            cnt++;
            if (cnt > 2) { continue; }
        } else {
            cnt = 1;
            digit = nums[i];
        }
        nums[index++] = nums[i];
    }
    return index;
}
int main() {
    vector<int>a;
    return 0;
}