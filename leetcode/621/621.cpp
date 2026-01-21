#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26] = {0};

        for (const auto& c : tasks) {
            arr[c - 'A']++;
        }

        sort(arr, arr + 26);
        int sum = 0;
        while (arr[25] > 0) {
            int size;
            for (int i = 0; i < 26; i++) {
                if (arr[i] != 0) {
                    size = 26 - i;
                    break;
                }
            }
            int period = n + 1;
            sum += period;

            int decrease_size = size > n + 1 ? n + 1: size;
            for (int i = 0; i < decrease_size; i++) {
                arr[25 - i]--;
            }
            sort(arr, arr + 26);
            if (arr[25] <= 0 && period > size) {
                sum -= period - size;
            }
        }
        return sum;
    }
};