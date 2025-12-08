#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) { return nullptr; }
    ListNode dummy(-1, head);
    ListNode* left = &dummy;
    ListNode* right = head;
    int cnt = 0;
    int cur = head->val;
    while (true) {
        if (right == nullptr) {
            if (cnt > 1) { left->next = right; }
            break;
        }
        if (cur == right->val) {
            cnt++;
        } else {
            if (cnt > 1) {
                left->next = right;
            } else {
                left = left->next;
            }
            cnt = 1;
            cur = right->val;
        }
        right = right->next;
    }
    return dummy.next;
}
int main() {
    return 0;
}