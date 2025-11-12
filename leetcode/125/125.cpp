#include <cctype>
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s) {
    string tmp = "";

    for (const auto& c : s) {
        if (isalnum(c)) { tmp += c; }
    }
    s = tmp;
    // cout << s <<endl;
    if (s.empty()) { return true; }

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (tolower(s[left]) == tolower(s[right])) {
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}

void test() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
}
int main() {
    test();
    return 0;
}