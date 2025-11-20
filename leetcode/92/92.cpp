#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode virhead(-1, head);
    ListNode* prev = nullptr;
    auto cursor = &virhead;
    int index = 0;

    auto leftend = &virhead;
    auto leftend_1 = head;

    while (true) {
        ListNode* tmp = nullptr;
        if (cursor != nullptr) {
            tmp = cursor->next;
        }
        if (index == left - 1) { leftend = cursor; }
        else if (index == left) { leftend_1 = cursor; }
        else if (index > left && index <= right) {
            cursor->next = prev;
        } else if (index == right + 1) {
            leftend->next = prev;
            leftend_1->next = cursor;
            break;
        }
        index++;
        prev = cursor;
        cursor = tmp;
    }
    return virhead.next;
}
int main() {
    return 0;
}