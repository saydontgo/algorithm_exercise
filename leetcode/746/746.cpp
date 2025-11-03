#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int p[1010];
    p[0] = 0, p[1] = 0;

    int index = 2;
    while(index <= cost.size()) {
        p[index] = min(cost[index - 1] + p[index - 1], cost[index - 2] + p[index - 2]);
        index++;
    }
    return p[cost.size()];
}

int main() {
    return 0;
}