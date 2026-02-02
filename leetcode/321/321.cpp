#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    deque<int> maxSeq(vector<int>& nums, int ind) {
        deque<int> res;
        if (ind == 0) { return res; }
        for (int i = 0; i < nums.size(); i++) {
            int rest = nums.size() - i;
            while (!res.empty() && rest > ind - res.size()) {
                if (res.back() < nums[i]) {
                    res.pop_back();
                } else {
                    break;
                }
            }
            if (res.size() < ind) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        int start = max(0, k - n);
        int last = min(k, m);
        vector<int> res(k, 0);
        for (int i = start; i <= last; i++) {
            auto left = maxSeq(nums1, i);
            auto right = maxSeq(nums2, k - i);
            vector<int> curMax;
            while (!left.empty() || !right.empty()) {
                if (left.empty()) {
                    curMax.push_back(right.front());
                    right.pop_front();
                } else if (right.empty()) {
                    curMax.push_back(left.front());
                    left.pop_front();
                } else {
                    if (left.front() > right.front()) {
                        curMax.push_back(left.front());
                        left.pop_front();
                    } else if (left.front() < right.front()) {
                        curMax.push_back(right.front());    
                        right.pop_front();
                    } else {
                        int right_size = right.size();
                        int left_size = left.size();
                        int flag = 0;
                        int size = min(left_size, right_size);
                        for (int j = 0; j < size; j++) {
                            if (left[j] > right[j]) { flag = 1; break; }
                            else if (left[j] < right[j]) { flag = -1; break; }
                        }
                        if (flag == -1 || (flag == 0 && left_size <= right_size)) { curMax.push_back(right.front()); right.pop_front(); }
                        else if (flag == 1 || (flag == 0 && left_size > right_size)) { curMax.push_back(left.front()); left.pop_front(); }
                    }
                }
            }
            if (compare(curMax, res) > 0) { res = curMax; }
        }
        return res;
    }
    int compare(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                return 1;
            } else if (a[i] < b[i]) {
                return -1;
            }
        }
        return 0;
    }
};