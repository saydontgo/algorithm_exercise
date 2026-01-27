#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int front = 0;
        int back = nums.size() - 1;

        while (front < nums.size() && nums[front] == 0) {
            front++;
        }

        while (back > -1 && nums[back] == 2) {
            back--;
        }

        int cur = front;
        while (front < back && cur <= back) {
            if (nums[cur] == 0) {
                int tmp = nums[cur];
                nums[cur] = nums[front];
                nums[front] = tmp;
                while (front < back && nums[front] == 0) {
            front++;
        }
            } else if (nums[cur] == 2) {
                int tmp = nums[cur];
                nums[cur] = nums[back];
                nums[back] = tmp;

                while (back > front && nums[back] == 2) {
            back--;
        }
            } else {
                cur++;
            }
            if (cur < front) { cur = front; }
        }
    }
};