#include <vector>
using namespace std;

class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        int right = scores.size() - 1;
        int left = 0;
        int first_ind = -1;
        int last_ind = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (scores[mid] > target) {
                right = mid - 1;
            } else if (scores[mid] < target) {
                left = mid + 1;
            } else {
                first_ind = mid;
                right = mid - 1;
            }
        }
        if (first_ind == -1) { return 0; }
        left = 0;
        right = scores.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (scores[mid] > target) {
                right = mid - 1;
            } else if (scores[mid] < target) {
                left = mid + 1;
            } else {
                last_ind = mid;
                left = mid + 1;
            }
        }
        return last_ind - first_ind + 1;
    }
};