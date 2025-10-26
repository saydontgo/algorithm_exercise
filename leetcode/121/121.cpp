#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    auto max_profit = 0;
    int min_price = 1e9;

    for (const auto& price : prices) {
        max_profit = max(price - min_price, max_profit);
        min_price = min(min_price, price);
    }

    return max_profit;
}

void test() {
    auto prices = vector<int>({5,6,1,3});
    cout << maxProfit(prices) << endl;
}
int main() {
    test();
    return 0;
}