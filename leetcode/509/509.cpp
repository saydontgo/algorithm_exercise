#include <iostream>

using namespace std;

int fib(int n) {
        int f[35];
        f[0] = 0;
        f[1] = 1;
        int index = 2;
        while (index <= n) {
            f[index] = f[index - 1] + f[index - 2];
            index++;
        }
        return f[n];
}

int main() {
    return 0;
}