#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto fast = head;
    auto slow = head;
    ListNode* prev = nullptr;
    int index = 1;
    while (index++ < n) {
        fast = fast->next;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev == nullptr) {
        return head->next;
    }
    prev->next = slow->next;
    return head;
}
int main() {
    return 0;
}