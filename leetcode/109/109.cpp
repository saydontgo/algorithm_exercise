struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) { return nullptr; }
        int size = 0;
        auto cur = head;
        auto cur_f = head;

        cur = head;
        ListNode dummy;
        dummy.next = head;
        auto prev = &dummy;
        while (cur_f != nullptr) {
            cur_f = cur_f->next;
            if (cur_f != nullptr) cur_f = cur_f->next;
            else { break; }
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = nullptr;
        auto node = new TreeNode(cur->val);
        node->left = sortedListToBST(dummy.next);
        node->right = sortedListToBST(cur->next);
        return node;
    }
};