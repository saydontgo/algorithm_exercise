#include <iostream>
#include <vector>
using namespace std;

void heapify_left_down(vector<int>& left) {
    int cursor = 0;
    auto size = left.size();
    while (cursor < left.size()) {
        int lchild = cursor * 2 + 1;
        int rchild = cursor * 2 + 2;

        int max = -1e6;
        int index = -1;
        if (lchild < size && max < left[lchild]) {
            max = left[lchild];
            index = lchild;
        }
        if (rchild < size && max < left[rchild]) {
            max = left[rchild];
            index = rchild;
        }

        if (max > left[cursor]) {
            auto tmp = left[cursor];
            left[cursor] = left[index];
            left[index] = tmp;
            cursor = index;
        } else {
            return;
        }
    }
}

void heapify_right_down(vector<int>& right) {
    int cursor = 0;
    auto size = right.size();
    while (cursor < size) {
        int lchild = cursor * 2 + 1;
        int rchild = cursor * 2 + 2;

        int min = 1e6;
        int index = -1;
        if (lchild < size && min > right[lchild]) {
            min = right[lchild];
            index = lchild;
        }
        if (rchild < size && min > right[rchild]) {
            min = right[rchild];
            index = rchild;
        }

        if (min < right[cursor]) {
            auto tmp = right[cursor];
            right[cursor] = right[index];
            right[index] = tmp;
            cursor = index;
        } else {
            return;
        }
    }
}

void heapify_left(vector<int>& left) {
    int cursor = left.size() - 1;
    while (cursor > 0) {
        int father = (cursor - (cursor & 1 ? 1 : 2)) / 2;
        if (left[father] < left[cursor]) {
            auto tmp = left[father];
            left[father] = left[cursor];
            left[cursor] = tmp;
            cursor = father;
        } else {
            return;
        }
    }
}

void heapify_right(vector<int>& right) {
    int cursor = right.size() - 1;
    while (cursor > 0) {
        int father = (cursor - (cursor & 1 ? 1 : 2)) / 2;
        if (right[father] > right[cursor]) {
            auto tmp = right[father];
            right[father] = right[cursor];
            right[cursor] = tmp;
            cursor = father;
        } else {
            return;
        }
    }
}

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left_.size() == right_.size()) {
            if (left_.empty()) {
                left_.push_back(num);
                return;
            }
            if (left_[0] >= num) {
                left_.push_back(num);
                heapify_left(left_);
            } else {
                right_.push_back(num);
                heapify_right(right_);
            }
        } else if (left_.size() > right_.size()) {
            if (left_[0] < num) {
                right_.push_back(num);
                heapify_right(right_);
            } else {
                right_.push_back(left_[0]);
                heapify_right(right_);
                left_[0] = num;
                heapify_left_down(left_);
            }
        } else {
            if (num < right_[0]) {
                left_.push_back(num);
                heapify_left(left_);
            } else {
                left_.push_back(right_[0]);
                heapify_left(left_);
                right_[0] = num;
                heapify_right_down(right_);
            }
        }
    }
    
    double findMedian() {
        if (left_.size() == right_.size()) { return (double(left_[0]) + right_[0]) / 2; }
        return left_.size() > right_.size() ? left_[0] : right_[0];
    }
private:
    vector<int> left_;
    vector<int> right_;
};
int main() {
    return 0;
}