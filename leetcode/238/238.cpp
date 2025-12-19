#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    auto size = nums.size();
    vector<int> res(size);
    res[0] = 1;
    for (int i = 1; i < size; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    auto tmp = nums[size - 1];
    for (int i = size - 2; i > -1; i--) {
        res[i] = res[i] * tmp;
        tmp *= nums[i];
    }
    return res;
}

int main() {
    return 0;
}