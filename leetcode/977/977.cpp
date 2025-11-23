#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res;
    int index = 0;
    for (const auto& num : nums) {
        if (num >= 0) {
            break;
        }
        index++;
    }
    int minus = index - 1;
    for (int i = 0; i < nums.size(); i++) {
        if (minus < 0) {
            res.push_back(nums[index] * nums[index]);
            index++;
        } else if (index >= nums.size()) {
            res.push_back(nums[minus] * nums[minus]);
            minus--;
        } else if (abs(nums[minus]) < nums[index]) {
            res.push_back(nums[minus] * nums[minus]);
            minus--;
        } else {
            res.push_back(nums[index] * nums[index]);
            index++;
        }
    }
    return res;
}

int main() {
    return 0;
}