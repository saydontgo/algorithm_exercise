#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int kthToLast(ListNode* head, int k) {
    auto first_start = head;
    auto second_start = head;

    auto index = 1;

    while (index++ < k) {
        first_start = first_start->next;
    }
    while (first_start->next != nullptr) {
        first_start = first_start->next;
        second_start = second_start->next;
    }

    return second_start->val;
}
int main() {
    return 0;
}