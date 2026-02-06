#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i > -1; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] + 1) * heights[i]);
        }
        return res;
    }
};