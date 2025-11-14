#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int val = l1->val + l2->val;
    l1 = l1->next;
    l2 = l2->next;
    auto res = new ListNode(val % 10);
    auto index = res;
    int jingwei = val / 10;
    while (l1 != nullptr || l2 != nullptr) {
        val = 0;
        if (l1 != nullptr) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            val += l2->val;
            l2 = l2->next;
        }
        // cout << val << endl;
        auto tmp = new ListNode((val % 10 + jingwei) % 10);
        jingwei = (val + jingwei) / 10;
        index->next = tmp;
        index = tmp;
    }
    if (jingwei != 0) {
        auto tmp = new ListNode(jingwei);
        index->next = tmp;
    }
    return res;
}

void test() {
    auto a = ListNode(3);
    auto b = ListNode(4, &a);
    auto c = ListNode(2, &b);

    auto d = ListNode(4);
    auto e = ListNode(6, &d);
    auto f = ListNode(5, &e);

    auto res = addTwoNumbers(&c, &f);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

}
int main() {
    test();
    return 0;
}