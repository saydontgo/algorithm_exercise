#include <iostream>
#include <vector>

using namespace std;
int singleNumber(vector<int>& nums) {
  int res = 0;
  for (const auto& num : nums) {
    res ^= num;
  }
  return res;
}
int main() {
  return 0;
}