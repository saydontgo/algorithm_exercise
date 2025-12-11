#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    auto fast = head;
    auto slow = head;
    stack<int> nodes;
    if (head->next == nullptr) { return true; }
    while (true) {
        fast = fast->next;
        if (fast->next == nullptr) {
            // 偶数
            nodes.push(slow->val);
            slow = slow->next;
            while (slow != nullptr) {
                auto tmp = nodes.top();
                nodes.pop();
                if (tmp != slow->val) { return false; }
                slow = slow->next;
            }
            return true;
        }
        fast = fast->next;
        if (fast->next == nullptr) {
            // 奇数
            nodes.push(slow->val);
            slow = slow->next->next;
            while (slow != nullptr) {
                auto tmp = nodes.top();
                nodes.pop();
                if (tmp != slow->val) { return false; }
                slow = slow->next;
            }
            return true;
        }
        nodes.push(slow->val);
        slow = slow->next;
    }
}
int main() {
    return 0;
}