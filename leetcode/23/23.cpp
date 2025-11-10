#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto index = new ListNode();
    auto res = index;
    vector<ListNode*> walk;
    for (const auto& head : lists) {
        walk.push_back(head);
    }
    while (true) {
        ListNode* tmp = nullptr;
        int min = 1e5;
        int ii = -1;
        int cnt = 0;
        for (int i = 0; i < walk.size(); i++) {
            if (walk[i] != nullptr && walk[i]->val < min) {
                tmp = walk[i];
                min = tmp->val;
                ii = i;
            }
            if (walk[i] == nullptr) { cnt++; }
        }
        if (cnt == walk.size()) { break; }
        walk[ii] = walk[ii]->next;
        index->next = tmp;
        index = index->next;
    }
    return res->next;
}
int main() {
    return 0;
}