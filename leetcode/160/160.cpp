#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto up = headA;
    auto down = headB;

    while (true) {
        if (up == nullptr && down == nullptr) {
            return nullptr;
        }

        if (up == down) {
            return up;
        }

        if (up == nullptr) {
            up = headB;
        } else {
            up = up->next;
        }

        if (down == nullptr) {
            down = headA;
        } else {
            down = down->next;
        }
    }
}
int main() {
    return 0;
}