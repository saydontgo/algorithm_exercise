#include <iostream>
using namespace std;
// 该题需要在原本的链表上进行反转，而不是重新创建链表！
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代版本 
ListNode* reverseList(ListNode* head) {
    auto prev = head;
    auto index = head;
    while(index != nullptr) {
        auto tmp = index->next;
        if (index != prev) {
            index->next = prev;
        } else {
            index->next = nullptr;
        }
        prev = index;
        index = tmp;
    }
    return prev;
}

// 递归版本
// ListNode* reverseList(ListNode* head) {
//     if (head == nullptr) { return nullptr; }
//     if (head->next == nullptr) { return head; }
//     auto real_head = reverseList(head->next);
//     head->next->next = head;
//     head->next = nullptr;
//     return real_head;
// }

int main() {
    return 0;
}