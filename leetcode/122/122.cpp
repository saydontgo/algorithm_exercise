#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    auto size = prices.size();

    if (size == 1) { return 0; }

    int in = 0;
    int out = 0;
    int res = 0;
    int flag = 0; // 0：买入状态， 1：卖出状态

    int prev = prices[0];
    for (const auto& price : prices) {
        if (flag == 0) {
            if (price > prev) {
                flag = 1;
                in = prev;
            }
        } else {
            if (price < prev) {
                flag = 0;
                res += prev - in;
            }
        }
        prev = price;
    }

    if (flag == 1 && prev > in) {
        res += prev - in;
    }
    return res;
}

void test() {
    auto prices = vector<int>({7,6,4,3,1});
    cout << maxProfit(prices) << endl;
}
int main() {
    test();
    return 0;
}