#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void heapify(deque<pair<int, int>>& heap) {
    int index = 0;
    auto size = heap.size();
    while (true) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int max_i = -1e5;
        if (left < size && right < size) {
            max_i = heap[left].first > heap[right].first ? left : right;
        } else if (left < size) {
            max_i = left;
        } else if (right < size) {
            max_i = right;
        } else {
            return;
        }

        if (heap[max_i].first > heap[index].first) {
            pair<int, int> tmp = heap[index];
            heap[index] = heap[max_i];
            heap[max_i] = tmp;
        } else {
            return;
        }
        index = max_i;
    }
}

void addele(deque<pair<int, int>>& heap) {
    int index = heap.size() - 1;
    while (true) {
        int father = index & 1 ? (index - 1) / 2 : (index - 2) / 2;

        if (father >= 0 && heap[father].first < heap[index].first) {
            pair<int, int> tmp = heap[index];
            heap[index] = heap[father];
            heap[father] = tmp;
        } else { return; }

        index = father;
    }
}

// 最基础的堆写法
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     deque<pair<int, int>> heap;

//     for (int i = 0; i < k; i++) {
//         heap.push_back({nums[i], i});
//         addele(heap);
//     }

//     res.push_back(heap[0].first);
//     for (int i = k; i < nums.size(); i++) {
//         if (heap[0].second < i - k + 1) {
//             heap[0] = {nums[i], i};
//             heapify(heap);
//             while (heap[0].second < i - k + 1) {
//                 heap[0] = heap[heap.size() - 1];
//                 heap.pop_back();
//                 heapify(heap);
//             }
//         } else {
//             if (heap[0].first < nums[i]) {
//                 heap[0] = {nums[i], i};
//             } else {
//                 heap.push_back({nums[i], i});
//                 addele(heap);
//             }
//         }
//         res.push_back(heap[0].first);
//     }
//     return res;
// }

// 单调队列的做法
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int>> window;
    vector<int> res;
    window.push_back({nums[0], 0});
    for (int i = 1; i < k; i++) {
        auto size = window.size();
        while (window[size - 1].first <= nums[i]) {
            window.pop_back();
            size--;
            if (size == 0) { break; }
        }
        window.push_back({nums[i], i});
    }
    res.push_back(window[0].first);

    for (int i = k; i < nums.size(); i++) {
        auto size = window.size();
        while (size > 0 && window[0].second < i - k + 1) {
            window.pop_front(); 
            --size; 
        }
        while (size > 0 && window[--size].first <= nums[i]) {
            window.pop_back();
        }
        window.push_back({nums[i], i});
        res.push_back(window[0].first);
    }
    return res;
}
int main() {
    return 0;
}