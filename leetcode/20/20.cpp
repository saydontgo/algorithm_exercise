#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> tmp;
    string left = "({["; 
    string right = ")}]";

    for (const auto& c : s) {
        if (left.find(c) != s.npos) {
            tmp.push(c);
        } else {
            if (tmp.empty()) { return false; }
            char match = tmp.top();
            int pos = left.find(match);
            tmp.pop();
            if (right[pos] != c) {
                return false;
            }
        }
    }
    if (!tmp.empty()) { return false; }
    return true;
}

void test() {
    string s = "()";
    cout << isValid(s) << endl;
}
int main() {
    test();
    return 0;
}