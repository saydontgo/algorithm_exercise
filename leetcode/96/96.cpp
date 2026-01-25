#include <cstring>
class Solution {
public:
    int numTrees(int n) {
        if (n == 1) { return 1; }
        int arr[n + 1];
        memset(arr, 0, (n + 1) * 4);
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                arr[i] += arr[j - 1] * arr[i - j];
            }
        }

        return arr[n];
    }
};