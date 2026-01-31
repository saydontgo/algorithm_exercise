#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur1 = m - 1;
        int cur2 = n - 1;
        int last = m + n - 1;

        while (last > -1) {
            if (cur1 == -1) {
                nums1[last] = nums2[cur2--];
            } else if (cur2 == -1) {
                nums1[last] = nums1[cur1--];
            } else if (nums1[cur1] > nums2[cur2]) {
                nums1[last] = nums1[cur1--];
            } else {
                nums1[last] = nums2[cur2--];
            }
            last--;
        }
    }
};