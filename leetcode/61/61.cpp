#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) { return nullptr; }
    
    ListNode* tail = nullptr;
    auto size = 0;
    auto cursor = head;
    while (cursor != nullptr) {
        size++;
        tail = cursor;
        cursor = cursor->next;
    }

    k %= size;
    cursor = head;
    ListNode* prev = nullptr;
    if (k == 0) { return head; }
    for (int i = 0; i < size - k; i++) {
        prev = cursor;
        cursor = cursor->next;
    }
    prev->next = nullptr;
    tail->next = head;
    return cursor;
}
int main() {
    return 0;
}