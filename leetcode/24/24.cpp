#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) { return nullptr; }
    ListNode dummy(-1, head);
    ListNode* prev = &dummy;
    ListNode* left = head;
    ListNode* right = head->next;
    while (right != nullptr) {
        auto tmp = right->next;
        prev->next = right;
        right->next = left;
        left->next = tmp;

        if (tmp == nullptr) { break; }
        prev = left;
        left = tmp;
        right = tmp->next;
    }
    return dummy.next;
}
int main() {
    return 0;
}