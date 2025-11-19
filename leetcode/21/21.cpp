#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归版本
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) { return list2; }
    if (list2 == nullptr) { return list1; }
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

// 迭代版本
// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     auto cursor1 = list1;        
//     auto cursor2 = list2;
//     ListNode* res = nullptr;
//     ListNode* cursor_res = nullptr;
//     while (cursor1 != nullptr || cursor2 != nullptr) {
//         int min = 1e4;
//         ListNode* tmp = nullptr;
//         int flag = 1;
//         if (cursor1 != nullptr && cursor1->val < min) {
//             min = cursor1->val;
//             tmp = cursor1;
//         }
//         if (cursor2 != nullptr && cursor2->val < min) {
//             min = cursor2->val;
//             tmp = cursor2;
//             flag = 0;
//         }
//         if (cursor1 == list1 && cursor2 == list2) {
//             res = tmp;
//             cursor_res = tmp;
//         } else {
//             if (flag) {
//                 cursor_res->next = cursor1;
//                 cursor1 = cursor1->next;
//             } else {
//                 cursor_res->next = cursor2;
//                 cursor2 = cursor2->next;
//             }
//         }
//         cursor_res = nullptr;
//     }
//     return res;
// }
int main() {
    return 0;
}