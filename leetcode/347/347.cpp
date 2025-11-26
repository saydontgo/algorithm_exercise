#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void heapify(vector<pair<int, int>>& topk, int k) {
    int index = 0;
    while (index < k) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int min = -1;
        if (left < k && right < k) {
            min = topk[left].second < topk[right].second ? left : right;
        } else if (left < k) {
            min = left;
        } else if (right < k) {
            min = right;
        }

        if (min == -1) break;

        if (topk[index].second > topk[min].second) {
            auto tmp = topk[min];
            topk[min] = topk[index];
            topk[index] = tmp;
        } else { break; }
        index = min;
    }
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<pair<int, int>> topk(k, {-1, -1e8});
    unordered_map<int, int> cnt;

    for (const auto& num : nums) {
        cnt.find(num) == cnt.end() ? cnt[num] = 1 : cnt[num]++;
    }

    for (const auto& ele : cnt) {
        if (ele.second > topk[0].second) {
            topk[0] = ele;
            heapify(topk, k);
        }
    }

    vector<int> res;

    for (const auto& ele : topk) {
        res.push_back(ele.first);
    }
    return res;
}
int main() {
    return 0;
}