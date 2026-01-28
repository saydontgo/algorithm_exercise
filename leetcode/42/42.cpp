#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int max_index = 0;
        int mheight = -1;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] > mheight) {
                mheight = height[i];
                max_index = i;
            }
        }
        if (mheight == 0) { return 0; }
        int index = 0;
        int res = 0;

        while (height[index] == 0) { index++; }
        int cur_wall = height[index++];
        int cur_wall_ind = index - 1;
        while (index <= max_index) {
            if (height[index] >= cur_wall) {
                cur_wall = height[index++];
                cur_wall_ind = index - 1;
            } else {
                res += cur_wall - height[index];
                index++;
            }
        }
        index = height.size() - 1;
        while (height[index] == 0) { index--; }
        cur_wall = height[index--];
        cur_wall_ind = index + 1;

        while (index >= max_index) {
            if (height[index] >= cur_wall) {
                cur_wall = height[index--];
                cur_wall_ind = index + 1;
            } else {
                res += cur_wall - height[index];
                index--;
            }
        }
        return res;
    }
};