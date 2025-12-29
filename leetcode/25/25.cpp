struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reverse_list(ListNode* cur_head) {
        if (cur_head == nullptr) { return; }
        auto prev = cur_head;
        auto tmp = cur_head->next;
        while (tmp != nullptr) {
            cur_head = tmp;
            tmp = cur_head->next;
            cur_head->next = prev;
            prev = cur_head;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;

        auto prev = &dummy;
        auto cur_head = head;
        auto cur_tail = head;
        while (cur_head != nullptr) {
            int flag = 0;
            for (int i = 0; i < k - 1; i++) {
                if (cur_tail == nullptr) {
                    flag = 1;
                    break;
                }
                cur_tail = cur_tail->next;
            }
            if (flag || cur_tail == nullptr) { break; }
            auto next = cur_tail->next;
            cur_tail->next = nullptr;
            reverse_list(cur_head);
            cur_head->next = next;
            prev->next = cur_tail;
            prev = cur_head;
            cur_head = next;
            cur_tail = next;
        }
        return dummy.next;
    }
};