#include <iostream>

using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int distance = 0;
        while (res != 0) {
            if (res & 1) { distance++; }
            res >>= 1;
        }
        return distance;
    }
};
int main() {
  return 0;
}