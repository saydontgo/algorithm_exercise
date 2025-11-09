#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* merge(ListNode* head, ListNode* tail, int size) {
    if (size == 0) { return nullptr; }
    if (size == 1) {
        head->next = nullptr;
        return head;
    }
    if (size == 2) {
        if (head->val > tail->val) {
            auto tmp = tail->next;
            tail->next = head;
            head->next = nullptr;
            return tail;
        }
        tail->next = nullptr;
        return head;
    }
    auto middle = size / 2;
    auto walk = head;
    for (int i = 1; i < middle; i++) {
        walk = walk->next;
    }
    auto right_start = walk->next;
    auto left = merge(head, walk, middle);
    // print(left);
    auto right = merge(right_start, tail, size - middle);
    // print(right);
    auto new_head = left->val > right->val ? right : left;
    auto prev = new_head;
    if (left->val > right->val) { right = right->next; }
    else { left = left->next; }
    // start merging
    while (left != nullptr && right != nullptr) {
        if (left->val > right->val) {
            prev->next = right;
            right = right->next;
        } else {
            prev->next = left;
            left = left->next;
        }
        prev = prev->next;
    }
    
    if (left != nullptr) {
        prev->next = left;
    } else {
        prev->next = right;
    }
    return new_head;
}
ListNode* sortList(ListNode* head) {
    auto size = 0;
    auto walk = head;
    auto prev = walk;
    while (walk != nullptr) {
        size++;
        prev = walk;
        walk = walk->next;
    }
    return merge(head, prev, size);
}

void test() {
    auto d = ListNode(-1);
    auto c = ListNode(5, &d);
    auto b = ListNode(3, &c);
    auto a = ListNode(4, &b);
    auto head = ListNode(0, &a);

    auto res = &head;
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    res = sortList(&head);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
}
int main() {
    test();
    return 0;
}