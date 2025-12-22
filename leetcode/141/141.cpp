#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
  auto slow = head;
  auto fast = head;

  while(slow != nullptr && fast != nullptr) {
    fast = fast->next;
    if (fast == nullptr) { return false; }

    fast = fast->next;
    slow = slow->next;
    if (fast == slow) { return true; }
  }
  return false;
}
int main() {
  return 0;
}