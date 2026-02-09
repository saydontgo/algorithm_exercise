#include <vector>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0;
        int end = m - 1;

        int med1 = nums2[(n - 1) >> 1];
        int med2 = n > 1 ? nums2[((n - 1) >> 1) + 1] : -1;

        while (start <= end) {
            int mid1 = (start + end) >> 1;
            int mid2 = ((m + n + 1) >> 1) - mid1 - 1;
            int nums1_1 = nums1[mid1];
            int nums1_2 = mid1 == m - 1 ? INT_MAX : nums1[mid1 + 1];
            int nums2_2 = nums2[mid2];
            int nums2_1 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];

            if (nums2_2 >= nums1_1) {
                med1 = max(nums1_1, nums2_1);
                med2 = min(nums1_2, nums2_2);
                start = mid1 + 1;
            } else {
                end = mid1 - 1;
            }
            cout << mid1 << " " << mid2 << endl;
            cout << nums1_1 << " " << nums1_2 << " " << nums2_1 << " " << nums2_2 << endl;
            cout << start << " " << end << endl << endl;
        }
        return (m + n) & 1 ? med1 : (med1 + med2) / 2.;
    }
};